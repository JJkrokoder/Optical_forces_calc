/**
 * @file test_permittivity_sweep.cpp
 * @brief Test para calcular fuerzas ópticas con diferentes permitividades
 */

#include "../../src/core/optical_forces_calc_DA.h"
#include "../utils/read_scalar_values.h"
#include "../utils/parse_complex_array.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <string>
#include <sstream>

// Función para leer parámetros del archivo de configuración
void readParameters(
    const std::string&,
    int&,
    int&,
    std::string&,
    std::vector<std::complex<double>>&,
    std::vector<std::complex<double>>&
);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <archivo_configuracion>" << std::endl;
        return 1;
    }

    // Variables para almacenar parámetros
    int num_particles, dimensions;
    std::string permittivity_file;
    std::vector<std::complex<double>> dipole_moments;
    std::vector<std::complex<double>> field_gradients;

    try {
        // Leer parámetros del archivo de configuración
        readParameters(
            argv[1],
            num_particles,
            dimensions,
            permittivity_file,
            dipole_moments,
            field_gradients
        );

        // Leer valores de permitividad
        std::vector<double> permittivity_values = readScalarValues(permittivity_file);

        // Archivo para guardar resultados
        std::ofstream outfile("../results/forces_vs_permittivity.txt");
        outfile << "# Permitividad | Partícula | Fx | Fy | Fz\n";

        // Vector para almacenar fuerzas
        std::vector<double> forces(num_particles * dimensions);

        // Calcular fuerzas para cada valor de permitividad
        for (double epsilon_m : permittivity_values) {
            calculateOpticalForces(
                dipole_moments,
                field_gradients,
                epsilon_m,
                num_particles,
                dimensions,
                forces
            );

            // Guardar resultados
            for (int i = 0; i < num_particles; i++) {
                outfile << epsilon_m << "\t" << i << "\t"
                       << forces[i * dimensions] << "\t"
                       << forces[i * dimensions + 1] << "\t"
                       << forces[i * dimensions + 2] << "\n";
            }
            outfile << "\n"; // Separador entre conjuntos de datos
        }

        std::cout << "Cálculo completado. Resultados guardados en forces_vs_permittivity.txt\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

void readParameters(
    const std::string& filename,
    int& num_particles,
    int& dimensions,
    std::string& permittivity_file,
    std::vector<std::complex<double>>& dipole_moments,
    std::vector<std::complex<double>>& field_gradients
) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo de configuración");
    }

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        std::istringstream iss(line);
        std::string parameter;
        iss >> parameter;

        if (parameter == "num_particles") {
            iss >> parameter; // =
            iss >> num_particles;
        }
        else if (parameter == "dimensions") {
            iss >> parameter; // =
            iss >> dimensions;
        }
        else if (parameter == "permittivity_file") {
            iss >> parameter; // =
            iss >> permittivity_file;
            permittivity_file = permittivity_file.substr(1, permittivity_file.length()-2); // Remove quotes
        }
        else if (parameter == "dipole_moments") {
            iss >> parameter; // =
            std::string array_line;
            std::getline(file, array_line);
            while (std::getline(file, line) && line.find("]") == std::string::npos) {
                array_line += line;
            }
            dipole_moments = parseComplexArray(array_line);
        }
        else if (parameter == "field_gradient") {
            iss >> parameter; // =
            std::string array_line;
            std::getline(file, array_line);
            while (std::getline(file, line) && line.find("]") == std::string::npos) {
                array_line += line;
            }
            field_gradients = parseComplexArray(array_line);
        }
    }
}