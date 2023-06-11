#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <getopt.h>

int main(int argc, char* argv[]) {
    int opt;
    int mode = 0777; // 디폴트는 777 권한

    while ((opt = getopt(argc, argv, "m:")) != -1) {
        switch (opt) {
        case 'm':
            mode = strtol(optarg, NULL, 8);  // 8진수 문자열을 숫자로 변환하고 사용자가 원하는 권한으로 변경
            break;
        default:
            fprintf(stderr, "How to Use: %s [-m mode] directory\n", argv[0]);
            return 1;
        }
    }

    if (optind >= argc) { // optind는 getopt가 다음에 처리할 argv배열의 index로 초기값은 1로 설정되어 있음 즉 이 조건문은 디렉토리 이름이 없다는 소리
        fprintf(stderr, "Please Enter Directory Name\n");
        return 1;
    }

    char* dirname = argv[optind]; // dirname에 첫번째 인자를 담는다

    if (mkdir(dirname, mode) == -1) { // mkdir함수를 이용해서 디렉토리 이름과 권한을 부여
        fprintf(stderr, "Error: Fail to Make Directory\n");
        return 1;
    }

    printf("Complete to Make Directory\n");

    return 0;
}
