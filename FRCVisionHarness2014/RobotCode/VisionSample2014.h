/*
 * VisionSample2014.h
 *
 *  Created on: Jan 27, 2014
 *      Author: nowireless
 */

#ifndef VISIONSAMPLE2014_H_
#define VISIONSAMPLE2014_H_

#include "WPILib.h"
#include "Vision/RGBImage.h"
#include "Vision/BinaryImage.h"
#include "Math.h"
#include "VisionSample2014.h"
#include <cmath>
class VisionSample2014 {
	struct Scores {
			double rectangularity;
			double aspectRatioVertical;
			double aspectRatioHorizontal;
		};

		struct TargetReport {
			int verticalIndex;
			int horizontalIndex;
			bool Hot;
			double totalScore;
			double leftScore;
			double rightScore;
			double tapeWidthScore;
			double verticalScore;
		};
private:
public:
		VisionSample2014();
		void Autonomous(const char* file);
		void OperatorControl(void);
		double computeDistance (BinaryImage *image, ParticleAnalysisReport *report);
		double scoreAspectRatio(BinaryImage *image, ParticleAnalysisReport *report, bool vertical);
		bool scoreCompare(Scores scores, bool vertical);
		double scoreRectangularity(ParticleAnalysisReport *report);
		double ratioToScore(double ratio);
		bool hotOrNot(TargetReport target);

};



#endif /* VISIONSAMPLE2014_H_ */
