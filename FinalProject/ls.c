#include <stdio.h>
#include <dirent.h>

int main() {
    DIR* dir;
    struct dirent* entry;

    // 현재 디렉토리 열기
    dir = opendir(".");
    if (dir == NULL) {
        printf("디렉토리를 열 수 없습니다.\n");
        return 1;
    }

    // 디렉토리 내용 읽기
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // 디렉토리 닫기
    closedir(dir);

    return 0;
}
