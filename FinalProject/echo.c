#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void echo(const char* text, int interpret_escape) {
    if (interpret_escape) {
        int len = strlen(text);
        char* output = malloc(len * 2 + 1);
        if (output == NULL) {
            fprintf(stderr, "Memory Error\n");
            return;
        }

        int j = 0;
        for (int i = 0; i < len; i++) {
            if (text[i] == '\\') {
                if (text[i + 1] == 'n') {
                    output[j++] = '\n';
                    i++;
                }
                else {
                    output[j++] = text[i];
                }
            }
            else {
                output[j++] = text[i];
            }
        }

        output[j] = '\0';
        printf("%s", output);
        free(output);
    }
    else {
        printf("%s", text);
    }
}

void print_help(const char* program_name) {
    printf("How to Use: %s [-n][-e][-E][String...]\n", program_name);
    printf("  -n: Does not output new line characters.\n");
    printf("  -e: Interpret and output the escape sequence.\n");
    printf("  -E: Outputs the escape sequence as it is without interpreting it\n");
}

int main(int argc, char* argv[]) {
    int interpret_escape = 0;
    int interpret_escape_default = 1;
    int print_newline = 1;
    int opt;

    while ((opt = getopt(argc, argv, "neEh")) != -1) {
        switch (opt) {
        case 'n':
            print_newline = 0;
            break;
        case 'e':
            interpret_escape = 1;
            break;
        case 'E':
            interpret_escape = 0;
            break;
        case 'h':
            print_help(argv[0]);
        case '?':
            return 1;
        }
    }

    if (optind == argc) {
        if (print_newline) {
            printf("\n");
        }
    }
    else {
        for (int i = optind; i < argc; i++) {
            echo(argv[i], interpret_escape);
            if (i < argc - 1) {
                printf(" ");
            }
        }
        if (print_newline) {
            printf("\n");
        }
    }

    return 0;
}
