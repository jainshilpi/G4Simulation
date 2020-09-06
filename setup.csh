#!/bin/csh

source /cvmfs/sft.cern.ch/lcg/views/setupViews.csh LCG_96 x86_64-centos7-gcc8-opt
setenv PATH /cvmfs/sft.cern.ch/lcg/contrib/CMake/3.14.2/Linux-x86_64/bin:$PATH
cd /cvmfs/cms.cern.ch/slc7_amd64_gcc820/external/geant4/10.6.2/bin/
source geant4.csh
cd -



setenv G4NEUTRONHPDATA "/tmp/shilpi/datasets/G4NDL4.5"
setenv G4LEDATA "/tmp/shilpi/datasets/G4EMLOW7.7"
setenv G4LEVELGAMMADATA "/tmp/shilpi/datasets/PhotonEvaporation5.3"
setenv G4RADIOACTIVEDATA "/tmp/shilpi/datasets/RadioactiveDecay5.3"
setenv G4PARTICLEXSDATA "/tmp/shilpi/datasets/G4PARTICLEXS1.1"
setenv G4PIIDATA "/tmp/shilpi/datasets/G4PII1.3"
setenv G4REALSURFACEDATA "/tmp/shilpi/datasets/RealSurface2.1.1"
setenv G4SAIDXSDATA "/tmp/shilpi/datasets/G4SAIDDATA2.0"
setenv G4ABLADATA "/tmp/shilpi/datasets/G4ABLA3.1"
setenv G4INCLDATA "/tmp/shilpi/datasets/G4INCL1.0"
setenv G4ENSDFSTATEDATA "/tmp/shilpi/datasets/G4ENSDFSTATE2.2"




echo "Back to main"
echo $G4NEUTRONHPDATA
