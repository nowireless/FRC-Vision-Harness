/*
 * VisionUI.h
 *
 *  Created on: Mar 10, 2014
 *      Author: nowireless
 */

#ifndef VISIONUI_H_
#define VISIONUI_H_

#include <nivision.h>
#include <Vision/ImageBase.h>

class VisionUI {
private:
	char** imagePath;
	int cancelled;
public:
	VisionUI();
	virtual ~VisionUI();
	void LoadImage();

	bool LoadImagePath();
	char* GetImagePath();
	void CreateWindow(int window);
	void DisplayImage(ImageBase *image, int window);
	void CleanUp();
};

#endif /* VISIONUI_H_ */
