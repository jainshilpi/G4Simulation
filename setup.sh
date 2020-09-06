#!/bin/sh

exec bash
source /cvmfs/sft.cern.ch/lcg/views/setupViews.sh LCG_96 x86_64-centos7-gcc8-opt
export PATH=/cvmfs/sft.cern.ch/lcg/contrib/CMake/3.14.2/Linux-x86_64/bin:$PATH
cd /cvmfs/cms.cern.ch/slc7_amd64_gcc820/external/geant4/10.6.2/bin/
source geant4.sh
cd -
#source sourceDatasets.sh

export G4NEUTRONHPDATA="/tmp/shilpi/datasets/G4NDL4.5"
export G4LEDATA="/tmp/shilpi/datasets/G4EMLOW7.7"
export G4LEVELGAMMADATA="/tmp/shilpi/datasets/PhotonEvaporation5.3"
export G4RADIOACTIVEDATA="/tmp/shilpi/datasets/RadioactiveDecay5.3"
export G4PARTICLEXSDATA="/tmp/shilpi/datasets/G4PARTICLEXS1.1"
export G4PIIDATA="/tmp/shilpi/datasets/G4PII1.3"
export G4REALSURFACEDATA="/tmp/shilpi/datasets/RealSurface2.1.1"
export G4SAIDXSDATA="/tmp/shilpi/datasets/G4SAIDDATA2.0"
export G4ABLADATA="/tmp/shilpi/datasets/G4ABLA3.1"
export G4INCLDATA="/tmp/shilpi/datasets/G4INCL1.0"
export G4ENSDFSTATEDATA="/tmp/shilpi/datasets/G4ENSDFSTATE2.2"


echo $G4NEUTRONHPDATA
