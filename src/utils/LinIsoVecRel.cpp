#include "LinIsoVecRel.h"

// Implementación de la función plantilla
template <typename T>
std::vector<T> LinIsoVecRel(const std::vector<T>& vec, const T& scalar)
{
    std::vector<T> result(vec.size());

    for (size_t i = 0; i < vec.size(); i++)
    {
        result[i] = scalar * vec[i];
    }

    return result;
}

// Instanciaciones explícitas (opcional, pero recomendable)
template std::vector<double> LinIsoVecRel(const std::vector<double>&, const double&);
template std::vector<std::complex<double>> LinIsoVecRel(const std::vector<std::complex<double>>&, const std::complex<double>&);