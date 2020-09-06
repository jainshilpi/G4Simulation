#!/bin/bash

AREA=$1
wget https://cern.ch/geant4-data/datasets/G4NDL.4.5.tar.gz -P $AREA
wget https://cern.ch/geant4-data/datasets/G4EMLOW.7.7.tar.gz -P $AREA
wget https://cern.ch/geant4-data/datasets/G4PhotonEvaporation.5.3.tar.gz -P $AREA
wget https://cern.ch/geant4-data/datasets/G4RadioactiveDecay.5.3.tar.gz -P $AREA
wget https://cern.ch/geant4-data/datasets/G4PARTICLEXS.1.1.tar.gz -P $AREA
wget https://cern.ch/geant4-data/datasets/G4PII.1.3.tar.gz -P $AREA
wget https://cern.ch/geant4-data/datasets/G4RealSurface.2.1.1.tar.gz -P $AREA
wget https://cern.ch/geant4-data/datasets/G4SAIDDATA.2.0.tar.gz -P $AREA
wget https://cern.ch/geant4-data/datasets/G4ABLA.3.1.tar.gz -P $AREA
wget https://cern.ch/geant4-data/datasets/G4INCL.1.0.tar.gz -P $AREA
wget https://cern.ch/geant4-data/datasets/G4ENSDFSTATE.2.2.tar.gz -P $AREA


cd $AREA
for f in *.tar.gz; do tar -xvf "$f"; done

cd -
