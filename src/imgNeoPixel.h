
#include "baseImage.h"
#include "Adafruit_NeoPixel.h"


class imgNeoPixel {
							
	public:
				imgNeoPixel(Adafruit_NeoPixel* theLEDs,baseImage* theBMPImage);
	virtual	~imgNeoPixel(void);
	
	virtual	void	setLine(int row,int numPixels=0);
				bool	setupOffscreen(int numPixels=0);
				void	clearOffscreen(void);
	
	protected:
				Adafruit_NeoPixel*	mPixels;
				baseImage*				mImage;
				RGBpack* 				mRGBArray;
				int						mNumPixels;
				File						mFile;
				File*						mImageFile;
};

