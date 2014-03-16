//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "VisionSample2014.h"
#include <nivision.h>
#include "../Tests/ImageProcessingTest.h"
#include "../Tests/ParticleScoringTest.h"
#include "../Tests/ParticleIdentificationTest.h"
#include "../Tests/ParticleScoringSageTwoTest.h"
#include "../Tests/ParticleAnalysisTest.h"

#include <Vision/ImageProcessing.h>
#include <Vision/ParticleScoring.h>
#include <Vision/ParticleIdentification.h>
#include <Vision/ParticleAnalysis.h>
#include "VisionUI.h"

int main(int argc, char *argv[]) {
	/*if(argc != 2) {
		printf("Usage: FRCVisionHarness.exe image.jpg\n");
		return -1;
	}*/

	printf("Creating VisionSample2014 instance\n");
	VisionSample2014 *visionSample2014 = NULL;
	visionSample2014 = new VisionSample2014();

	/*//printf("Going to process image [%s]\n", argv[1]);
	visionSample2014->Autonomous("..\\images\\Center18ft_On2.jpg");
	printf("Done\n");
	delete visionSample2014;


	ImageProcessingTest *imgProcTest = new ImageProcessingTest();
	printf("Starting Image Processing Test\n");
	imgProcTest->Run();
	printf("Finished Image Processing Test\n");
	delete imgProcTest;

	ParticleScoringTest *scoringTest = new ParticleScoringTest();
	printf("Starting Particle Scoring Test\n");
	scoringTest->Run();
	printf("Finished Particle Scoring Test\n");
	delete scoringTest;

	ParticleIdentificationTest *particleIDTest = new ParticleIdentificationTest();
	printf("Starting Particle ID test\n");
	particleIDTest->Run();
	printf("Finished Particle ID Test\n");
	delete particleIDTest;
*/
/*	ParticleScoringSageTwoTest *scoringTwoTest = new ParticleScoringSageTwoTest();
	printf("[ParticleScoringStageTwoTest] Starting Test\n");
	scoringTwoTest->Run();
	printf("[ParticleScoringStageTwoTest] Finished Test\n");
	delete scoringTwoTest;
*/



	VisionUI *ui = new VisionUI();


	if(ui->LoadImagePath()) {
		ui->CreateWindow(0);

		ImageProcessing *imgProcTest = new ImageProcessing();
		imgProcTest->SetThreshold(105, 137, 230, 255, 133, 183);
		imgProcTest->ProcessFilesystemImage(ui->GetImagePath(), "..\\TestImages\\Threshold.bmp", "..\\TestImages\\FilteredImage.bmp");

		ui->DisplayImage(imgProcTest->GetFilteredImage(), 0);

		ParticleScoring *scoringTest = new ParticleScoring();
		scoringTest->StageOneScoring(imgProcTest->GetFilteredImage(), imgProcTest->GetParticleReports());

		ParticleIdentification *particleID = new ParticleIdentification();
		particleID->IDParticles(scoringTest->GetParticleStageOneScores());

		scoringTest->StageTwoScoring(
				imgProcTest->GetFilteredImage(),
				imgProcTest->GetParticleReports(),
				particleID->GetVerticalIDReports(),
				particleID->GetHorizontalIDReports()
				);

		ParticleAnalysis *particleAnalysis = new ParticleAnalysis();

		particleAnalysis->DetectHotSide(scoringTest->GetBestStageTwoScore());

		printf("==========================================\n");
		if(particleAnalysis->IsHotTargetVisable()) {
			printf("Hot Target Visible\n");
		} else {
			printf("Hot Target Not visible\n");
		}

		delete particleAnalysis;
		delete particleID;
		delete scoringTest;
		delete imgProcTest;
	}

	delete ui;


	/*ParticleAnalysisTest *particleAnalysisTest = new ParticleAnalysisTest();
	particleAnalysisTest->Run();
	delete particleAnalysisTest;*/
	system("pause");
}

