#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
    init_intensity_image();
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            setPixel(x, y, other.getPixel(x, y));
        }
    }
    //TODO: Create a copy from the other object
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
    init_intensity_image();
    //TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {
    delete_intensity_array(intensity_image);
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
    Intensity** t_intensity_array = intensity_image;
    int old_width = this->width;
    int old_height = this->height;
    this->width = width;
    this->height = height;
    init_intensity_image();
    cpy_intensity_array(intensity_image, t_intensity_array, old_width, old_height);
    delete_intensity_array(t_intensity_array);
    //TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
    Intensity** t_intensity_array = intensity_image;
    init_intensity_image();
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            setPixel(x, y, other.getPixel(x, y));
        }
    }
    delete_intensity_array(intensity_image);
    //TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
    intensity_image[y][x] = pixel;
    //TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
    int x = i % width, y = i / width;
    setPixel(x, y, pixel);
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
    return intensity_image[y][x];
	//TODO: no comment needed :)
}

Intensity IntensityImageStudent::getPixel(int i) const {
    int x = i % width, y = i / width;
    return intensity_image[y][x];
	//TODO: see setPixel(int i, RGB pixel)

}


void IntensityImageStudent::delete_intensity_array(Intensity** array1)	{
    for (size_t i = 0; i < width; i++)
    {
        delete[] array1[i];
    }
    delete[] array1;
}

void IntensityImageStudent::init_intensity_image()	{
    *intensity_image = new Intensity[height];
    for (size_t i = 0; i < height; i++)
    {
        **intensity_image = *new Intensity[width];
    }

}

void IntensityImageStudent::cpy_intensity_array(Intensity** array1, Intensity** array2, int width, int height)	{
    for (size_t i = 0; i < height; i++)
    {
        memcpy(array1[i], array2[i], width);
    }

}