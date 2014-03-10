/*
 * VisionUI.h
 *
 *  Created on: Mar 10, 2014
 *      Author: nowireless
 */

#ifndef VISIONUI_H_
#define VISIONUI_H_

class VisionUI {
private:
	char** imagePath;
	int cancelled;
public:
	VisionUI();
	virtual ~VisionUI();
	void LoadImage();
};

#endif /* VISIONUI_H_ */
