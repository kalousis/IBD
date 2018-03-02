
#include "IConstants.h"

using namespace std;

namespace IConstants
{
  Double_t pi = 3.14159265359;
  // Added by hand
  
  Double_t c = 2.99792458e+10;
  // In cm/sec, PDG
  
  Double_t hc = 1.9732698e-11;
  // In MeV cm, PDG
  
  Double_t me = 0.51099895;
  // In MeV/c^2, PDG

  Double_t mp = 938.27208;
  // In MeV/c^2, PDG
  
  Double_t mn = 939.56541;
  // In MeV/c^2, PDG

  Double_t mz = 91187.6;
  // In MeV/cm^2, PDG
  
  Double_t alpha = 7.2973525664e-3;
  // PDG
  
  Double_t GF = 1.166379e-11;
  // In MeV^-2/( \bar(h)c )^3, PDG
    
  Double_t Vud = 0.97425;
  // PDG 2017 excluding measurements from tau_n
  
  
  
  Double_t fR = 1.71517;
  Double_t dfR = 0.00009; 
  // Wilkinson, Nucl. Instrum. Methods A 404, 305 (1998)
  
  Double_t DR = 0.024;
  Double_t dDR = 0.001; 
  // W. J. Marciano and A. Sirlin, Phys. Rev. Lett. 96, 032002
  
  Double_t tau = 880.2;
  Double_t dtau = 1.0; 
  // In sec, PDG 2017
  
  Double_t lambda = 1.2723; // I removed the "-" sign here !
  Double_t dlambda = 0.0023; 
  // PDG 2017
  
}
