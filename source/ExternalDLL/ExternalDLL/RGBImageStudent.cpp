#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage(0, 0) {
	// set rgb_image nullptr, safety check
    rgb_image = nullptr;
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()){    
    init_rgb_image();
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            setPixel(x, y, other.getPixel(x, y));
        }
    }
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height){
    init_rgb_image();
	//TODO: Initialize pixel storage

	// Ferdi Method
}

RGBImageStudent::~RGBImageStudent() {
    delete_rgb_array(rgb_image, height);
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)

	RGB** t_rgb_array = rgb_image;
	
	//delete_rgb_array();
	int old_width	= this->width;
	int old_height	= this->height;

	this->width		= width;
	this->height	= height;
	init_rgb_image();
	cpy_rgb_array(rgb_image, t_rgb_array, old_width, old_height);
	delete_rgb_array(t_rgb_array, old_height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	//int throwError = 0, e = 1 / throwError; This method has been implemented
    RGB** t_rgb_array = rgb_image;
    int old_height = height;
    width = other.width;
    height = other.height;
    init_rgb_image();
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            setPixel(x, y, other.getPixel(x, y));
        }
    }
    delete_rgb_array(t_rgb_array, old_height);
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
    rgb_image[y][x] = pixel;
    //TODO: Create a copy from the other 
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
    int x = i % width, y = i / width;
    rgb_image[y][x] = pixel;
}


RGB RGBImageStudent::getPixel(int x, int y) const {
	//TODO: no comment needed :)
	return rgb_image[y][x];
}

RGB RGBImageStudent::getPixel(int i) const {
	// i % width = row. i / width = column
    int x = i % width, y = i / width;
    return rgb_image[y][x];
}
void RGBImageStudent::delete_rgb_array(RGB** array1, int old_height) {
   // if (array1 != nullptr){
        for (size_t i = 0; i < old_height; i++)
        {
            delete[] array1[i];
        }
        delete[] array1;
    //}
}

void RGBImageStudent::init_rgb_image()	{
    rgb_image = new RGB*[height];
	for (size_t i = 0; i < height; i++)
	{
		rgb_image[i] = new RGB[width];
	}

}

void RGBImageStudent::cpy_rgb_array(RGB** array1, RGB** array2, int width, int height)	{
	for (size_t i = 0; i < height; i++)
	{
		memcpy(array1[i], array2[i], width);
	}
	
}