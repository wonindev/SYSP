#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_LINE_COUNT 10;

void print_help(const char* program_name) {
    printf("How to Use: %s [-n <Num of Line>] [-c <Num of Byte>] [-f] [-q] [-v] [FileName...]\n", program_name);
    printf("  -n <Enter Num of Line>: Specifies the number of lines to output. Default is 10.\n");
    printf("  -c <Enter Num of Byte>: Specifies the number of bytes to output.\n");
    printf("  -q: Do Not show FileName\n");
    printf("  -v: Show FileName\n");
}

void print_file_lines(const char* filename, int line_count, int quiet) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        if (!quiet) {
            fprintf(stderr, "Can not open File %s\n", filename);
        }
        return;
    }

    char buffer[BUFSIZ];
    int line_buffer[line_count];
    int lines_read = 0;
    int lines_printed = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        line_buffer[lines_read % line_count] = lines_read;
        lines_read++;
    }

    int start_line = lines_read >= line_count ? line_buffer[lines_read % line_count] : 0;
    fseek(file, 0, SEEK_SET);

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (lines_printed >= start_line) {
            printf("%s", buffer);
        }
        lines_printed++;
    }

    fclose(file);
}

void print_file_bytes(const char* filename, int byte_count, int quiet) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        if (!quiet) {
            fprintf(stderr, "Can not open File %s\n", filename);
        }
        return;
    }

    char buffer[BUFSIZ];
    int bytes_read = 0;
    int bytes_printed = 0;

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (byte_count > file_size) {
        byte_count = file_size;
    }

    while (bytes_read < file_size && bytes_printed < byte_count) {
        int bytes_to_read = sizeof(buffer);
        if (bytes_read + bytes_to_read > file_size) {
            bytes_to_read = file_size - bytes_read;
        }
        fread(buffer, 1, bytes_to_read, file);

        int bytes_to_print = bytes_to_read;
        if (bytes_printed + bytes_to_print > byte_count) {
            bytes_to_print = byte_count - bytes_printed;
        }
        fwrite(buffer, 1, bytes_to_print, stdout);

        bytes_read += bytes_to_read;
        bytes_printed += bytes_to_print;
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    int line_count = DEFAULT_LINE_COUNT;
    int byte_count = 0;
    int follow = 0;
    int quiet = 0;
    int verbose = 0;
    int opt;

    while ((opt = getopt(argc, argv, "n:c:qvh")) != -1) {
        switch (opt) {
        case 'n':
            line_count = atoi(optarg);
            if (line_count <= 0) {
                fprintf(stderr, "Incorrect Num of Line %s\n", optarg);
                return 1;
            }
            break;
        case 'c':
            byte_count = atoi(optarg);
            line_count = 0;
            if (byte_count <= 0) {
                fprintf(stderr, "Incorrect Num of Byte %s\n", optarg);
                return 1;
            }
            break;
        case 'q':
            quiet = 1;
            break;
        case 'v':
            verbose = 1;
            break;
        case 'h':
            print_help(argv[0]);
            return 0;
        case '?':
            return 1;
        }
    }

    if (byte_count > 0 && line_count > 0) {
        fprintf(stderr, "Options -n and -c cannot be used at the same time.\n");
        return 1;
    }

    if (optind == argc) {
        if (follow) {
            fprintf(stderr, "Need File Name\n");
            return 1;
        }
        if (byte_count > 0) {
            print_file_bytes(NULL, byte_count, quiet);
        }
        else {
            print_file_lines(NULL, line_count, quiet);
        }
    }
    else {
        for (int i = optind; i < argc; i++) {
            if (follow) {
                if (verbose) {
                    printf("==> %s <==\n", argv[i]);
                }
                if (byte_count > 0) {
                    print_file_bytes(argv[i], byte_count, quiet);
                }
                else {
                    print_file_lines(argv[i], line_count, quiet);
                }
            }
            else {
                if (verbose) {
                    printf("==> %s <==\n", argv[i]);
                }
                if (byte_count > 0) {
                    print_file_bytes(argv[i], byte_count, quiet);
                }
                else {
                    print_file_lines(argv[i], line_count, quiet);
                }
            }
        }
    }

    return 0;
}
