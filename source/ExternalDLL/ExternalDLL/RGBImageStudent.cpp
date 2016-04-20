#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage(), ARRAYSIZE{ 0 }{
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()), ARRAYSIZE{ other.getWidth() * other.getHeight() }{
	int throwError = 0, e = 1 / throwError;
	//TODO: Create a copy from the other object
	// Copy rgbimage contents
	// Ferdi Method
	//initVector(other.getWidth(), other.getHeight());
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height), ARRAYSIZE{ width * height } {
	int throwError = 0, e = 1 / throwError;
	//TODO: Initialize pixel storage

	// Ferdi Method
	initVector(width, height);
}

RGBImageStudent::~RGBImageStudent() {
	int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	RGBImage::set(width, height);
	int throwError = 0, e = 1 / throwError;
	
	RGB **vi_array_t;
	vi_array_t = new RGB*[width];
	for (size_t i = 0; i < width; i++)
	{
		vi_array_t[i] = new RGB[height]{ RGB(0, 0, 0) };
	}
	memcpy(vi_array_t, vi_array, (width * height * sizeof(RGB))); // should be done for each row!

}

void RGBImageStudent::set(const RGBImageStudent &other) {
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	emptyArray();	// Deleting old data
	RGBImage::set(other.getWidth(), other.getHeight());	// setting RGB Image width and height
	copy_vimage(other);	// Copying other RBGImageStudent content to this RGBImageStudent
	//int throwError = 0, e = 1 / throwError; This method has been implemented
	
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int throwError = 0, e = 1 / throwError;
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

RGB RGBImageStudent::getPixel(int x, int y) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	return 0;
}
void RGBImageStudent::copy_vimage(const RGBImageStudent &other)	{
	// Delete old data
	vi_array = new RGB*[other.width];
	for (size_t i = 0; i < other.width; i++)
	{
		vi_array[i] = new RGB[other.height]{ RGB(0, 0, 0) };
		for (size_t j = 0; j < other.height; j++)
		{
			// Copy the other array data into the new array data
			vi_array[i][j] = other.vi_array[i][j];
		}
	}
}
void RGBImageStudent::initVector(const int width, const int height)	{
	vi_array = new RGB*[width];
	for (size_t i = 0; i < width; i++)
	{
		vi_array[i] = new RGB[height]{ RGB(0, 0, 0) };
	}
}
void RGBImageStudent::emptyArray()	{
	// Cleanup multidimensional array
	for (size_t i = 0; i < width; i++)
	{
		delete[] vi_array[i];
	}
	delete[] vi_array;
}