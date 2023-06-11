#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFSIZE 4096
#define COPYMODE 0644

void oops(char*, char*);

int main(int ac, char* av[]) {
    int opt;

    while ((opt = getopt(ac, av, "h:")) != -1) {
        switch (opt) {
        case 'h':
            printf("How to Use: %s [Src File] [Des File] \n", av[0]);
            break;
        default:
            printf("How to Use: %s [Src File] [Des File] \n", av[0]);
            return 1;
        }
    }

    int in_fd, out_fd, n_chars;
    char  buf[BUFSIZE];

    if (ac != 3) {
        fprintf(stderr, "usage: %s source destination\n", *av);
        exit(1);
    }

    // opens an existing file
    if ((in_fd = open(av[1], O_RDONLY)) == -1)
        oops("Cannot open ", av[1]);

    // creates a new file
    if ((out_fd = creat(av[2], COPYMODE)) == -1)
        oops("Cannot open ", av[2]);

    // copies an existing file to a new file
    while ((n_chars = read(in_fd, buf, BUFSIZE)) > 0)
        if (write(out_fd, buf, n_chars) != n_chars)
            oops("Write error to ", av[2]);

    if (n_chars == -1)
        oops("Read error from ", av[1]);

    if (close(in_fd) == -1 || close(out_fd) == -1)
        oops("Error closing files", "");

    return 0;
}

// prints an error message
void oops(char* s1, char* s2) {
    fprintf(stderr, "Error: %s ", s1);
    perror(s2);
    exit(1);
}