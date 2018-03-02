
#ifndef IEXPERIMENT_H
#define IEXPERIMENT_H

#include "iostream"
#include "TObject.h"
#include "TMath.h"
#include "IType.h"
#include "IConstants.h"

class IExperiment : public TObject
{
 private:
  
  IConstants myconst;

  Double_t kappa;
  Double_t kappa2;
  
  
 public:
  
  IExperiment();
  
  virtual ~IExperiment();

  IExperiment( IType::Experiment exp );
  
  ClassDef( IExperiment, 1 )

    
};

#endif
