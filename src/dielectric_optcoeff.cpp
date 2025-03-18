#include "dielectric_optcoeff.h"

namespace dioptco{
    
    Permittivity::Permittivity(std::string material){
        this->material = material;
    }

    Permittivity::~Permittivity(){
    }

    std::complex<double> Permittivity::getPermittivity(double wavelength){
        
        if (this->material == "gold"){
            double epsilon_b = 9;
            double h = 6.62607015;
            double c = 2.99792458;
            double e = 1.602176634;
            double E = h*c/(wavelength*e)*100;
            double Ep = 9;
            double Et = 0.05;

            return epsilon_b - (Ep * Ep / (E * E - 1j* E * Et));
        }
        else if (this->material == "silver"){
            return 2.0;
        }
        else{
            return 3.0;
        }
    }

} // namespace dioptco


