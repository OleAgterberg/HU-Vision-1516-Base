#include "StudentLocalization.h"
#include "IntensityImageStudent.h"
using namespace std;
bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {
	// Assert all previous features have been mapped correctly
	// Todo:
	// Create copy of image
	// Morph image (using dilation?)
	// Morphing:
	//		Get a black - white version of the image (Intensity image)
	
	// Copy the image and create a new version of it.
	
	img_copy.setPixel(features.getFeature(Feature::FEATURE_EYE_LEFT_RECT).getX(), features.getFeature(Feature::FEATURE_EYE_LEFT_RECT).getX(), 100);
	
	//cout << "Left eye points are: [x]: " << left_eye.getPoints()[0].getX() << "[y]: " << left_eye.getPoints()[0].getY() << endl;
	return false;
}