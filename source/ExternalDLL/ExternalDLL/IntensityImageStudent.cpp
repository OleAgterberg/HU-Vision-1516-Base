#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {

    //TODO: Create a copy from the other object
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {

    //TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {

	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {

    //TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {

    //TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {

    //TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {

	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {

	//TODO: no comment needed :)
}

Intensity IntensityImageStudent::getPixel(int i) const {

	//TODO: see setPixel(int i, RGB pixel)
}