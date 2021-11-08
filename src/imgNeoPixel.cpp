#include "imgNeoPixel.h"
#include <resizeBuff.h>


imgNeoPixel::imgNeoPixel(Adafruit_NeoPixel* theLEDs,baseImage* theBMPImage) {
	
	mPixels			= theLEDs;
	mImage			= theBMPImage;
	mRGBArray		= NULL;
	mNumPixels		= 0;
	mImageFile		= NULL;
}
				
				
imgNeoPixel::~imgNeoPixel(void) {

	resizeBuff(0,&mRGBArray);
	if (mFile) {
		mFile.close();
	}
}
	
	
bool  imgNeoPixel::setupOffscreen(int numPixels) {

	int		maxWidth;
	
	mImageFile = NULL;														// Just in case.
	maxWidth = min(mPixels->numPixels(),mImage->getWidth());
	if (numPixels==0) {
		mNumPixels = maxWidth;
	} else {
		mNumPixels = min(maxWidth,mNumPixels);
	}
	if (resizeBuff(sizeof(RGBpack)*mNumPixels,&mRGBArray)) {
		mFile = SD.open(mImage->getDocFilePath());
		if (mFile) {
			mImageFile = &mFile;
			return true;
		} else {
			resizeBuff(0,&mRGBArray);
			mNumPixels = 0;
		}
	}
	return false;
}
	
	
void imgNeoPixel::clearOffscreen(void) {

	resizeBuff(0,&mRGBArray);
	mNumPixels = 0;
	if (mFile) {
		mFile.close();
	}
	mImageFile = NULL;
}


void imgNeoPixel::setLine(int row,int numPixels) {
	
	int		maxWidth;	
	colorObj	aPixel;
	
	maxWidth = min(mPixels->numPixels(),mImage->getWidth());
	if (numPixels==0) {
		numPixels = maxWidth;
	} else {
		mNumPixels = min(maxWidth,mNumPixels);
	}
	if (mImageFile && mRGBArray) { 
		mImage->getRow(row,mRGBArray,mNumPixels,mImageFile);
		for (int i=0;i<mNumPixels;i++) {
			mPixels->setPixelColor(i,mRGBArray[i].r,mRGBArray[i].g,mRGBArray[i].b);
		}
	} else {
		for (int i=0;i<maxWidth;i++) {
			aPixel = mImage->getPixel(i,row);
			mPixels->setPixelColor(i,aPixel.getRed(),aPixel.getGreen(),aPixel.getBlue());
		}
	}
}			

	

