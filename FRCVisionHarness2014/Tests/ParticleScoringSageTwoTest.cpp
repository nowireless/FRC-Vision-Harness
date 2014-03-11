/*
 * ParticleScoringSageTwoTest.cpp
 *
 *  Created on: Mar 10, 2014
 *      Author: nowireless
 */

#include "ParticleScoringSageTwoTest.h"
#include <Vision/ImageProcessing.h>
#include <Vision/ParticleScoring.h>
#include <Vision/ParticleIdentification.h>

ParticleScoringSageTwoTest::ParticleScoringSageTwoTest() {
	// TODO Auto-generated constructor stub

}

ParticleScoringSageTwoTest::~ParticleScoringSageTwoTest() {
	// TODO Auto-generated destructor stub
}

void ParticleScoringSageTwoTest::Run() {
	ImageProcessing *imgProcTest = new ImageProcessing();
	imgProcTest->SetThreshold(105, 137, 230, 255, 133, 183);
	imgProcTest->ProcessFilesystemImage("..\\images\\Center_18ft_On.jpg", "..\\TestImages\\Threshold.bmp", "..\\TestImages\\FilteredImage.bmp");

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

	delete particleID;
	delete scoringTest;
	delete imgProcTest;
}
