
#ifndef ICONSTANTS_H
#define ICONSTANTS_H

#include "TMath.h"

namespace IConstants
{
  extern Double_t pi;
  // The usual pi of math
  
  extern Double_t c;
  // Speed of ligt 
  
  extern Double_t hc;
  // \bar{h}c 
  
  extern Double_t me;
  // Electron mass 
  
  extern Double_t mp;
  // Proton mass 

  extern Double_t mn;
  // Neutron mass

  extern Double_t mz;
  // Z boson mass
  
  extern Double_t alpha;
  // Fine structure constant
  
  extern Double_t GF;
  // Fermi constant 

  extern Double_t Vud;
  // Cabibbo angle
    
  extern Double_t fR;
  // Phase space factor including the Coulomb, weak magnetism, recoil, and outer radiative corrections
  extern Double_t dfR;
  // Error of fR
  
  extern Double_t DR;
  // Inner radiative corrections
  extern Double_t dDR;
  // Error
    
  Double_t lambda;
  // Ratio of axial-vector to vector n couplings
  Double_t dlambda;
  // Error of lambda
    
};

#endif
