#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Argument should be a file path\n";
        exit(1);
    }

    int fd_1 = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd_1 == -1) {
        perror("error opening file");
        exit(1);
    }

    int fd_2 = dup(fd_1);
    if(fd_2 == -1) {
        perror("fup error");
        exit(1);
    }

    const char* first_line = "first line\n";
    ssize_t bytes_written_1 = write(fd_1, first_line, strlen(first_line));
    if(bytes_written_1 == -1) {
        perror("error writing");
        close(fd_1);
        close(fd_2);
        exit(1);
    }

    const char* second_line = "second line\n";
    ssize_t bytes_written_2 = write(fd_2, second_line, strlen(second_line));
    if(bytes_written_2 == -1) {
        perror("error writing");
        close(fd_1);
        close(fd_2);
        exit(1);
    }
    close(fd_1);
    close(fd_2);
    return 0;
}
