
#ifndef IXSECTION_H
#define IXSECTION_H

#include <stdio.h>
#include "iostream"
#include "iomanip"
#include "TObject.h"
#include "TMath.h"
#include "IConstants.h"
#include "IType.h"

class IXSection : public TObject
{
 private:
  
  IConstants myconst;

  
 public:
  
  IXSection();
  
  virtual ~IXSection();

  IXSection( IType::Experiment exp );
  
  Double_t GetValue( IType::Model mod, Double_t Enu );

  Double_t IBD0( Double_t Enu );

  Double_t kappa;
  Double_t kappa2;
  
  Double_t thr;
  
  Double_t D;
  
  ClassDef( IXSection, 1 )
        
};

#endif
