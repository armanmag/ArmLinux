#include <iostream>
#include <fcntl.h> 
#include <unistd.h> 



int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "usage" << argv[0] << "filename\n";
        return 1;
    }

    const char* filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        std::cerr << "error opening file" << filename << "\n";
        return 1;
    }

    const size_t BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
        if (bytesWritten == -1) {
            std::cerr << "error writing" << "\n";
            close(fd);
            return 1;
        }
    }

    if (bytesRead == -1) {
        std::cerr << "error reading" << "\n";
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
