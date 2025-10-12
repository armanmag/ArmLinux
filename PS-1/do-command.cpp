#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include <chrono>
#include <cerrno>

void do_command(char** argv) {
    auto start = std::chrono::steady_clock::now();

    pid_t pid = fork();

    if (pid < 0) {
        perror("Failed to create process");
        exit(1);
    } else if (pid == 0) {
        execvp(argv[1], argv + 1);

        if (errno == ENOENT) {
            std::cerr << "command not found: " << argv[1] << "\n";
            exit(127);
        } else if (errno == EACCES) {
            std::cerr << " permission denied: " << argv[1] << "\n";
            exit(126);
        } else {
            std::cerr << "failed to execute command: " << argv[1] << "\n";
            exit(1);
        }
    } else {
        int status;
        wait(&status);

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = end - start;

        if (WIFEXITED(status)) {
            int exit_code = WEXITSTATUS(status);
            std::cout << "command finished in " << duration.count()
                      << " seconds (exit code " << exit_code;

            if (exit_code == 127) {
                std::cerr << "The command was not found in path.\n";
            } else if (exit_code == 126) {
                std::cerr << "You don’t have permission to run this command.\n";
            } else if (exit_code != 0) {
                std::cerr << "command exited with a error.\n";
            }
        } else {
            std::cerr << " Command crashed or terminated unexpectedly"
                      << "(took " << duration.count() << " seconds).";
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./do-command <command> [args...]\n";
        exit(1);
    }

    do_command(argv);
    return 0;
}
