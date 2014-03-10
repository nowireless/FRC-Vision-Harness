/*
 * ImageProcessingTest.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: nowireless
 */

#include "ImageProcessingTest.h"

ImageProcessingTest::ImageProcessingTest() {
	// TODO Auto-generated constructor stub
}

ImageProcessingTest::~ImageProcessingTest() {
	// TODO Auto-generated destructor stub
}

void ImageProcessingTest::Run() {
	ImageProcessing *imgProcTest = new ImageProcessing();
	imgProcTest->SetThreshold(83, 153, 67, 255, 138, 198);
	imgProcTest->ProcessFilesystemImage("..\\images\\Center_18ft_On.jpg", "..\\TestImages\\Threshold.bmp", "..\\TestImages\\FilteredImage.bmp");
	delete imgProcTest;
}
