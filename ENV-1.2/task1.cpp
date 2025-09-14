#include <iostream>
#include <algorithm>

int main(int argc, char* argv[]) {
    int a = std::stoi(argv[1]);
    int b = std::stoi(argv[2]);
    int c = std::stoi(argv[3]);

    int min_val = std::min({a, b, c});
    int max_val = std::max({a, b, c});

    std::cout << "min-" << min_val << ", max-" << max_val << std::endl;
    return 0;
}



