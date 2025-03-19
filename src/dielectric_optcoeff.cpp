#include "dielectric_optcoeff.h"

// Define the imaginary unit
const std::complex<double> i_im(0.0, 1.0);

namespace dioptco{
    
    Permittivity::Permittivity(std::string Material){
        material = Material;
    }

    Permittivity::~Permittivity(){
    }

    std::complex<double> Permittivity::getPermittivity(double wavelength){
        
        if (material == "gold"){
            double epsilon_b = 9;
            double h = 6.62607015;
            double c = 2.99792458;
            double e = 1.602176634;
            double E = h*c/(wavelength*e)*100;
            double Ep = 9;
            double Et = 0.05;

            return epsilon_b - (Ep * Ep / (E * E - i_im* E * Et));
        }
        else if (material == "silver"){
            return 2.0;
        }
        else{
            return 3.0;
        }
    }

} // namespace dioptco


