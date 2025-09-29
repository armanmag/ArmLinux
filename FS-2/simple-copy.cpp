#include <iostream>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "usage" << argv[0] << " <source> <destination>\n";
        return 1;
    }

    const char* source = argv[1];
    const char* destination = argv[2];

    int src = open(source, O_RDONLY);
    if (src == -1) {
        std::cerr << "error opening " << "\n";
        return 1;
    }

    int dest = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) {
        std::cerr << "error opening file" << "\n";
        close(src);
        return 1;
    }

    char buffer[4096];
    ssize_t bytesRead;

    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        ssize_t bytesWritten = write(dest, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            std::cerr << "error\n";
            close(src);
            close(dest);
            return 1;
        }
    }

    if (bytesRead == -1) {
        std::cerr << "error reading" << "\n";
    }

    close(src);
    close(dest);

    return 0;
}
