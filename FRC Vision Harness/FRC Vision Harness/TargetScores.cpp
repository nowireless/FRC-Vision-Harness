#include "TargetScores.h"

TargetScores::TargetScores() {
	 m_highAspect			= 0.0;
	 m_Rectangularity	= 0.0;
	 m_yEdge			= 0.0;
	 m_xEdge			= 0.0;

	 m_middleAspect			= 0.0;

	 m_lowAspect			= 0.0;

	 m_driverStationLineAspect			= 0.0;

	 m_pyramidAspect			= 0.0;
}

TargetScores::~TargetScores() {
}

void TargetScores::SetScore(Score score, TargetData::Target target, double value) {
	if(score == kAspect && target == TargetData::k2013High) {
		this->m_highAspect = value;
	} else if(score == kAspect && target == TargetData::k2013Middle) {
		this->m_middleAspect = value;
	} else if(score == kAspect && target == TargetData::k2013Low) {
		this->m_lowAspect = value;
	} else if(score == kAspect && target == TargetData::k2013Pyramid) {
		this->m_pyramidAspect = value;
	} else if(score == kAspect && target == TargetData::k2013DriverStationLine) {
		this->m_driverStationLineAspect = value;
	} else if(score == kRectangularity) {
		this->m_Rectangularity = value;
	} else if(score == kXEdge) {
		this->m_xEdge = value;
	} else if(score == kYEdge) {
		this->m_yEdge = value;
	} 
}
double TargetScores::GetScore(Score score, TargetData::Target target) {
	if(score == kAspect && target == TargetData::k2013High) {
		return this->m_highAspect;
	} else if(score == kAspect && target == TargetData::k2013Middle) {
		return this->m_middleAspect;
	} else if(score == kAspect && target == TargetData::k2013Low) {
		return this->m_lowAspect;
	} else if(score == kAspect && target == TargetData::k2013Pyramid) {
		return this->m_pyramidAspect;
	} else if(score == kAspect && target == TargetData::k2013DriverStationLine) {
		return this->m_driverStationLineAspect;
	} else if(score == kRectangularity) {
		return this->m_Rectangularity;
	} else if(score == kXEdge) {
		return this->m_xEdge;
	} else if(score == kYEdge) {
		return this->m_yEdge;
	} 
}

