#include <stdio.h>
#include <string.h>
#include <unistd.h>

void reverse_string(char* str) { // ��Ʈ���� ���������ִ� �Լ�
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
    
    while (fgets(input, sizeof(input), stdin) != EOF) { // EOF���� ��� �Է� ����
        
        input[strcspn(input, "\n")] = '\0';  // ������ �־ ��ĭ ������ ��µǱ� ������ ���� ���� ����

        reverse_string(input);
        printf("%s\n", input);
    }
    

    return 0;
}
