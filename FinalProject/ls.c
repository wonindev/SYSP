#include <stdio.h>
#include <dirent.h>

int main() {
    DIR* dir;
    struct dirent* entry;

    // ���� ���丮 ����
    dir = opendir(".");
    if (dir == NULL) {
        printf("���丮�� �� �� �����ϴ�.\n");
        return 1;
    }

    // ���丮 ���� �б�
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // ���丮 �ݱ�
    closedir(dir);

    return 0;
}
