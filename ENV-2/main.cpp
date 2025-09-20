#include <iostream>
#include <vector>
#include "complex.h"
#include "sort.h"

int main() {
    std::vector<Complex> numbers = {
        Complex(3, 4),
        Complex(1, 1),
        Complex(0, 2),
        Complex(5, -1)
    };

    std::cout << "Sortavorumic araj:\n";
    for (auto& c : numbers) {
        c.print();
        std::cout <<" "<< c.abs() << "\n";
    }

    sortComplex(numbers);

    std::cout << "\nSortavorumic heto:\n";
    for (auto& c : numbers) {
        c.print();
        std::cout <<" "<< c.abs() << "\n";
    }

    return 0;
}
