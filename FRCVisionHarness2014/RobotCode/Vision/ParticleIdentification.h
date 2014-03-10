/*
 * ParticleIdentification.h
 *
 *  Created on: Mar 9, 2014
 *      Author: nowireless
 */

#ifndef PARTICLEIDENTIFICATION_H_
#define PARTICLEIDENTIFICATION_H_

#include <vector>
#include <Vision/VisionDataTypes.h>

using namespace std;
class ParticleIdentification {
private:
	vector<ParticleIDReport> *m_particleIDReports;
	TargetID compareScores(ParticleScoreReport report, int i);
	char* TargetIDToChar(TargetID id);
public:

	ParticleIdentification();
	virtual ~ParticleIdentification();
	void IDParticles(vector<ParticleScoreReport> *scoreReports);
	vector<ParticleIDReport> *GetParticleIDReports();
};

#endif /* PARTICLEIDENTIFICATION_H_ */
