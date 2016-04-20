#include "RGBImageStudent.h"
#include <iostream>

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()){    
	//TODO: Create a copy from the other object
	// Copy rgbimage contents
	// Ferdi Method
	//initVector(other.getWidth(), other.getHeight());
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height){
    
	//TODO: Initialize pixel storage

	// Ferdi Method
}

RGBImageStudent::~RGBImageStudent() {
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	//RGB** t_rgb_array = rgb_image;
	delete_rgb_array();
	this->width		= width;
	this->height	= height;
	init_rgb_image();
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	//int throwError = 0, e = 1 / throwError; This method has been implemented
	
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
    //TODO: Create a copy from the other 
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
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
	//TODO: no comment needed :)
}

RGB RGBImageStudent::getPixel(int i) const {
	//TODO: see setPixel(int i, RGB pixel)
}
void RGBImageStudent::delete_rgb_array()	{
	for (size_t i = 0; i < width; i++)
	{
		delete[] rgb_image[i];
	}
	delete[] rgb_image;
}

void RGBImageStudent::init_rgb_image()	{
	*rgb_image = new RGB[height];
	for (size_t i = 0; i < height; i++)
	{
		**rgb_image = *new RGB[width];
	}

}