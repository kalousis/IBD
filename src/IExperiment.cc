
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

      myconst.fR = 1.71465;
      myconst.dfR = 0.00015;
      
      myconst.tau = 887.4;
      myconst.dtau = 1.7;
      
      myconst.lambda = 1.266;
      
    }

  else if ( exp==IType::RAA )
    {
      cout << " Load RAA experiment ! " << endl;
      cout << "" << endl;

      myconst.fR = 1.71465;
      myconst.dfR = 0.00015;
      
      myconst.tau = 885.7;
      myconst.dtau = 0.8;

      myconst.lambda = 1.2694;
            
    }

  else if ( exp==IType::TODAY )
    {
      cout << " Load contemporary experiment ! " << endl;
      cout << "" << endl;
            
    }
  
  myconst.lambda2 = pow( myconst.lambda, 2.0 );
  
  kappa = 2.0*pow( myconst.pi, 2.0 )*pow( myconst.hc, 3.0 )/( pow( myconst.me, 5.0 )*myconst.fR*( myconst.c*myconst.tau ) );
  // IBD pre-factor kappa, tau approach
  
  kappa2 = pow( myconst.GF*myconst.hc*myconst.Vud, 2.0 )*( 1.0+myconst.DR )*( 1.0+3.0*pow( myconst.lambda, 2.0 ) )/myconst.pi;
  // IBD pre-factor kappa, Vud approach
  
  cout << " Prefactor kappa ( tau approach ) : " << kappa << endl; //" +/- " << dkappa << " cm^2/MeV^2 " << endl;
  cout << "" << endl;
    
  cout << " Prefactor kappa ( Vud approach ) : " << kappa2 << endl; //" +/- " << dkappa2 << " cm^2/MeV^2 " << endl;
  cout << "" << endl;
  
}
