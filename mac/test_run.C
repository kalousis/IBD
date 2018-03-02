
R__LOAD_LIBRARY(libIBD)

#include "IType.h"

Int_t test_run()
{
  time_t start;  
  
  time( &start );
  
  cout << "" << endl;
  
  cout << " The macro starts ( contour_plotter.C ) ... " << endl;

  cout << "" << endl;

  IExperiment b4( IType::B4 );
  IExperiment raa( IType::RAA );
  IExperiment mine( IType::TODAY );
  
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
