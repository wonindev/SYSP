#include <stdio.h>

int main() {
    int input = 0;
    printf("16비트 이하의 16진수입력 : ");
    scanf("%x", &input);
    
    for(int i = 15; i >= 12; i--){
        printf("%d", (input >> i) & 1);
    }
    printf(" : ");
    
    for(int i = 11; i >= 9; i--){
        printf("%d", (input >> i) & 1);
    }
    
    printf(" : ");
    
    for(int i = 8; i >= 0; i--){
        printf("%d", (input >> i) & 1);
    }
}
