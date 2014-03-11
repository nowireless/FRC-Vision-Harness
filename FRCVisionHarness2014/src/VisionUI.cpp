/*
 * VisionUI.cpp
 *
 *  Created on: Mar 10, 2014
 *      Author: nowireless
 */

#include "VisionUI.h"
#include <nivision.h>
#include <Vision/ImageBase.h>

#define DISPLAY_WINDOW 0

#include <Vision/ImageProcessing.h>

VisionUI::VisionUI() {
	// TODO Auto-generated constructor stub
	imaqSetWindowThreadPolicy(IMAQ_SEPARATE_THREAD);
	cancelled = 0;
}

VisionUI::~VisionUI() {
	// TODO Auto-generated destructor stub
}

void VisionUI::LoadImage() {
	ImageType imageType;    // Image Type
	    Image* image;           // Image
	imagePath = imaqLoadImagePopup(NULL, "*.*", NULL, "Open Image", FALSE,
			IMAQ_BUTTON_LOAD, 0, 0, 1, 0, &cancelled, NULL);
	if (!cancelled) {
		// Get the type of the image file to create an image of the right type
		//imaqGetFileInfo(imagePath[0], NULL, NULL, NULL, NULL, NULL, &imageType);

		// Create an IMAQ Vision image
		//image = imaqCreateImage(imageType, 7);

		// Read the image from disk
		//imaqReadFile(image, imagePath[0], NULL, NULL);
		printf("Image Path %s\n", imagePath[0]);

		/*ImageProcessing *imgProc = new ImageProcessing();
		imgProc->SetThreshold(83, 153, 67, 255, 138, 198);
		imgProc->ProcessFilesystemImage(imagePath[0],NULL,NULL);
		image = imgProc->GetFilteredImage()->GetImaqImage();
*/
		// Display the image
		imaqMoveWindow(DISPLAY_WINDOW, imaqMakePoint(0, 0));
		imaqSetWindowPalette(DISPLAY_WINDOW, IMAQ_PALETTE_BINARY, NULL, 0);
		imaqDisplayImage(image, DISPLAY_WINDOW, TRUE);

		// Wait for a key press before exiting
		printf("Press Enter to exit.\n");
		getchar();
		//delete imgProc;
		// Dispose resources
		//imaqDispose (image);
	}

	imaqDispose(imagePath);
}


bool VisionUI::LoadImagePath() {
	this->imagePath = imaqLoadImagePopup(NULL,"*.jpg", NULL, "Open Image", FALSE, IMAQ_BUTTON_LOAD,0,0,1,0, &cancelled,NULL);
	if(!cancelled) {
		return true;
	}
	return false;
}
char* VisionUI::GetImagePath() {
	return this->imagePath[0];
}
void VisionUI::CreateWindow(int window) {
	imaqMoveWindow(window, imaqMakePoint(0,0));
	imaqSetWindowPalette(window, IMAQ_PALETTE_BINARY, NULL, 0);
}
void VisionUI::DisplayImage(ImageBase *image, int window) {
	imaqDisplayImage(image->GetImaqImage(), window, TRUE);
}
void VisionUI::CleanUp() {
	imaqDispose(imagePath);
}
