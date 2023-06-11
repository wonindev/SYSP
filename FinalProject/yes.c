#include <stdio.h>
#include <unistd.h>

int main(int ac, char* av[]) {
    int opt;

    while ((opt = getopt(ac, av, "h:")) != -1) { 
        switch (opt) {
        case 'h':
            printf("How to Use: Default - print 'y' , %s [String] - print - 'String' \n", av[0]);
            break;
        default:
            printf("How to Use: Default - print 'y' , %s [String] - print - 'String' \n", av[0]);
            return 1;
        }
    }
    if (ac == 1) { // 인자 카운트가 1이라면 yes 하나만 있다는 소리이니 y를 출력
        while (1) {
            printf("y\n");
        }
    }
    else { // 그렇지 않으면 인자를 반복문을 통해 출력
        while (1) {
            for (int i = 1; i < ac; i++) {
                printf("%s ", av[i]);
            }
            printf("\n");
        }
    }

    return 0;
}