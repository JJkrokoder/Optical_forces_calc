// read_scalar_values.h
#ifndef READ_SCALAR_VALUES_H
#define READ_SCALAR_VALUES_H

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

/**
 * @brief Lee valores de permitividad desde un archivo
 * @param filename Ruta al archivo con los valores de permitividad
 * @return Vector con los valores de permitividad leídos
 * @throws std::runtime_error si no se puede abrir el archivo
 */
inline std::vector<double> readScalarValues(const std::string& filename) {
    std::vector<double> values;
    std::ifstream file(filename);
    std::string line;
    double value;
    int index;

    if (!file.is_open()) {
        throw std::runtime_error("Could not open scalar file");
    }

    // Saltar líneas de comentarios
    while (std::getline(file, line) && line[0] == '#') {}

    // Leer valores
    while (file >> index >> value) {
        values.push_back(value);
    }

    return values;
}

#endif // READ_SCALAR_VALUES_H