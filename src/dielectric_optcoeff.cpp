#include "dielectric_optcoeff.h"

namespace dioptco{
    
    Permittivity::Permittivity(std::string material){
        this->material = material;
    }

    Permittivity::~Permittivity(){
    }
} // namespace dioptco


