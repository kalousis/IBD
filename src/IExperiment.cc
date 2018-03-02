
#include "IExperiment.h"

using namespace std;

ClassImp( IExperiment )

IExperiment::IExperiment()
{}

IExperiment::~IExperiment()
{}

IExperiment::IExperiment( IType::Experiment exp )
{
  if ( exp==IType::B4 )
    {
      cout << " Load Bougey-4 experiment ! " << endl;
      cout << "" << endl;
            
    }
    
}
