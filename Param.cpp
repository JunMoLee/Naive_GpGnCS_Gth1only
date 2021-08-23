/*******************************************************************************
* Copyright (c) 2015-2017
* School of Electrical, Computer and Energy Engineering, Arizona State University
* PI: Prof. Shimeng Yu
* All rights reserved.
*   
* This source code is part of NeuroSim - a device-circuit-algorithm framework to benchmark 
* neuro-inspired architectures with synaptic devices(e.g., SRAM and emerging non-volatile memory). 
* Copyright of the model is maintained by the developers, and the model is distributed under 
* the terms of the Creative Commons Attribution-NonCommercial 4.0 International Public License 
* http://creativecommons.org/licenses/by-nc/4.0/legalcode.
* The source code is free and you can redistribute and/or modify it
* by providing that the following conditions are met:
*   
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer. 
*   
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*   
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* Developer list: 
*   Pai-Yu Chen     Email: pchen72 at asu dot edu 
*                     
*   Xiaochen Peng   Email: xpeng15 at asu dot edu
********************************************************************************/

#include <string>
#include "math.h"
#include "Param.h"

Param::Param() {
	/* MNIST dataset */
	numMnistTrainImages = 60000;// # of training images in MNIST
	numMnistTestImages = 10000;	// # of testing images in MNIST
	const double
        l=30;
	/* Algorithm parameters */
	numTrainImagesPerEpoch = 8000;	// # of training images per epoch
	totalNumEpochs = 125;	// Total number of epochs
	interNumEpochs = 1;		// Internal number of epochs (print out the results every interNumEpochs)
	nInput = 400;     // # of neurons in input layer
	nHide = 100;      // # of neurons in hidden layer
	nOutput = 10;     // # of neurons in output layer
	alpha1 =l/100.0;	// Learning rate for the weights from input to hidden layer
	alpha2 =l/2.0/100.0;	// Learning rate for the weights from hidden to output layer
	const double
	revlr=15;
	ratio = alpha1 / (revlr/100);
	maxWeight = 1;	// Upper bound of weight value
	minWeight = -1;	// Lower bound of weight value
    /*Optimization method 
    Available option include: "SGD", "Momentum", "Adagrad", "RMSprop" and "Adam"*/
    optimization_type = "SGD";
        ReverseUpdate = 1;
	FullRefresh= 0;
	Reference = 0;
	RefPeriod = 100;
	Record = 1;
	RecordPeriod = 200;
	WeightTrack = 1;
	WeightTrackPeriod=200;
	c2cvariation=0;
	LocationTrack=1;
	LocationTrackPeriod=200;
        const double
        cratioo=6;
cratio=cratioo;
	Gth1 = -1;
	Gth2 = 9;

	/* Hardware parameters */
	useHardwareInTrainingFF = true;   // Use hardware in the feed forward part of training or not (true: realistic hardware, false: ideal software)
	useHardwareInTrainingWU = true;   // Use hardware in the weight update part of training or not (true: realistic hardware, false: ideal software)
	useHardwareInTraining = useHardwareInTrainingFF || useHardwareInTrainingWU;    // Use hardware in the training or not
	useHardwareInTestingFF = true;    // Use hardware in the feed forward part of testing or not (true: realistic hardware, false: ideal software)
	numBitInput = 1;       // # of bits of the input data (=1 for black and white data)
	numBitPartialSum = 8;  // # of bits of the digital output (partial weighted sum output)
	pSumMaxHardware = pow(2, numBitPartialSum) - 1;   // Max digital output value of partial weighted sum
	numInputLevel = pow(2, numBitInput);  // # of levels of the input data
	numWeightBit = 6;	// # of weight bits (only for pure algorithm, SRAM and digital RRAM hardware)
	BWthreshold = 0.5;	// The black and white threshold for numBitInput=1
	Hthreshold = 0.5;	// The spiking threshold for the hidden layer (da1 in Train.cpp and Test.cpp)
	numColMuxed = 16;	// How many columns share 1 read circuit (for analog RRAM) or 1 S/A (for digital RRAM)
	numWriteColMuxed = 16;	// How many columns share 1 write column decoder driver (for digital RRAM)
	writeEnergyReport = true;	// Report write energy calculation or not
	NeuroSimDynamicPerformance = true; // Report the dynamic performance (latency and energy) in NeuroSim or not
	relaxArrayCellHeight = 0;	// True: relax the array cell height to standard logic cell height in the synaptic array
	relaxArrayCellWidth = 0;	// True: relax the array cell width to standard logic cell width in the synaptic array
	arrayWireWidth = 100;	// Array wire width (nm)
	processNode = 32;	// Technology node (nm)
	clkFreq = 2e9;		// Clock frequency (Hz)

	RefreshRate = 2;
	const int 
	nur=2;
	newUpdateRate = nur; // rate of new update algorithm implementation (per # of images)
const int
a=0;
	
const int
gths=1;
	
switch(a){
case 0:
param_gp=1;
param_gn=-9;
break;
case 1:
param_gp=2;
param_gn=-9;
break;
case 2:
param_gp=3;
param_gn=-9;
break;
case 3:
param_gp=4;
param_gn=-9;
break;
case 4:
param_gp=5;
param_gn=-9;
break;
case 5:
param_gp=6;
param_gn=-9;
break; }
	
int Gthlist [55][2];
int idx = 0;

 for(int i=10;  i>=0 ; i--){
 	for(int j=0; j<i; j++ ){
		Gthlist[idx][0] = j;
		Gthlist[idx][1] = i;
		idx++;
	}
 }
			
Gth1 = Gthlist[gths][0];
Gth2 = Gthlist[gths][1]; 

	
const double
select=0;
	
double plist [7] ={8, -9, 0.3, 0, 2, 2, 1};
param_gp=plist[0];
param_gn=plist[1];
alpha1=plist[2];
Reference=plist[3];
RefPeriod=100;
newUpdateRate=int(plist[5]);
Gth1  =10-select;
	
alpha2=alpha1/2;	
ratio = alpha1/0.15;

}



/*
const int
select=0;

switch(select){
		
case 0:
		
double plist [7] ={2, -9, 0.1, 0, 2, 2, 1}
param_gp=plist[0];
param_gn=plist[1];
alpha1=plist[2];
Reference=plist[3];
RefPeriod=int(plist[4]);
newUpdateRate=int(plist[5]);
Gth  =plist[6];
	
alpha2=alpha1/2;	
ratio = alpha1/0.15;

break;
		
case 1:
		
double plist [7] ={2, -9, 0.1, 0, 2, 2, 1.2}
param_gp=plist[0];
param_gn=plist[1];
alpha1=plist[2];
Reference=plist[3];
RefPeriod=int(plist[4]);
newUpdateRate=int(plist[5]);
Gth  =plist[6];
	
alpha2=alpha1/2;	
ratio = alpha1/0.15;

break;
		
}
*/
