
R__LOAD_LIBRARY(libIBD)

#include "IType.h"

Int_t test_run()
{
  time_t start;  
  
  time( &start );
  
  cout << "" << endl;
  
  cout << " The macro starts ( contour_plotter.C ) ... " << endl;

  cout << "" << endl;

  IXSection xsec( IType::TODAY );

  Double_t x[421];
  Double_t y0[421];
  
  std::vector<Double_t> xi;
  for ( Int_t i=0; i<421; i++ )
    {
      x[i] = xsec.thr+1.0*i*0.02;
      y0[i] = xsec.kappa*xsec.GetValue( IType::IBD0, x[i] );
      cout << y0[i] << endl;
      
    }
  
  TGraph *gr0 = new TGraph( 421, x, y0 );
  gr0->SetLineColor( kBlack );
  gr0->SetLineWidth( 3.0 );
  gr0->SetMarkerColor( kBlack );
  gr0->SetTitle( "Cross-section models; E_{#nu}  in MeV; #sigma_{IBD}  in cm^{2}" );
  
  gr0->Draw( "AC" );
  gr0->GetXaxis()->SetRangeUser( 0.0, 12.0 );
  gr0->SetMinimum( 0.0 );
  gr0->SetMaximum( 1.1e-41 );
  gr0->Draw( "AC" );
  
  
  cout << " ... the macro ends ! " << endl;
	  
  cout << "" << endl;
  
  time_t end;      
  
  time( &end );
      
  Int_t dura = difftime( end, start );      
   
  Int_t min = dura / 60; Int_t sec = dura % 60;
    
  cout << " ---> "<< Form( "%02d:%02d", min, sec ) << endl;  
    
  cout << "" << endl;

  cout << "" << endl;
    
  return 0;
  
}
