#!/bin/sh

source /cvmfs/sft.cern.ch/lcg/views/setupViews.sh LCG_96 x86_64-centos7-gcc8-opt
export PATH=/cvmfs/sft.cern.ch/lcg/contrib/CMake/3.14.2/Linux-x86_64/bin:$PATH
cd /cvmfs/cms.cern.ch/slc7_amd64_gcc820/external/geant4/10.6.2/bin/
source geant4.sh
cd -
#source sourceDatasets.sh

DATAPATH=/cvmfs/cms.cern.ch/slc7_amd64_gcc820/external/

export G4NEUTRONHPDATA=${DATAPATH}/geant4-G4NEUTRONXS/1.4/data/G4NEUTRONXS1.4/
export G4LEDATA=${DATAPATH}/geant4-G4EMLOW/7.9.1/data/G4EMLOW7.9.1/
export G4LEVELGAMMADATA=${DATAPATH}/geant4-G4PhotonEvaporation/5.5/data/PhotonEvaporation5.5/
export G4RADIOACTIVEDATA=${DATAPATH}/geant4-G4RadioactiveDecay/5.4/data/RadioactiveDecay5.4/
export G4PARTICLEXSDATA=${DATAPATH}/geant4-G4PARTICLEXS/2.1/data/G4PARTICLEXS2.1/
#export G4PIIDATA=${DATAPATH}/
export G4REALSURFACEDATA=${DATAPATH}/geant4-G4RealSurface/2.1.1/data/RealSurface2.1.1/
export G4SAIDXSDATA=${DATAPATH}/geant4-G4SAIDDATA/2.0/data/G4SAIDDATA2.0/
export G4ABLADATA=${DATAPATH}/geant4-G4ABLA/3.1/data/G4ABLA3.1/
export G4INCLDATA=${DATAPATH}/geant4-G4INCL/1.0/data/G4INCL1.0/
export G4ENSDFSTATEDATA=${DATAPATH}/geant4-G4ENSDFSTATE/2.2/data/G4ENSDFSTATE2.2/


echo $G4NEUTRONHPDATA
