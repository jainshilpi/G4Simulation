# Simple G4 simulation  ---> 300um Si layer as the only detector


(1) git clone https://github.com/jainshilpi/G4Simulation.git

(2) cd G4Simulation

(3) /bin/bash

(4) source setup.sh

(5) mkdir build; cd build

(6) cmake ..  

(7) make   ###At this point, the codes are compiled. To run, do:  

(8) ./shower 300 "mu-" 50 2500  ### first argument is is the Si thickness in micro-meters, second is particle type, third is the energy in GeV and fourth is the #events you want to generate

(9) You will see a rootfile with 

(10) NOTE: whnever you make any changes to any of the .cc codes, make is needed to be done. If you add another set of files, remove all the contents of build directory (make sure rootfiles are secured) again do cmake .. followed by make

(11) At the end of the run is a root file with a tree named "tree" in it. 
(12) Following variables: 
      "sensorE": gives thte total energy deposited in tht sensor
      "EnergyInTrans": gives the energy in the transverse ring whose radius is given by "radiusBin"
