/*
 * ParticleScoringTest.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: nowireless
 */

#include "ParticleScoringTest.h"
#include <Vision/ImageProcessing.h>
#include <Vision/ParticleScoring.h>

ParticleScoringTest::ParticleScoringTest() {
	// TODO Auto-generated constructor stub

}

ParticleScoringTest::~ParticleScoringTest() {
	// TODO Auto-generated destructor stub
}

void ParticleScoringTest::Run() {
	ImageProcessing *imgProcTest = new ImageProcessing();
	imgProcTest->SetThreshold(105, 137, 230, 255, 133, 183);
	imgProcTest->ProcessFilesystemImage("..\\images\\Center_18ft_On.jpg", "..\\TestImages\\Threshold.bmp", "..\\TestImages\\FilteredImage.bmp");

	ParticleScoring *scoringTest = new ParticleScoring();
	scoringTest->StageOneScoring(imgProcTest->GetFilteredImage(), imgProcTest->GetParticleReports());

	delete scoringTest;
	delete imgProcTest;
}
