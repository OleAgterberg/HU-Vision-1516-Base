#include "RGBImageStudent.h"
#include <iostream>

RGBImageStudent::RGBImageStudent() : RGBImage(), ARRAYSIZE{ 0 }{
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()), ARRAYSIZE{ other.getWidth() * other.getHeight() }{
    int width = getWidth(), height = getHeight();
    image.clear();
    //image_pointer = image.get_allocator().allocate(width*height);
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            setPixel(x, y, other.getPixel(x, y));
            //RGB pixel = other.getPixel(x, y);
            //std::cout << "(" << pixel.b << ", " << pixel.g << ", " << pixel.r << ") ";
        }
    }
	//TODO: Create a copy from the other object
	// Copy rgbimage contents
	// Ferdi Method
	//initVector(other.getWidth(), other.getHeight());
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height), ARRAYSIZE{ width * height } {
    //int throwError = 0, e = 1 / throwError;
    image.clear();
	//TODO: Initialize pixel storage

	// Ferdi Method
	initVector(width, height);
}

RGBImageStudent::~RGBImageStudent() {
    //image.get_allocator().deallocate(image_pointer, getWidth() * getHeight());
    image.clear();
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
    int oldHeight = getHeight();
    int oldWidth = getWidth();
	RGBImage::set(width, height);
    image.clear();
    //image.get_allocator().deallocate(image_pointer, oldHeight*oldWidth);
    //image_pointer = image.get_allocator().allocate(width*height);
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent &other) {
    int height = other.getHeight(), width = other.getWidth();
	RGBImage::set(width, height);

    image.clear();
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            setPixel(x, y, other.getPixel(x, y));
        }
    }

    //////////////////////////////////////

	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	emptyArray();	// Deleting old data
	RGBImage::set(other.getWidth(), other.getHeight());	// setting RGB Image width and height
	copy_vimage(other);	// Copying other RBGImageStudent content to this RGBImageStudent
	int throwError = 0, e = 1 / throwError;
	
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
    image[y][x] = pixel;
    //image_pointer = image.get_allocator().allocate(width*height);
    /*std::cout << "(" << int(pixel.b) << ", " << int(pixel.g) << ", " << int(pixel.r) << ") ";
    if (getWidth() == x){
        std::cout << std::endl;
    }*/
    //TODO: Create a copy from the other 
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
    int x = 1, y = 1; //i % getWidth(), y = i / getWidth();
    image[y][x] = pixel;
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
    std::map<const int, std::map<int, RGB, std::less<int>, std::allocator<std::pair<const int, RGB>>>>::const_iterator it_x;
    std::map<int, RGB>::const_iterator it_y;
    it_x = image.find(x);
    it_y = it_x->second.find(y);
    return it_y->second;
	//TODO: no comment needed :)
}

RGB RGBImageStudent::getPixel(int i) const {
    int x = i % getWidth(), y = i / getWidth();
    RGB pixel = getPixel(x, y);
    return getPixel(x, y);
	//TODO: see setPixel(int i, RGB pixel)
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