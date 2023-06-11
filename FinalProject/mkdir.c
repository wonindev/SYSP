#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <getopt.h>

int main(int argc, char* argv[]) {
    int opt;
    int mode = 0777; // ����Ʈ�� 777 ����

    while ((opt = getopt(argc, argv, "m:")) != -1) {
        switch (opt) {
        case 'm':
            mode = strtol(optarg, NULL, 8);  // 8���� ���ڿ��� ���ڷ� ��ȯ�ϰ� ����ڰ� ���ϴ� �������� ����
            break;
        default:
            fprintf(stderr, "How to Use: %s [-m mode] directory\n", argv[0]);
            return 1;
        }
    }

    if (optind >= argc) { // optind�� getopt�� ������ ó���� argv�迭�� index�� �ʱⰪ�� 1�� �����Ǿ� ���� �� �� ���ǹ��� ���丮 �̸��� ���ٴ� �Ҹ�
        fprintf(stderr, "Please Enter Directory Name\n");
        return 1;
    }

    char* dirname = argv[optind]; // dirname�� ù��° ���ڸ� ��´�

    if (mkdir(dirname, mode) == -1) { // mkdir�Լ��� �̿��ؼ� ���丮 �̸��� ������ �ο�
        fprintf(stderr, "Error: Fail to Make Directory\n");
        return 1;
    }

    printf("Complete to Make Directory\n");

    return 0;
}
