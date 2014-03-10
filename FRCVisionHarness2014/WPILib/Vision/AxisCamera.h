/*
 * AxisCamera.h
 *
 *  Created on: Feb 27, 2014
 *      Author: nowireless
 */

#ifndef AXISCAMERA_H_
#define AXISCAMERA_H_

#include <Vision/HSLImage.h>

class AxisCamera {
public:
	AxisCamera();
	virtual ~AxisCamera();
	static AxisCamera& GetInstance(const char *cameraIP = NULL);
	static void DeleteInstance();

	bool IsFreshImage();

	int GetImage(Image *imaqImage);
	int GetImage(ColorImage *image);
	HSLImage *GetImage();
};

#endif /* AXISCAMERA_H_ */
