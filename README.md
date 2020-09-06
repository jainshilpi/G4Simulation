# Simple G4 simulation  ---> 300um Si layer as the only detector
https://github.com/jainshilpi/G4Simulation.git
To start setting up the area, first we need to download the G4 dataset files. There is a script getDatasets.sh which you can use. First make sure where you want to download those (may be outside this area)do the following :
mkdir ~<PATH>/datasets  
./getDatasets.sh ~<PATH>/datasets  ### after this you can do ls -ltr ~<PATH>/datasets . You will see various directories.  At this stage make sure you are still inside G4Simulation
Update setup.sh script by updating the DATAPATH variable to whereever your datasets are (i.e. ~<PATH>/datasets )
/bin/bash
source setup.sh
cd build
cmake ..  
make   ###At this point, the codes are compiled. To run, do:  
./shower "mu-" 50   ### first argument is is the particle type and second is the energy in GeV
