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
// $Id: ExN01PrimaryGeneratorAction.cc,v 1.6 2006-06-29 17:47:23 gunter Exp $
// GEANT4 tag $Name: geant4-09-04-patch-02 $
//

#include "ExN01PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

#include "G4IonTable.hh"
#include "G4Ions.hh"

#include "G4SystemOfUnits.hh"          

#include <iostream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExG4PrimaryGeneratorAction01::ExG4PrimaryGeneratorAction01( std::string part, float gev) : G4VUserPrimaryGeneratorAction(),fParticleGun(0)
{
  G4int nofParticles = 1;
  fParticleGun  = new G4ParticleGun(nofParticles);
  gev_ = gev;
  part_ = part;
  posx = 0*CLHEP::um;
  posy = 0*CLHEP::um;
  posz = -10*CLHEP::cm;

  std::cout<<"Inside Primary generator action"<<std::endl;
  std::cout<<"vertex in mm is ("<<posx<<","<<posy<<","<<posz<<")"<<std::endl;
  std::cout<<"Particle generated is "<<part_<<" with energy"<<gev_<<std::endl;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExG4PrimaryGeneratorAction01::~ExG4PrimaryGeneratorAction01()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExG4PrimaryGeneratorAction01::GeneratePrimaries(G4Event* anEvent)
{
  srand(time(NULL));
  
  const G4String& particleName = part_.c_str();
  
  G4float energy;
  G4ThreeVector position(posx,posy,posz);
  G4ThreeVector momentumDirection(0.,0.,1.);
  
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle(particleName);
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleEnergy(energy = gev_*GeV);
  fParticleGun->SetParticlePosition(position);
  fParticleGun->SetParticleMomentumDirection(momentumDirection);


  //std::cout<<"Particle generated is "<<fParticleGun->GetParticleDefinition()->GetParticleName()<<std::endl;
  // this function is called at the begining of event
  fParticleGun->GeneratePrimaryVertex(anEvent);
  

  //std::cout<<"beam energy (GeV) is  "<<gev_<<std::endl;
  //std::cout<<"Done with Primary generator action"<<std::endl;
}


