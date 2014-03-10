/*
 * ParticleScoring.h
 *
 *  Created on: Mar 9, 2014
 *      Author: nowireless
 */

#ifndef PARTICLESCORING_H_
#define PARTICLESCORING_H_

#include <Vision/BinaryImage.h>
#include "VisionDataTypes.h"

class ParticleScoring {
private:
	vector<ParticleScoreReport> *m_particleScores;
	float scoreRectangularity(ParticleAnalysisReport *report);
	float scoreAspectRatio(BinaryImage *image, ParticleAnalysisReport *report, TargetID target);
	float ratioToScore(float ratio);

public:
	ParticleScoring();
	virtual ~ParticleScoring();
	void StageOneScoring(BinaryImage *image, vector<ParticleAnalysisReport> *reports);
	vector<ParticleScoreReport> *GetParticleScores();
};

#endif /* PARTICLESCORING_H_ */
