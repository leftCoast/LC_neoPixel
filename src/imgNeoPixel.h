#ifndef imgNeoPixel_h
#define imgNeoPixel_h


#include "baseImage.h"
#include "Adafruit_NeoPixel.h"


class imgNeoPixel {
							
	public:
				imgNeoPixel(Adafruit_NeoPixel* theLEDs,baseImage* theBMPImage);
	virtual	~imgNeoPixel(void);
	
				void	setupOffscreen(int numPixels=0);
	virtual	void	setLine(int row,int numPixels=0);
	
	protected:
				Adafruit_NeoPixel*	mPixels;
				baseImage*				mImage;
				RGBpack* 				mRGBArray;
				int						mNumPixels;
				bool						mReadyToDraw;
};

#endif