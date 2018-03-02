
#include "IXSection.h"

using namespace std;

ClassImp( IXSection )

IXSection::IXSection()
{}

IXSection::~IXSection()
{}

IXSection::IXSection( IType::Experiment exp )
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

  thr = ( pow( myconst.mn+myconst.me, 2.0 )-pow( myconst.mp, 2.0 ) )/( 2.0*myconst.mp );
  
  cout << " Threshold : " << setprecision(8) << thr << " MeV " << endl;
  cout << "" << endl;
  
  D = myconst.mn-myconst.mp;
  M = ( myconst.mn+myconst.mp )/2.0;
  
}

Double_t IXSection::GetValue( IType::Model mod, Double_t Enu )
{
  Double_t result = -999.0;
  
  if ( mod==IType::IBD0 ) result = IBD0( Enu );

  if ( mod==IType::VOGEL99 ) result = VOGEL99( Enu );
  
  //; VOGEL84, VOGEL99, STRUMIA)

  return result;
  
}

Double_t IXSection::IBD0( Double_t Enu )
{
  Double_t result = 0.0;

  if ( Enu>thr )
    {
      Double_t Ee = Enu-D;
      Double_t pe = sqrt( pow( Ee, 2.0 )-pow( myconst.me, 2.0 ) );
      
      result = Ee*pe;

    }
  
  return result;
    
}

Double_t IXSection::VOGEL99( Double_t Enu )
{
  Double_t result = 0.0;

  if ( Enu>thr )
    {
      Double_t Ee0 = Enu-D;
      Double_t pe0 = sqrt( pow( Ee0, 2.0 )-pow( myconst.me, 2.0 ) );
      Double_t ve0 = pe0/Ee0;
      
      Int_t nsteps = ( 2.0 )/( 0.0001*0.8 );
      Double_t redstep = ( 2.0 )/( nsteps*1.0 );
      
      for ( Int_t j=0; j<nsteps; j++ )
	{
	  Double_t costh = ( -1.0+redstep/2.0 )+1.0*j*redstep;
	  
	  Double_t Ee1 = Ee0*( 1.0-Enu/M*( 1.0 - ve0*costh ) ) - ( pow( D, 2.0 )-pow( myconst.me, 2.0 ) )/( 2.0*M );
	  Double_t pe1 = sqrt( pow( Ee1, 2.0 )-pow( myconst.me, 2.0 ) );
	  Double_t ve1 = pe1/Ee1;
	  
	  Double_t Gamma = 0.0;
	  Gamma += 2.0*( 1.0+myconst.mu )*myconst.lambda*( ( 2.0*Ee0+D )*( 1.0-ve0*costh ) - pow( myconst.me, 2.0 )/Ee0 );
	  Gamma += ( 1.0+myconst.lambda2 )*( D*( 1.0+ve0*costh ) + pow( myconst.me, 2.0 )/Ee0 );
	  Gamma += ( 1.0+3.0*myconst.lambda2 )*( ( Ee0+D )*( 1.0-costh/ve0 ) - D );
	  Gamma += ( 1.0-myconst.lambda2 )*( ( Ee0+D )*( 1.0-costh/ve0 ) - D )*ve0*costh;
	  
	  Double_t si = 1.0/2.0*( 1.0+( 1.0-myconst.lambda2 )/( 1.0+3.0*myconst.lambda2 )*ve1*costh )*Ee1*pe1 - 1.0/2.0/( 1.0+3.0*myconst.lambda2 )*( Gamma/M )*Ee0*pe0;
	  
	  result += si*redstep;

	}

    }

  return result;
  
}
