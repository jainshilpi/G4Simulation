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
// $Id: ExN01DetectorConstruction.cc,v 1.9 2006-06-29 17:47:19 gunter Exp $
// GEANT4 tag $Name: geant4-09-04-patch-02 $
//

#include "ExN01DetectorConstruction.hh"
#include "G4SystemOfUnits.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "globals.hh"
#include "ExN01CreateTree.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4NistManager.hh"

ExN01DetectorConstruction* ExN01DetectorConstruction::fInstance = NULL ;

int verbosity = 1;
///SJ
///world
G4double world_hx = 0.3*m;
G4double world_hy = 0.3*m;
G4double world_hz = 2.*m;



ExN01DetectorConstruction::ExN01DetectorConstruction()
 :  worldLog(0), absLog(0), outLog(0),
    worldPhys(0), absPhys(0), outPhys(0)
{


  
  if ( fInstance )
    {
      return;
    }

  this->fInstance = this ;

  sensorWidth     = 10*CLHEP::cm;
  sensorThickness = 300*CLHEP::um;
  //sensorThickness = 200*CLHEP::um;

}

ExN01DetectorConstruction::~ExN01DetectorConstruction()
{
}

G4VPhysicalVolume* ExN01DetectorConstruction::Construct()
{

  //------------------------------------------------------ materials

G4String name, symbol;
G4double z, a, density,fractionmass;
G4int ncomponents, natoms;


//defining O and O2
density = 0.001429*g/cm3;
a = 15.9994*g/mole;
G4Element* elO  = new G4Element(name="Oxygen"  ,symbol="O" , z= 8., a);

//defining Si
density = 2.33*g/cm3;
a = 28.0855*g/mole;
G4Element* elSi  = new G4Element(name="Silicon"  ,symbol="Si" , z= 14., a);
G4Material* matSi = new G4Material(name="Silicon",density,ncomponents=1);
matSi->AddElement(elSi, natoms=1);

//defining N and N2
density = 0.001251*g/cm3;
a = 14.0067*g/mole;
G4Element* elN  = new G4Element(name="Nitrogen"  ,symbol="N" , z= 7., a);

//defining air
density = 0.001275*g/cm3;
G4Material* Air = new G4Material(name="Air",density,ncomponents=2);

Air->AddElement(elN, fractionmass=70.*perCent);
Air->AddElement(elO, fractionmass=30.*perCent);


//defining world environment

G4Box* worldBox = new G4Box("World", 0.5*world_hx, 0.5*world_hy, 0.5*world_hz);
G4LogicalVolume* worldLog = new G4LogicalVolume(worldBox, Air, "World");
G4PVPlacement* worldPhys = new G4PVPlacement(0,G4ThreeVector(),worldLog,"World",0,false,0);
// worldLog->SetVisAttributes (G4VisAttributes::Invisible);


 G4double pos_x =  0.0*CLHEP::m;
 G4double pos_y =  0.0*CLHEP::m;
 G4double pos_z =  0.0 * CLHEP::m;


 ////sensors now - square shaped - place 4 layers of sensor
 G4Box* solid = new G4Box("ECalSensitive", 0.5*sensorWidth, 0.5*sensorWidth, 0.5*sensorThickness);
 G4LogicalVolume *logSens = new G4LogicalVolume(solid, matSi, "ECalSensitive");
 G4ThreeVector trans;
 trans = G4ThreeVector(0,0,0);
 
 new G4PVPlacement(0,trans,logSens,"sensitiveLayer",worldLog,false,0); ///last argument is for the copy number - useful later


 G4VisAttributes* atb = new G4VisAttributes(G4Colour(1.0,1.0,0.5));
 atb->SetForceSolid(true);  
 logSens->SetVisAttributes(atb);
 
 
 
 if(verbosity > 0) std::cout<<"Done defining the geometry "<<std::endl;
 
 
 //------------------------------------------------------------------
 
 return worldPhys;
}

