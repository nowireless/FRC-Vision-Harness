/*
 * AxisCamera.cpp
 *
 *  Created on: Feb 27, 2014
 *      Author: nowireless
 */

#include <Vision/AxisCamera.h>

AxisCamera::AxisCamera() {
	// TODO Auto-generated constructor stub

}

AxisCamera::~AxisCamera() {
	// TODO Auto-generated destructor stub
}

AxisCamera& AxisCamera::GetInstance(const char *cameraIP) {
	AxisCamera *cam = NULL;
	return *cam;
}
void AxisCamera::DeleteInstance() {

}

bool AxisCamera::IsFreshImage() {
	return false;
}

int AxisCamera::GetImage(Image *imaqImage) {
	return 1;
}
int AxisCamera::GetImage(ColorImage *image) {
	return 1;
}
HSLImage *AxisCamera::GetImage() {
	return NULL;
}
