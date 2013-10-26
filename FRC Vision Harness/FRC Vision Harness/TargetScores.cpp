#include "TargetScores.h"

TargetScores::TargetScores() {
	 m_highAspect			= 0.0;
	 m_highRectangularity	= 0.0;
	 m_highYEdge			= 0.0;
	 m_highXEdge			= 0.0;

	 m_middleAspect			= 0.0;
	 m_middleRectangularity	= 0.0;
	 m_middleYEdge			= 0.0;
	 m_middleXEdge			= 0.0;

	 m_lowAspect			= 0.0;
	 m_lowRectangularity	= 0.0;
	 m_lowYEdge				= 0.0;
	 m_lowXEdge				= 0.0;

	 m_driverStationLineAspect			= 0.0;
	 m_driverStationLineRectangularity	= 0.0;
	 m_driverStationLineYEdge			= 0.0;
	 m_driverStationLineXEdge			= 0.0;

	 m_pyramidAspect			= 0.0;
	 m_pyramidRectangularity	= 0.0;
	 m_pyramidYEdge				= 0.0;
	 m_pyramidXEdge				= 0.0;

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
	} else if(score == kRectangularity && target == TargetData::k2013High) {
		this->m_highRectangularity = value;
	} else if(score == kRectangularity && target == TargetData::k2013Middle) {
		this->m_middleRectangularity = value;
	} else if(score == kRectangularity && target == TargetData::k2013Low) {
		this->m_lowAspect = value;
	} else if(score == kRectangularity && target == TargetData::k2013Pyramid) {
		this->m_pyramidRectangularity = value;
	} else if(score == kRectangularity && target == TargetData::k2013DriverStationLine) {
		this->m_driverStationLineRectangularity = value;
	} else if(score == kXEdge && target == TargetData::k2013High) {
		this->m_highXEdge = value;
	} else if(score == kXEdge && target == TargetData::k2013Middle) {
		this->m_middleXEdge = value;
	} else if(score == kXEdge && target == TargetData::k2013Low) {
		this->m_lowXEdge = value;
	} else if(score == kXEdge && target == TargetData::k2013Pyramid) {
		this->m_pyramidXEdge = value;
	} else if(score == kXEdge && target == TargetData::k2013DriverStationLine) {
		this->m_driverStationLineAspect = value;
	} else if(score == kYEdge && target == TargetData::k2013High) {
		this->m_highYEdge = value;
	} else if(score == kYEdge && target == TargetData::k2013Middle) {
		this->m_middleYEdge = value;
	} else if(score == kYEdge && target == TargetData::k2013Low) {
		this->m_lowYEdge = value;
	} else if(score == kYEdge && target == TargetData::k2013Pyramid) {
		this->m_pyramidYEdge = value;
	} else if(score == kYEdge && target == TargetData::k2013DriverStationLine) {
		this->m_driverStationLineYEdge = value;
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
	} else if(score == kRectangularity && target == TargetData::k2013High) {
		return this->m_highRectangularity;
	} else if(score == kRectangularity && target == TargetData::k2013Middle) {
		return this->m_middleRectangularity;
	} else if(score == kRectangularity && target == TargetData::k2013Low) {
		return this->m_lowAspect;
	} else if(score == kRectangularity && target == TargetData::k2013Pyramid) {
		return this->m_pyramidRectangularity;
	} else if(score == kRectangularity && target == TargetData::k2013DriverStationLine) {
		return this->m_driverStationLineRectangularity;
	} else if(score == kXEdge && target == TargetData::k2013High) {
		return this->m_highXEdge;
	} else if(score == kXEdge && target == TargetData::k2013Middle) {
		return this->m_middleXEdge;
	} else if(score == kXEdge && target == TargetData::k2013Low) {
		return this->m_lowXEdge;
	} else if(score == kXEdge && target == TargetData::k2013Pyramid) {
		return this->m_pyramidXEdge;
	} else if(score == kXEdge && target == TargetData::k2013DriverStationLine) {
		return this->m_driverStationLineAspect;
	} else if(score == kYEdge && target == TargetData::k2013High) {
		return this->m_highYEdge;
	} else if(score == kYEdge && target == TargetData::k2013Middle) {
		return this->m_middleYEdge;
	} else if(score == kYEdge && target == TargetData::k2013Low) {
		return this->m_lowYEdge;
	} else if(score == kYEdge && target == TargetData::k2013Pyramid) {
		return this->m_pyramidYEdge;
	} else if(score == kYEdge && target == TargetData::k2013DriverStationLine) {
		return this->m_driverStationLineYEdge;
	} 
}

