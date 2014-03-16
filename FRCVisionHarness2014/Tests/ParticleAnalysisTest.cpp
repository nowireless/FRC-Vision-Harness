/*
 * ParticleAnalysisTest.cpp
 *
 *  Created on: Mar 16, 2014
 *      Author: nowireless
 */

#include "ParticleAnalysisTest.h"
#include <Vision/ImageProcessing.h>
#include <Vision/ParticleScoring.h>
#include <Vision/ParticleIdentification.h>
#include <Vision/ParticleAnalysis.h>

ParticleAnalysisTest::ParticleAnalysisTest() {
	// TODO Auto-generated constructor stub

}

ParticleAnalysisTest::~ParticleAnalysisTest() {
	// TODO Auto-generated destructor stub
}

void ParticleAnalysisTest::Run() {
	ImageProcessing *imgProcTest = new ImageProcessing();
	imgProcTest->SetThreshold(105, 137, 230, 255, 133, 183);
	imgProcTest->ProcessFilesystemImage("..\\images\\Center18ft_On2.jpg", "..\\TestImages\\Threshold.bmp", "..\\TestImages\\FilteredImage.bmp");

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
	}

	delete particleAnalysis;
	delete particleID;
	delete scoringTest;
	delete imgProcTest;
}
