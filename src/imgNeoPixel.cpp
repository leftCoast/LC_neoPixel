#include "imgNeoPixel.h"
#include <resizeBuff.h>


imgNeoPixel::imgNeoPixel(Adafruit_NeoPixel* theLEDs,baseImage* theBMPImage) {
	
	mPixels			= theLEDs;
	mImage			= theBMPImage;
	mRGBArray		= NULL;
	mNumPixels		= 0;
	mReadyToDraw	= false;
}
				
				
imgNeoPixel::~imgNeoPixel(void) {

	resizeBuff(0,(byte**)&mRGBArray);		// Deallocate the offscreen buffer.
	if (mImage) mImage->closeDocFile();		// Close but don't delete the image file.
}
	

// Open up the image file, make sure its readable. Then, if so.. Setup to allocate the
// offscreen buffer. Basically an array of RGBpack(s). There are three numbers to take
// into account. 
// First 	: The number of pixels we have on the string.
// Second	: The width of the image we have to read from.
// Third		: The actual value the uses puts in as the value, and that default to zero.
//
// How to choose?
void imgNeoPixel::setupOffscreen(int numPixels) {

	int	maxWidth;
	
	mReadyToDraw	= false;																	// We ain't ready yet..
	if (mImage) {																				// If we have an image file..
		if (mImage->openDocFile(FILE_READ)) {											// If we can open/read said image file..
			maxWidth = min(mPixels->numPixels(),mImage->getWidth());				// Grab the smaller of the image width and the number of pixels we have.
			if (numPixels==0) {																// If the numPixels passed in is zero..
				mNumPixels = maxWidth;														// We just use the maxWidth we just calculated.
			} else {																				// Else, we have non zero value passed in..
				mNumPixels = min(maxWidth,numPixels);									// We use the smallar of the previous max width and this new passed in value.
			}
			if (resizeBuff(sizeof(RGBpack)*mNumPixels,(byte**)&mRGBArray)) {	// If we can grab the RAM..
				mReadyToDraw = true;															// Ok, we are ready to draw!
				return;																			// We call all of this a success! And exit.
			} else {																				// Else, we could NOT allocate the buffer..
				mImage->closeDocFile();														// Close the image file.
			}
		}
	}																				// And if we got here? We call this a failure. And exit.
}
			

void imgNeoPixel::setLine(int row,int numPixels) {
	
	int		maxWidth;	
	
	if (mReadyToDraw) {
		if (numPixels) {
			maxWidth = min(mNumPixels,numPixels);
		} else {
			maxWidth = mNumPixels;
		}
		if (mImage->getRow(0,row,maxWidth,mRGBArray)) {
			for (int i=0;i<maxWidth;i++) {
				mPixels->setPixelColor(i,mRGBArray[i].r,mRGBArray[i].g,mRGBArray[i].b);
			}
		}
	}
}	
