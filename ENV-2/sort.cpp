#include "sort.h"
#include <algorithm>

void sortComplex(std::vector<Complex>& arr) {
    std::sort(arr.begin(), arr.end(),
              [](const Complex& x, const Complex& y) {
                  return x.abs() < y.abs();
              });
}
