// parse_complex_array.h
#ifndef PARSE_COMPLEX_ARRAY_H
#define PARSE_COMPLEX_ARRAY_H

#include <vector>
#include <complex>
#include <string>
#include <sstream>
#include <stdexcept>

/**
 * @brief Parses an array of complex numbers from a text string
 * @param line String containing complex numbers in format (real,imag)
 * @return Vector of complex numbers
 * @throws std::runtime_error if the entry format is not valid
 */
inline std::vector<std::complex<double>> parseComplexArray(const std::string& line) {
    std::vector<std::complex<double>> values;
    std::istringstream iss(line);
    std::string token;
    
    while (iss >> token) {
        if (token[0] == '(' && token[token.length()-1] == ')') {
            token = token.substr(1, token.length()-2);
            std::istringstream complex_iss(token);
            std::string real_str, imag_str;
            std::getline(complex_iss, real_str, ',');
            std::getline(complex_iss, imag_str);
            
            try {
                values.push_back(std::complex<double>(
                    std::stod(real_str),
                    std::stod(imag_str)
                ));
            } catch (const std::exception& e) {
                throw std::runtime_error("Error when parsing complex number: " + token);
            }
        }
    }
    return values;
}

#endif // PARSE_COMPLEX_ARRAY_H