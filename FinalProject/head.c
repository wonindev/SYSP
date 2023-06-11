#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_LINE_COUNT 10;

void print_help(const char* program_name) {
    printf("How to Use: %s [-n <Num of Line>] [-c <Num of Byte>] [FileName...]\n", program_name);
    printf("  -n <Enter Num of Line>: Specifies the number of lines to output. Default is 10.\n");
    printf("  -c <Enter Num of Byte>: Specifies the number of bytes to output.\n");
}

void print_file_lines(const char* filename, int line_count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Can not open file: %s\n", filename);
        return;
    }

    char buffer[BUFSIZ];
    int lines_printed = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL && lines_printed < line_count) {
        printf("%s", buffer);
        lines_printed++;
    }

    fclose(file);
}

void print_file_bytes(const char* filename, int byte_count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Can not open file %s\n", filename);
        return;
    }

    char buffer[BUFSIZ];
    int bytes_printed = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL && bytes_printed < byte_count) {
        int len = strlen(buffer);
        if (bytes_printed + len > byte_count) {
            buffer[byte_count - bytes_printed] = '\0';
            len = byte_count - bytes_printed;
        }
        printf("%s", buffer);
        bytes_printed += len;
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    int opt;
    int line_count = DEFAULT_LINE_COUNT;
    int byte_count = 0;

    while ((opt = getopt(argc, argv, "n:c:h")) != -1) {
        switch (opt) {
        case 'n':
            line_count = atoi(optarg);
            if (line_count <= 0) {
                fprintf(stderr, "Incorrect Num of Line\n");
                return 1;
            }
            break;
        case 'c':
            line_count = 0;
            byte_count = atoi(optarg);
            if (byte_count <= 0) {
                fprintf(stderr, "Incorrect Num of Byte.\n");
                return 1;
            }
            break;
        case 'h':
            print_help(argv[0]);
            return 0;
        default:
            fprintf(stderr, "Incorrect Option.\n");
            print_help(argv[0]);
            return 1;
        }
    }

    // -n과 -c 옵션은 동시에 사용할 수 없음
    if (line_count > 0 && byte_count > 0) {
        fprintf(stderr, "Options -n and -c cannot be used at the same time.\n");
        return 1;
    }

    // 파일명이 주어지지 않은 경우 표준 입력에서 읽어옴
    if (optind == argc) {
        char buffer[BUFSIZ];
        int lines_printed = 0;
        int bytes_printed = 0;
        while ((line_count == 0 || lines_printed < line_count) &&
            (byte_count == 0 || bytes_printed < byte_count) &&
            fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (line_count > 0 && lines_printed >= line_count) {
                break;
            }
            if (byte_count > 0 && bytes_printed >= byte_count) {
                break;
            }

            int len = strlen(buffer);
            if (line_count > 0) {
                if (lines_printed + 1 <= line_count) {
                    printf("%s", buffer);
                    lines_printed++;
                }
            }
            else {
                if (bytes_printed + len <= byte_count) {
                    printf("%s", buffer);
                    bytes_printed += len;
                }
                else {
                    buffer[byte_count - bytes_printed] = '\0';
                    printf("%s", buffer);
                    bytes_printed += byte_count - bytes_printed;
                }
            }
        }
    }
    else {
        for (int i = optind; i < argc; i++) {
            if (line_count > 0) {
                print_file_lines(argv[i], line_count);
            }
            else {
                print_file_bytes(argv[i], byte_count);
            }
        }
    }

    return 0;
}
