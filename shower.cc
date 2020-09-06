//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: exampleN01.cc,v 1.6 2006-06-29 17:47:10 gunter Exp $
// GEANT4 tag $Name: geant4-09-04-patch-02 $
//
// 
// --------------------------------------------------------------
//      GEANT 4 - exampleN01
// --------------------------------------------------------------
//#include "G4Track.hh"
#include "ExN01EventAction.hh"
#include "ExN01CreateTree.hh"

#include <string>
#include <vector>
#include <map>
#include "G4RunManager.hh"
#include "G4UImanager.hh"

#include "ExN01DetectorConstruction.hh"
#include "G4VUserPhysicsList.hh"
#include "FTFP_BERT.hh"
#include "ExN01PrimaryGeneratorAction.hh"


#include "ExN01SteppingAction.hh"

#include "G4SystemOfUnits.hh"

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

//#include "G4TrajectoryGenericDrawer.hh"
//#include "UserTrackingAction.hh"


#include "G4Run.hh"
#include "G4RunManager.hh" 
#include "G4UImanager.hh"
#include "G4UIsession.hh"
#include "G4UIterminal.hh"
#include "globals.hh"
#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#include "ExN01VisAction.hh"
#include "B1Run.hh"
#include "B1RunAction.hh"


#endif


using namespace CLHEP;
using namespace std;

int main(int argc,char** argv) 
{
  float energy, stepEnergyTotal;
  TString name_file;
  std::string part;
  
  if ( argc >= 2 )
    {
      TString agrument = (argv[2]);
      name_file = (argv[1]) + agrument + "GeV.root";
      //name_file = "test.root";				
      energy = atof (argv[2]);
      part = argv[1];
    }
  
  else {
    cout<<"please insert the particle name and energy of incoming particle in GeV"<<endl;
    return 0;
  }
  



  cout<<name_file<<endl;
    	
  // Construct the default run manager
  //
  G4RunManager* runManager = new G4RunManager;
  
  // set mandatory initialization classes
  //

  
  G4VUserDetectorConstruction* detector = new ExN01DetectorConstruction();
  runManager->SetUserInitialization(detector);
  //

  //G4VUserPhysicsList* physics = new ExN01PhysicsList;
  G4VUserPhysicsList* physics = new FTFP_BERT;
  runManager->SetUserInitialization(physics);

  cout<<"Defined Physics list"<<endl;
  
  // set mandatory user action class
  
  G4VUserPrimaryGeneratorAction* gen_action = new ExG4PrimaryGeneratorAction01(part, energy);
  runManager->SetUserAction(gen_action);
  //Creating Tree
  TFile *output = new TFile(name_file,"RECREATE");
  CreateTree* mytree = new CreateTree ("tree") ; 
  
  //G4UserEventAction* event_action = new EventAction();
  EventAction* event_action = new EventAction();
  //G4UserEventAction* event_action = new ExN01EventAction();
  runManager->SetUserAction(event_action);
  
  runManager->SetUserAction(new B1RunAction);
  G4UserSteppingAction* stpAct = new SteppingAction(event_action);
  runManager->SetUserAction(stpAct);
  
  
  runManager->Initialize();
  /*
  // Get the pointer to the UI manager and set verbosities
  //
  G4UImanager* UI = G4UImanager::GetUIpointer();
  UI->ApplyCommand("/run/verbose 0");
  UI->ApplyCommand("/event/verbose 0");
  //UI->ApplyCommand("/tracking/verbose 0");
  UI->ApplyCommand("/gun/particle e-");
  //UI->ApplyCommand("/gun/energy 10 GeV");
  //UI->ApplyCommand("");
  */

  
  //G4int numberOfEvent = 2;
  G4int numberOfEvent = 2500;
  cout<<"Particle and beam energy "<<part<<" "<<energy<<endl;
  runManager->BeamOn(numberOfEvent);
  
  cout<<"checkBeamON"<<endl;

  
  mytree->Write(output);
  output->Close();
  
  delete runManager;

  return 0;
}


