# Simple G4 simulation  ---> 300um Si layer as the only detector


(1) git clone https://github.com/jainshilpi/G4Simulation.git

(2) /bin/bash

(3) source setup.sh

(4) cd build

(5) cmake ..  

(6) make   ###At this point, the codes are compiled. To run, do:  

(7) ./shower 300 "mu-" 50 2500  ### first argument is is the Si thickness in micro-meters, second is particle type, third is the energy in GeV and fourth is the #events you want to generate

(8) You will see a rootfile with 

(8) NOTE: whnever you make any changes to any of the .cc codes, make is needed to be done. If you add another set of files, remove all the contents of build directory (make sure rootfiles are secured) again do cmake .. followed by make
