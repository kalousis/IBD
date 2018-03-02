
#ifndef IEXPERIMENT_H
#define IEXPERIMENT_H

#include "iostream"
#include "TObject.h"
#include "TMath.h"
#include "IType.h"

class IExperiment : public TObject
{
 private:
  
 public:
  
  IExperiment();
  
  virtual ~IExperiment();

  IExperiment( IType::Experiment exp );
  
  ClassDef( IExperiment, 1 )

    
};

#endif
