#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void print_line(const char* line, int line_number, bool show_line_numbers,
    bool show_nonempty_line_numbers, bool show_dollar_at_end) {
    if (show_line_numbers) {
        if (show_nonempty_line_numbers) {
            if (strlen(line) > 1) {
                printf("%6d  ", line_number);
            }
            else {
                printf("       ");
            }
        }
        else {
            printf("%6d  ", line_number);
        }
    }

    printf("%s", line);

    if (show_dollar_at_end && strlen(line) > 0 && line[strlen(line) - 1] != '\n') {
        printf("$");
    }
}

void print_file(const char* filename, bool show_line_numbers, bool show_nonempty_line_numbers,
    bool show_dollar_at_end, bool squeeze_blank, bool show_tabs, bool show_special_chars) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    bool is_previous_blank = false;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (squeeze_blank && line[0] == '\n') {
            if (is_previous_blank) {
                continue;
            }
            is_previous_blank = true;
        }
        else {
            is_previous_blank = false;
        }

        if (show_tabs) {
            int length = strlen(line);
            for (int i = 0; i < length; i++) {
                if (line[i] == '\t') {
                    line[i] = '^';
                }
            }
        }

        if (show_special_chars) {
            int length = strlen(line);
            for (int i = 0; i < length; i++) {
                if (line[i] == '\n') {
                    printf("\\n");
                }
                else if (line[i] == '\t') {
                    printf("\\t");
                }
                else {
                    printf("%c", line[i]);
                }
            }
        }
        else {
            print_line(line, line_number, show_line_numbers, show_nonempty_line_numbers, show_dollar_at_end);
        }

        line_number++;
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    bool show_line_numbers = false;
    bool show_nonempty_line_numbers = false;
    bool show_dollar_at_end = false;
    bool squeeze_blank = false;
    bool show_tabs = false;
    bool show_special_chars = false;

    int opt;
    while ((opt = getopt(argc, argv, "nbsvetC")) != -1) {
        switch (opt) {
        case 'n':
            show_line_numbers = true;
            break;
        case 'b':
            show_nonempty_line_numbers = true;
            break;
        case 's':
            squeeze_blank = true;
            break;
        case 'v':
            show_nonempty_line_numbers = true;
            show_dollar_at_end = true;
            break;
        case 'e':
            show_dollar_at_end = true;
            break;
        case 't':
            show_tabs = true;
            break;
        case 'C':
            show_special_chars = true;
            break;
        default:
            fprintf(stderr, "사용법: %s [-nbsvetC] [파일1] [파일2] ...\n", argv[0]);
            return 1;
        }
    }

    if (optind >= argc) {
        print_file(NULL, show_line_numbers, show_nonempty_line_numbers, show_dollar_at_end,
            squeeze_blank, show_tabs, show_special_chars);
    }
    else {
        for (int i = optind; i < argc; i++) {
            print_file(argv[i], show_line_numbers, show_nonempty_line_numbers, show_dollar_at_end,
                squeeze_blank, show_tabs, show_special_chars);
        }
    }

    return 0;
}
