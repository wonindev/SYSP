#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H"); // ANSI Escape code�� Ŀ���� Ȩ���� �̵� �� ȭ�� �ϴܱ��� ��� ����� �̽������� �ڵ�
}

int main() {
    clear_screen();
    return 0;
}
