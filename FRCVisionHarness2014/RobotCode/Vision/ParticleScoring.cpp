/*
 * ParticleScoring.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: nowireless
 */

#include <Vision/ParticleScoring.h>
#include <Vision/VisionConfig.h>

ParticleScoring::ParticleScoring() {
	// TODO Auto-generated constructor stub
	this->m_particleScores = NULL;
}

ParticleScoring::~ParticleScoring() {
	// TODO Auto-generated destructor stub
	if(this->m_particleScores != NULL) {
		delete m_particleScores;
	}
}

void ParticleScoring::StageOneScoring(BinaryImage *image, vector<ParticleAnalysisReport> *reports) {
	printf("[ParticleScoring] Starting Stage One\n");
	printf("[ParticleScoring] Reports Size %i \n", reports->size());
	if(reports == NULL && reports->size() == 0) {
		return;
	}

	this->m_particleScores = new vector<ParticleScoreReport>;
	for(unsigned int i = 0; (i < SCORE_MAXPARTICLES) && (i < reports->size()); i++) {
		ParticleAnalysisReport *report = &(reports->at(i));
		ParticleScoreReport scores;

		scores.rectangularityScore			= scoreRectangularity(report);
		scores.aspectRatioHorizontalScore	= scoreAspectRatio(image, report, kHorizontal);
		scores.aspectRatioVerticalScore		= scoreAspectRatio(image, report, kVertical);

		printf("[ParticleScoring] Particle:%i Scores- Rect: %f, AspectHorizontal: %f, AspectVertical: %f\n", i, scores.rectangularityScore, scores.aspectRatioHorizontalScore, scores.aspectRatioVerticalScore);

		m_particleScores->push_back(scores);
	}
}

float ParticleScoring::scoreRectangularity(ParticleAnalysisReport *report) {
	if (report->boundingRect.width * report->boundingRect.height != 0) {
		return 100 * report->particleArea / (report->boundingRect.width * report->boundingRect.height);
	} else {
		return 0;
	}
}

float ParticleScoring::scoreAspectRatio(BinaryImage *image, ParticleAnalysisReport *report, TargetID target) {
	double rectLong, rectShort, idealAspectRatio, aspectRatio;
	switch (target) {
		case kVertical:
			idealAspectRatio = (TARGET_VERTICAL_WIDTH / TARGET_VERTICAL_HEIGHT);
			break;
		case kHorizontal:
			idealAspectRatio = (TARGET_HORIZONTAL_WIDTH / TARGET_HORIZONTAL_HEIGHT);
			break;
		default:
			return 0;
			break;
	}

	imaqMeasureParticle(image->GetImaqImage(), report->particleIndex, 0, IMAQ_MT_EQUIVALENT_RECT_LONG_SIDE, &rectLong);
	imaqMeasureParticle(image->GetImaqImage(), report->particleIndex, 0, IMAQ_MT_EQUIVALENT_RECT_SHORT_SIDE, &rectShort);

	//Divide width by height to measure aspect ratio
	if (report->boundingRect.width > report->boundingRect.height) {
		//particle is wider than it is tall, divide long by short
		aspectRatio = ratioToScore(((rectLong / rectShort) / idealAspectRatio));
	} else {
		//particle is taller than it is wide, divide short by long
		aspectRatio = ratioToScore(((rectShort / rectLong) / idealAspectRatio));
	}
	return aspectRatio;		//force to be in range 0-100
}

float ParticleScoring::ratioToScore(float ratio) {
	double min1 = 100*(1.0-fabs(1-ratio));
	double min2 = 100;
	return (max(0.0, min(min1, min2)));
}

vector<ParticleScoreReport> *ParticleScoring::GetParticleScores() {
	return this->m_particleScores;
}
