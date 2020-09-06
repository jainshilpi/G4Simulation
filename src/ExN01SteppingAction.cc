/**
* @file   SteppingAction.cc
*
* @date   17 Dec 2009
* @author adotti
*
* @brief  Implements user class SteppingAction.
*/
#include <vector>
#include <map>

#include "ExN01CreateTree.hh"
//#include "LinkDef.h"
#include "ExN01SteppingAction.hh"
#include "ExN01EventAction.hh"
#include "G4Step.hh"
#include "G4VTouchable.hh"
#include "G4SteppingManager.hh"
#include "G4UnitsTable.hh"
//#include "G4Electron.hh"
#include "G4RunManager.hh"
//#include "G4Gamma.hh"
#include "ExN01DetectorConstruction.hh"

double casualen (double min, double max)			//random numbers generator
    {
    return (min + (max - min)*rand()/(1.*RAND_MAX));
    }

using namespace std ;

SteppingAction::SteppingAction(EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
fScoringVolume(0)

	{}

SteppingAction::~SteppingAction()
	{

	}	


void SteppingAction::UserSteppingAction(const G4Step* theStep)
{

  //bool verbosity = true;
  bool verbosity = false;

  G4StepPoint* point1 = theStep->GetPreStepPoint();
  G4StepPoint* point2 = theStep->GetPostStepPoint();
  
  G4TouchableHandle touch1 = point1->GetTouchableHandle();
  G4VPhysicalVolume* pre_volume = touch1->GetVolume();
  G4String pre_volName = "" ; if ( pre_volume ) pre_volName = pre_volume -> GetName () ;
  
  //get the name of the volume in which the particles is at the end of the step
  G4TouchableHandle touch2 = point2->GetTouchableHandle();
  G4VPhysicalVolume* post_volume = touch2->GetVolume();
  G4String post_volName = "" ; if ( post_volume ) post_volName = post_volume -> GetName () ;
  //cout<<"prevol:"<<"\t"<<pre_volName<<endl;
  //cout<<"postVol:"<<"\t"<<post_volName<<endl;
  
  if  (pre_volName == "sensitiveLayer"){
    
  
    G4int copyIDinZ = touch1->GetReplicaNumber() - 1;  ///0, 1, 2,3 as the answer
    if(verbosity > 0) std::cout<<""<<std::endl;
    if(verbosity > 0)std::cout<<"Name of preVolume and copy number "<<pre_volName<<" : "<<copyIDinZ<<std::endl;
    
    // get volume of the current step
    G4LogicalVolume* volume 
      = theStep->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();
    //G4String volumename = "";
    //volumename = volume -> GetName();
    //G4cout<<"pre_volume is "<<pre_volName<<endl;
    //G4cout<<"Post_volume is"<<post_volName<<endl;  
    //    cout<<"before"<<endl;
    G4double edepStep;
    //float edepStep;
    

    // collect energy deposited in this step
    edepStep = theStep->GetTotalEnergyDeposit();
    if(verbosity > 0)cout << "edepStep="<<edepStep<<endl;
    fEventAction->AddEdep(edepStep);
    

    if(verbosity>0) cout<<"BEFORE ADDING sensorE["<<copyIDinZ<<"] "<<CreateTree::Instance() -> sensorE<<endl;

    CreateTree::Instance() -> sensorE = CreateTree::Instance() -> sensorE + edepStep;
    
    if(verbosity>0) cout<<"AFTER ADDING sensorE["<<copyIDinZ<<"] "<<CreateTree::Instance() -> sensorE<<endl;


    ////try to calculate hte transverse size of the shower for every Z
    
    double radius = sqrt( pow(point1->GetPosition().x(),2) + pow(point1->GetPosition().y(),2) );
    int radius_bin = int(radius/2*CLHEP::mm);
    
    CreateTree::Instance() -> EnergyInTrans[radius_bin] += edepStep;
    CreateTree::Instance() -> radiusBin[radius_bin] = radius_bin;
    
  }



  


}


