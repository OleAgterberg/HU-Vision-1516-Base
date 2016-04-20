#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
    int width = getWidth(), height = getHeight();
    image.clear();
    //image_pointer = image.get_allocator().allocate(width*height);
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            setPixel(x, y, other.getPixel(x, y));
        }
    }
    //TODO: Create a copy from the other object
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
    //image_pointer = image.get_allocator().allocate(width*height);
    image.clear();
    //TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {
    //image.get_allocator().deallocate(image_pointer, getWidth() * getHeight());
    image.clear();
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
    int oldHeight = getHeight();
    int oldWidth = getWidth();
    IntensityImage::set(width, height);
    image.clear();
    //image.get_allocator().deallocate(image_pointer, oldHeight*oldWidth);
    //image_pointer = image.get_allocator().allocate(width*height);
    //TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
    int height = other.getHeight(), width = other.getWidth();
    IntensityImage::set(width, height);

    image.clear();
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            setPixel(x, y, other.getPixel(x, y));
        }
    }
    //TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
    image[y][x] = pixel;
    //TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
    int x = i % getWidth(), y = i / getWidth();
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

Intensity IntensityImageStudent::getPixel(int x, int y) const {
    std::map<const int, std::map<int, Intensity, std::less<int>, std::allocator<std::pair<const int, Intensity>>>>::const_iterator it_x;
    std::map<int, Intensity>::const_iterator it_y;
    it_x = image.find(x);
    it_y = it_x->second.find(y);
    return it_y->second;
	//TODO: no comment needed :)
}

Intensity IntensityImageStudent::getPixel(int i) const {
    int x = i % getWidth(), y = i / getWidth();
    return getPixel(x, y);
	//TODO: see setPixel(int i, RGB pixel)
}