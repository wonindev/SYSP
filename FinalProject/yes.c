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
    if (ac == 1) {
        while (1) {
            printf("y\n");
        }
    }
    else {
        while (1) {
            for (int i = 1; i < ac; i++) {
                printf("%s ", av[i]);
            }
            printf("\n");
        }
    }

    return 0;
}