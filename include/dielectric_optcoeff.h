#pragma once
#include <string>

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
};

}


