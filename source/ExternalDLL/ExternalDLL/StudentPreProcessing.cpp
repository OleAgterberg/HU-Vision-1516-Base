#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"

/** 
*   used Luminosity with the values ( 0.21 R + 0.72 G + 0.07 B )
**/
IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
    IntensityImageStudent *intensitye_image = new IntensityImageStudent();
    int width = image.getWidth(), heigth = image.getHeight();
    intensitye_image->set(width, heigth);
    for (int y = 0; y < heigth; y++){
        for (int x = 0; x < width; x++){
            RGB rgb = image.getPixel(x, y);
            Intensity intensity = (0.21 * rgb.r + 0.72 * rgb.g + 0.07 * rgb.b);
            intensitye_image->setPixel(x, y, intensity);
        }
    }
	return intensitye_image;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}