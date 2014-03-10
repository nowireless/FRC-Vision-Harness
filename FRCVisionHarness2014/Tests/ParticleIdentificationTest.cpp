/*
 * ParticleIdentificationTest.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: nowireless
 */

#include "ParticleIdentificationTest.h"
#include <Vision/ImageProcessing.h>
#include <Vision/ParticleScoring.h>
#include <Vision/ParticleIdentification.h>

ParticleIdentificationTest::ParticleIdentificationTest() {
	// TODO Auto-generated constructor stub

}

ParticleIdentificationTest::~ParticleIdentificationTest() {
	// TODO Auto-generated destructor stub
}

void ParticleIdentificationTest::Run() {
	ImageProcessing *imgProcTest = new ImageProcessing();
	imgProcTest->SetThreshold(105, 137, 230, 255, 133, 183);
	imgProcTest->ProcessFilesystemImage("..\\images\\Center_18ft_On.jpg", "..\\TestImages\\Threshold.bmp", "..\\TestImages\\FilteredImage.bmp");

	ParticleScoring *scoringTest = new ParticleScoring();
	scoringTest->StageOneScoring(imgProcTest->GetFilteredImage(), imgProcTest->GetParticleReports());

	printf("[ParticleIdentificationTest] Testing Particle ID\n");
	ParticleIdentification *particleID = new ParticleIdentification();
	particleID->IDParticles(scoringTest->GetParticleScores());

	delete particleID;
	delete scoringTest;
	delete imgProcTest;
}
