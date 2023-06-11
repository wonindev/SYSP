#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PATH_MAX_LENGTH 4096 // 최대 길이 설정

int main() {
    char path[PATH_MAX_LENGTH];

    if (getcwd(path, sizeof(path)) == NULL) { // 현재 작업경로를 얻는 함수 널 이라면 오류 출력
        fprintf(stderr, "Error: Can not find path\n");
        return 1;
    }

    printf("%s\n", path); // 그렇지 않으면 출력

    return 0;
}
