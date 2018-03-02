
#include "IConstants.h"

ClassImp( IConstants )

IConstants::IConstants()
{
  pi = 3.14159265359;
  // Added by hand
  
  c = 2.99792458e+10;
  // In cm/sec, PDG
  
  hc = 1.9732698e-11;
  // In MeV cm, PDG
  
  me = 0.51099895;
  // In MeV/c^2, PDG

  mp = 938.27208;
  // In MeV/c^2, PDG
  
  mn = 939.56541;
  // In MeV/c^2, PDG

  mu = 2.79284735+1.913043;
  // PDG 
  
  mz = 9.119e+4;
  // In MeV/cm^2, PDG
  
  alpha = 7.29735257e-3;
  // PDG
  
  GF = 1.166379e-11;
  // In MeV^-2/( \bar(h)c )^3, PDG
    
  
  
  Vud = 0.97420;
  dVud = 0.00021;
  // PDG 2017 excluding measurements from tau_n
    
  fR = 1.71517;
  dfR = 0.00009; 
  // Wilkinson, Nucl. Instrum. Methods A 404, 305 (1998)
  
  DR = 0.024;
  dDR = 0.001; 
  // W. J. Marciano and A. Sirlin, Phys. Rev. Lett. 96, 032002
  
  tau = 880.2;
  dtau = 1.0; 
  // In sec, PDG 2017
  
  lambda = 1.2723; // I removed the "-" sign here !
  dlambda = 0.0023; 
  // PDG 2017
  
  lambda2 = pow( lambda, 2.0 );
  
}

IConstants::~IConstants()
{}
