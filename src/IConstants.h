
#ifndef ICONSTANTS_H
#define ICONSTANTS_H

#include "TObject.h"
#include "TMath.h"

class IConstants : public TObject
{
 private:
  
 public:
  
  IConstants();
  
  virtual ~IConstants();
      
  Double_t pi;
  // The usual pi of math
  
  Double_t c;
  // Speed of ligt 
  
  Double_t hc;
  // \bar{h}c 
  
  Double_t me;
  // Electron mass 
  
  Double_t mp;
  // Proton mass 

  Double_t mn;
  // Neutron mass

  Double_t mu;
  // Anomalous nucleon isovector magnetic moment 
  
  Double_t mz;
  // Z boson mass
  
  Double_t alpha;
  // Fine structure constant
  
  Double_t GF;
  // Fermi constant 

  Double_t Vud;
  // Cabibbo angle
  Double_t dVud;
  // Error of dVud
  
  Double_t fR;
  // Phase space factor including the Coulomb, weak magnetism, recoil, and outer radiative corrections
  Double_t dfR;
  // Error of fR
  
  Double_t DR;
  // Inner radiative corrections
  Double_t dDR;
  // Error
  
  Double_t tau;
  // Neutron life-time
  Double_t dtau;
  // Error of tau
  
  Double_t lambda;
  // Ratio of axial-vector to vector n couplings
  Double_t dlambda;
  // Error of lambda

  Double_t lambda2;
  // Square of lambda
  
  ClassDef( IConstants, 1 )

    
};

#endif
