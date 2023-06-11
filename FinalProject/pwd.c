#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PATH_MAX_LENGTH 4096

int main() {
    char path[PATH_MAX_LENGTH];

    if (getcwd(path, sizeof(path)) == NULL) {
        fprintf(stderr, "Error: Can not find path\n");
        return 1;
    }

    printf("%s\n", path);

    return 0;
}
