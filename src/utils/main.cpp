#include <iostream>
#include "LinIsoVecRel.h"

int main() {
    std::vector<double> vec = {1.0, 2.0, 3.0};
    double scalar = 2.0;

    std::vector<double> result = LinIsoVecRel(vec, scalar);

    std::cout << "Resultado: ";
    for (const auto& val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}