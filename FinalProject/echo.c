#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void echo(const char* text, int interpret_escape) {
    if (interpret_escape) { // 이스케이프 문자를 이스케이프 문자로 인식을 해야한다면
        int len = strlen(text);
        char* output = malloc(len * 2 + 1);
        if (output == NULL) {
            fprintf(stderr, "Memory Error\n");
            return;
        }

        int j = 0;
        for (int i = 0; i < len; i++) {
            if (text[i] == '\\') { // 스트링의 해당 자리가 \이고
                if (text[i + 1] == 'n') { // 다음 글자가 n이면
                    output[j++] = '\n'; // \n을 담는다
                    i++; // 다음칸으로 자리 이동
                }
                else if (text[i + 1] == 't') { //위와 같은 메커니즘
                    output[j++] = '\t';
                    i++;
                }
                else { //이스케이프 문이 아니라면 \ 자체를 담는다
                    output[j++] = text[i]; 
                }
            }
            else { // 그렇지 않으면 그냥 문자열을 output에 담는다
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
            interpret_escape = 1; // e옵션은 이스케이프를 그 자체로 인식해야하기 때문에 1이다
            break;
        case 'E':
            interpret_escape = 0; // E옵션은 ""로 묶어서 생각하기 때문에 0이다
            break;
        case 'h':
            print_help(argv[0]);
        case '?':
            return 1;
        }
    }

    if (optind == argc) { // argc가 1이라면 echo할 스트링이 없다는 의미로 \n만 출력하고 종료한다
        if (print_newline) {
            printf("\n");
        }
    }
    else { // 그렇지 않다면 에코함수에 해당 문자열을 전달하고 위의 스위치 문에서 전달받은 이스케이프를 실행해야할지 말아야할지를 파라미터로 넘긴다.
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
