#include <iostream>
#include <fcntl.h>
#include <string>
#include <unistd.h>
#include <iterator>
#include <cstdlib>


void initialize(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Argument should be a file path!\n";
        std::exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        std::exit(EXIT_FAILURE);
    }

    if (dup2(fd, 0) == -1) {
        perror("Dup error");
        close(fd);
        std::exit(EXIT_FAILURE);
    }

    close(fd);
}

int main(int argc, char** argv) {
    initialize(argc, argv);

    std::string input;
    std::cin >> input;
    std::string reversed(input.rbegin(), input.rend());

    std::cout << reversed << std::endl;
    return 0;
}

