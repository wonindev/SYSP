#include <stdio.h>
#include <string.h>
#include <unistd.h>

void reverse_string(char* str) { // 스트링을 반전시켜주는 함수
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main(int ac, char * av[]) {
    int opt;
    while ((opt = getopt(ac, av, "h:")) != -1) {
        switch (opt) {
        case 'h':
            printf("How to Use: %s Please Enter , And Enter the String, ^c is Exit  \n", av[0]);
            return 0;
        default:
            printf("How to Use: %s Please Enter , And Enter the String, ^c is Exit  \n", av[0]);
            return 1;
        }
    }
    char input[100];
    
    while (fgets(input, sizeof(input), stdin) != EOF) { // EOF까지 계속 입력 받음
        
        input[strcspn(input, "\n")] = '\0';  // 개행이 있어서 한칸 밑으로 출력되기 때문에 개행 문자 제거

        reverse_string(input);
        printf("%s\n", input);
    }
    

    return 0;
}
