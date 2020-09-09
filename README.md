# Simple G4 simulation  ---> 300um Si layer as the only detector


(1) git clone https://github.com/jainshilpi/G4Simulation.git

(2) /bin/bash

(3) source setup.sh

(4) cd build

(5) cmake ..  

(6) make   ###At this point, the codes are compiled. To run, do:  

(7) ./shower "mu-" 50   ### first argument is is the particle type and second is the energy in GeV

(8) NOTE: whnever you make any changes to any of the .cc codes, make is needed to be done. If you add another set of files, remove all the contents of build directory (make sure rootfiles are secured) again do cmake .. followed by make
