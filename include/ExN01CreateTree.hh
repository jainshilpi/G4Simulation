#ifndef CreateTree_H
#define CreateTree_H 1

#include <iostream>
#include <vector>
#include <map>

#include "TH2F.h"
#include "TH3F.h"
#include "TFile.h"
#include "TTree.h"




class CreateTree
{
private:
  
  TTree*  ftree ;
  TString fname ;
  
public:
  
  CreateTree (TString name);

  
  ~CreateTree () ;
  
  
  TTree*             GetTree  () const { return ftree ; } ;
  TString            GetName  () const { return fname ; } ;

  int                Fill     () ;
  void               Write    (TFile *) ;
  void               Clear    () ;
  static CreateTree* Instance () { return fInstance ; } ;
  static CreateTree* fInstance ;

  
  int   Event ;

  float sensorE;

  float EnergyInTrans[1000];

  int radiusBin[1000];
} ;

#endif
