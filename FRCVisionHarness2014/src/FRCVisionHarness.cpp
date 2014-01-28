//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "VisionSample2014.h"
#include <nivision.h>

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Usage: FRCVisionHarness.exe image.jpg\n");
		return -1;
	}


	printf("Creating VisionSample2014 instance\n");
	VisionSample2014 *visionSample2014 = NULL;
	visionSample2014 = new VisionSample2014();

	printf("Going to process image [%s]\n", argv[1]);
	visionSample2014->Autonomous(argv[1]);
	printf("Done\n");
	delete visionSample2014;
	system("pause");
}

