#!/bin/sh

source /cvmfs/sft.cern.ch/lcg/views/setupViews.sh LCG_96 x86_64-centos7-gcc8-opt
export PATH=/cvmfs/sft.cern.ch/lcg/contrib/CMake/3.14.2/Linux-x86_64/bin:$PATH
cd /cvmfs/cms.cern.ch/slc7_amd64_gcc820/external/geant4/10.6.2/bin/
source geant4.sh
cd -
#source sourceDatasets.sh

DATAPATH=/tmp/shilpi/datasets/

export G4NEUTRONHPDATA=${DATAPATH}/G4NDL4.5
export G4LEDATA=${DATAPATH}/G4EMLOW7.7
export G4LEVELGAMMADATA=${DATAPATH}/PhotonEvaporation5.3
export G4RADIOACTIVEDATA=${DATAPATH}/RadioactiveDecay5.3
export G4PARTICLEXSDATA=${DATAPATH}/G4PARTICLEXS1.1
export G4PIIDATA=${DATAPATH}/G4PII1.3
export G4REALSURFACEDATA=${DATAPATH}/RealSurface2.1.1
export G4SAIDXSDATA=${DATAPATH}/G4SAIDDATA2.0
export G4ABLADATA=${DATAPATH}/G4ABLA3.1
export G4INCLDATA=${DATAPATH}/G4INCL1.0
export G4ENSDFSTATEDATA=${DATAPATH}/G4ENSDFSTATE2.2


echo $G4NEUTRONHPDATA
