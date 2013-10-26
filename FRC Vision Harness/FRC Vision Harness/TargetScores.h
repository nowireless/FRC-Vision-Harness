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
	double m_highRectangularity;
	double m_highYEdge;
	double m_highXEdge;

	double m_middleAspect;
	double m_middleRectangularity;
	double m_middleYEdge;
	double m_middleXEdge;

	double m_lowAspect;
	double m_lowRectangularity;
	double m_lowYEdge;
	double m_lowXEdge;

	double m_driverStationLineAspect;
	double m_driverStationLineRectangularity;
	double m_driverStationLineYEdge;
	double m_driverStationLineXEdge;

	double m_pyramidAspect;
	double m_pyramidRectangularity;
	double m_pyramidYEdge;
	double m_pyramidXEdge;

};
