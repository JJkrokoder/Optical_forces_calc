#pragma once
#include <string>
#include <complex>

namespace dioptco{
    
/**
 * @brief This is a class for material dielectric permittivity
 */
class Permittivity {

public:
    
    /**
     * @brief This is a string with the material name
     */
    std::string material;

    /**
     * @brief This is a constructor
     * @param material This is a string with the material name
     */
    Permittivity(std::string material);

    /**
     * @brief This is a destructor
     */
    ~Permittivity();

    /**
        * @brief This is a function that returns the dielectric permittivity of the material
        * @param wavelength This is a double with the wavelength of the light
        * @return double This returns the dielectric permittivity of the material
    */
    std::complex<double> getPermittivity(double wavelength);

}; // class Permittivity

}   // namespace dioptco


