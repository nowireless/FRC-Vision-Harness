#pragma once

class TargetData
{
public:
	static enum FRCGame {
		k2010,
		k2011,
		k2012,
		k2013
	};
	static enum Target {
		k2013High,
		k2013Middle,
		k2013Low,
		k2013DriverStationLine,
		k2013Pyramid,
		kNone
	};

	static double getTargetHeight(Target target);
	static double getTargetWidth(Target target);

	//static double getAspectRatio(Target target);
private:
	FRCGame m_year;

	static const int m_2013HighTargetHeight = 0;
	static const int m_2013HighTargetWidth = 0;

	static const int m_2013MiddleTargetHeight = 0;
	static const int m_2013MiddleTargetWidth = 0;
	
	static const int m_2013LowTargetHeight = 0;
	static const int m_2013LowTargetWidth = 0;
	
	static const int m_2013DriverStationLineHeight = 0;
	static const int m_2013DriverStationLineWidth = 0;

	static const int m_2013PyramidHeight = 0;
	static const int m_2013PyramidWidth = 0;
};
