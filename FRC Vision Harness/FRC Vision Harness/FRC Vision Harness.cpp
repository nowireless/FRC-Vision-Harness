// FRC Vision Harness.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VisionSubsystemV2.h"


int _tmain(int argc, char *argv[]) {
	VisionSubsystemV2 *visionSubsystemV2 = new VisionSubsystemV2();
	
	visionSubsystemV2->ProcessImageFromFileSystem("..\\..\\18feet.jpg");
	printf("18Feet.jpg\n");
	printf("High \n\tDistance\t %f\n\tAsimuth \t %f\nMiddle\n \tDistance\t %f\n\tAsimuth \t %f\nSecond Middle\n\tDistance\t %f\n\tAsimuth \t %f",
		visionSubsystemV2->GetHighTargetDistance(),
		visionSubsystemV2->GetHighTargetAzimuth(),
		visionSubsystemV2->GetMiddleTargetDistance(),
		visionSubsystemV2->GetMiddleTargetAzimuth(),
		visionSubsystemV2->GetSecondMiddleTargetDistance(),
		visionSubsystemV2->GetSecondMiddleTargetAzimuth());
	
	
	printf("\n");
	printf("25Feet.jpg\n");
	visionSubsystemV2->ProcessImageFromFileSystem("..\\..\\25feet.jpg");
	printf("High \n\tDistance\t %f\n\tAsimuth \t %f\nMiddle\n \tDistance\t %f\n\tAsimuth \t %f\nSecond Middle\n\tDistance\t %f\n\tAsimuth \t %f",
		visionSubsystemV2->GetHighTargetDistance(),
		visionSubsystemV2->GetHighTargetAzimuth(),
		visionSubsystemV2->GetMiddleTargetDistance(),
		visionSubsystemV2->GetMiddleTargetAzimuth(),
		visionSubsystemV2->GetSecondMiddleTargetDistance(),
		visionSubsystemV2->GetSecondMiddleTargetAzimuth());

	delete visionSubsystemV2;
	return 0;
}

