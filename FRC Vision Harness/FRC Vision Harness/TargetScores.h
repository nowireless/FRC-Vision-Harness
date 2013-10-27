#pragma once
#include "TargetData.h"
class TargetScores
{
public:
	static enum Score {
		kAspect,
		kRectangularity,
		kXEdge,
		kYEdge
	};
	TargetScores(void);
	~TargetScores(void);
	void SetScore(Score score, TargetData::Target target, double value);
	double GetScore(Score score, TargetData::Target target);

private:
	double m_highAspect;
	double m_Rectangularity;
	double m_yEdge;
	double m_xEdge;

	double m_middleAspect;
	
	double m_lowAspect;
	
	double m_driverStationLineAspect;
	
	double m_pyramidAspect;
	
};
