#include <iostream>
#include <fstream>
#include <vector>

#include "dielectric_optcoeff.h"

using namespace dioptco;


// This is a script for an executable that, given a file path, writes a set of permittivity data for a set of wavelengths to a file.
// The file path is given as a command line argument.

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <output file path>" << std::endl;
        return 1;
    }

    std::string output_file_path = argv[1];

    // Initialize a permittivity object for gold.
    Permittivity permittivity("gold");

    // Define the wavelengths for which to calculate the permittivity.
    // The wavelengths are given in nanometers and are obtained from the upper an lower graphing limits and the vector's length
    std::vector<double> wavelengths;
    double lower_limit = 300.0;
    double upper_limit = 800.0;
    size_t num_points = 100;
    for (size_t i = 0; i < num_points; i++) {
        wavelengths.push_back(lower_limit + i * (upper_limit - lower_limit) / (num_points - 1));
    }

    // Calculate the permittivity for each wavelength.
    /*
    std::vector<std::complex<double>> permittivities;
    for (double wavelength : wavelengths) {
        permittivities.push_back(permittivity.getPermittivity(wavelength));
    }
    

    // Write the permittivity data to the output file.
    std::ofstream output_file(output_file_path);
    if (!output_file) {
        std::cerr << "Error: could not open file '" << output_file_path << "' for writing." << std::endl;
        return 1;
    }

    output_file << "# wavelength (um)  real(epsilon)  imag(epsilon)" << std::endl;
    for (size_t i = 0; i < wavelengths.size(); i++) {
        output_file << wavelengths[i] << "  " << std::real(permittivities[i]) << "  " << std::imag(permittivities[i]) << std::endl;
    }
    */

    return 0;
}



