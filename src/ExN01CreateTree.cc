#include "ExN01CreateTree.hh"
#include <algorithm>
#include <vector>

using namespace std ;

CreateTree* CreateTree::fInstance = NULL ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


CreateTree::CreateTree (TString name)
{
  if ( fInstance )
  {
    return ;
  }


  this->fInstance = this ;
  this->fname     = name ;
  
  this->ftree     = new TTree (name,name) ;
  
  this->ftree->SetDirectory(0);

  
  this->GetTree ()->Branch ("Event", &this->Event, "Event/I") ;
  
  this->GetTree ()->Branch ("sensorE", &sensorE, "sensorE/F") ;
  
  this->GetTree ()->Branch ("EnergyInTrans", EnergyInTrans, "EnergyInTrans[200]/F") ;
  this->GetTree ()->Branch ("radiusBin", radiusBin, "radiusBin[200]/I") ;
  
  this->Clear () ;
  cout<<"tree"<<endl;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


CreateTree::~CreateTree ()
{}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int CreateTree::Fill () 
{ 
  return this->GetTree ()->Fill () ; 
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


void CreateTree::Write (TFile * outfile)
{
  outfile->cd () ;
  ftree->Write () ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


void CreateTree::Clear ()
{
  Event	= 0 ;

  sensorE = 0;


  
  for(int jj=0; jj<1000; jj++)
    EnergyInTrans[jj] = 0;


 }
