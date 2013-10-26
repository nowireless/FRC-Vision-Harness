#include "TargetData.h"

double TargetData::getTargetHeight(Target target) {
	if(target == k2013High) {
		return m_2013HighTargetHeight;
	} else if(target == k2013Middle) {
		return m_2013MiddleTargetHeight;
	} else if(target == k2013Low) {
		return m_2013LowTargetHeight;
	} else if(target == k2013Pyramid) {
		return m_2013PyramidHeight;
	} else if(target == k2013DriverStationLine) {
		return m_2013DriverStationLineHeight;
	} else {
		return -1;
	}
}

double TargetData::getTargetWidth(Target target) {
	if(target == k2013High) {
		return m_2013HighTargetWidth;
	} else if(target == k2013Middle) {
		return m_2013MiddleTargetWidth;
	} else if(target == k2013Low) {
		return m_2013LowTargetWidth;
	} else if(target == k2013Pyramid) {
		return m_2013PyramidWidth;
	} else if(target == k2013DriverStationLine) {
		return m_2013DriverStationLineWidth;
	} else {
		return -1;
	}
}