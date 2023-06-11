#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char *av[]) {
    
    if (rmdir(av[1]) == -1) { // 삭제할 디렉토리 인자를 rmdir 함수를 통해 삭제
        fprintf(stderr, "Error:Fail to Delete Directroy\n");
        return 1;
    }

    printf("Complete to Delect Directory\n");

    return 0;
}
