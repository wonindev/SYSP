#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H"); // ANSI Escape code로 커서를 홈으로 이동 후 화면 하단까지 모두 지우는 이스케이프 코드
}

int main() {
    clear_screen();
    return 0;
}
