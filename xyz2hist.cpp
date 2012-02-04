// xyz2hist - Create histograms from data files.
// Matt LeBlanc; leblanc1@uvic.ca

// V0.1 - Outline

//#include "xyz2hist.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
using namespace std;

// ROOT Headers
#include "TF1.h"
#include "TH2.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TApplication.h"

//int main(void)
int main(int argc, char **argv)
{
  float datum = -1;
  vector<float> data;

  // Open the file
  ifstream input("input.xyz");

  // Construct the histogram
  TH1F *histo = new TH1F("Histogram of Data","Title;Data Value;Number of Events",10,1,10);
 
  // Read the data
  if(input.is_open())
    {
      while(input.good())
	{
	input >> datum;
	data.push_back(datum);
      } 
    }
  else
    {
      cout << "NOPE!" << endl;
    }
  
  // Fill the histogram
  
  cout << "Filling histogram with data as-follows:" << endl;

  for(vector<float>::iterator i=data.begin();i!=data.end();i++)
    {
      cout << *i << endl; 
      histo->Fill(*i,1);
    }
  
  cout << "Make sure this is all you want! Is that the last value of your file?" << endl;
  
  // Save histogram as a .root file
  
  cout << "Creating .root file ..." << endl;
  TFile f("histo.root","new");
  histo->Write();
  
  // Display the histogram
  
  cout << "Displaying the histogram:" << endl;

  TApplication theApp("theApp",&argc,argv);
  TCanvas *c1 = new TCanvas("c1","data",800,600);
  histo->Draw();
  c1->Update();
  theApp.Run();
  
  // Close the file
  
  cout << "Closing input file." << endl;
  input.close();

  cout << "Done!" << endl;
  return 0;
}
