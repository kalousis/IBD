
R__LOAD_LIBRARY(libIBD)

#include "IType.h"
#include "IStyle.h"

Int_t test_run()
{
  time_t start;  
  
  time( &start );
  
  cout << "" << endl;
  
  cout << " The macro starts ( contour_plotter.C ) ... " << endl;

  cout << "" << endl;

  
  IStyle::SetDefaultStyle();
  
  IXSection xsec( IType::TODAY );
  
  Double_t x[421];
  Double_t y0[421];
  Double_t y1[421];
  
  for ( Int_t i=0; i<421; i++ )
    {
      x[i] = xsec.thr+1.0*i*0.02;
      y0[i] = xsec.kappa*xsec.GetValue( IType::IBD0, x[i] );
      //cout << setprecision(8) << x[i] << ", " << setprecision(8) << y0[i] << endl;
      y1[i] = xsec.kappa*xsec.GetValue( IType::VOGEL99, x[i] );
      
    }

  TCanvas *c1 = new TCanvas( "c1", "" );
  c1->cd();
  
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
  
  
  TGraph *gr1 = new TGraph( 421, x, y1 );
  gr1->SetLineColor( 29 );
  gr1->SetLineWidth( 3.0 );
  gr1->SetMarkerColor( kRed );
  gr1->Draw( "C, SAME" );

  TLegend *leg_1 = new TLegend( 0.55, 0.61, 0.88, 0.88 );
  leg_1->AddEntry( gr0, "0th order Vogel and Beacom '99", "l" );
  leg_1->AddEntry( gr1, "1st order Vogel and Beacom '99", "l" );
  leg_1->SetFillColor( 0 ); 
  leg_1->Draw();

  
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
