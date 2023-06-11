#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

void print_help(const char* program_name) {
    printf("How to Use: %s [-asnrvmpi]\n", program_name);
    printf("  -a: Print All\n");
    printf("  -s: Print Kernel Name\n");
    printf("  -n: Print Host Name\n");
    printf("  -r: Print Release\n");
    printf("  -v: Print Kernel Version\n");
    printf("  -m: Print Machine Type\n");
    printf("  -i: Print hardware platform\n");
}

int main(int argc, char* argv[]) {
    int opt;
    int show_all = 0;
    int show_sysname = 0;
    int show_nodename = 0;
    int show_release = 0;
    int show_version = 0;
    int show_machine = 0;
    int show_processor = 0;

    while ((opt = getopt(argc, argv, "asnrvmh")) != -1) {
        switch (opt) {
        case 'a':
            show_all = 1;
            break;
        case 's':
            show_sysname = 1;
            break;
        case 'n':
            show_nodename = 1;
            break;
        case 'r':
            show_release = 1;
            break;
        case 'v':
            show_version = 1;
            break;
        case 'm':
            show_machine = 1;
            break;
        case 'h':
            print_help(argv[0]);
            return 0;
        default:
            fprintf(stderr, "Error: If you need help '-h'\n");
            print_help(argv[0]);
            return 1;
        }
    }

    if (!show_all && !show_sysname && !show_nodename && !show_release && !show_version && !show_machine && !show_processor) {
        show_sysname = 1;
    }

    struct utsname system_info;
    if (uname(&system_info) != 0) {
        perror("uname");
        return 1;
    }
    if (show_all || show_sysname) {
        printf("Kernel Name: %s\n", system_info.sysname);
    }
    if (show_all || show_nodename) {
        printf("Host Name: %s\n", system_info.nodename);
    }
    if (show_all || show_release) {
        printf("Kernel Release: %s\n", system_info.release);
    }
    if (show_all || show_version) {
        printf("Kernel Version: %s\n", system_info.version);
    }
    if (show_all || show_machine) {
        printf("HardWare Architecture: %s\n", system_info.machine);
    }
   

    return 0;
}