#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage(0, 0) {
    intensity_image = nullptr;
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
    init_intensity_image();
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            setPixel(x, y, other.getPixel(x, y));
        }
    }
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
    init_intensity_image();
}

IntensityImageStudent::~IntensityImageStudent() {
    delete_intensity_array(intensity_image, height);
}

void IntensityImageStudent::set(const int width, const int height) {
    // make temp of intensity_image
    Intensity** t_intensity_array = intensity_image;
    int old_width = this->width;
    int old_height = this->height;
    // make new empty intensity_image
    this->width = width;
    this->height = height;
    init_intensity_image();
    // copy old data of to new image
    cpy_intensity_array(intensity_image, t_intensity_array, old_width, old_height);
    // delete old image
    delete_intensity_array(t_intensity_array, old_height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
    Intensity** t_intensity_array = intensity_image;
    int old_height = height;
    width = other.width;
    height = other.height;

    init_intensity_image();
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            setPixel(x, y, other.getPixel(x, y));
        }
    }
    delete_intensity_array(t_intensity_array, old_height);
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
    intensity_image[y][x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
    int x = i % width, y = i / width;
    setPixel(x, y, pixel);
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
    return intensity_image[y][x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
    int x = i % width, y = i / width;
    return intensity_image[y][x];
}


void IntensityImageStudent::delete_intensity_array(Intensity** array1, int height)	{
    //if (array1 != nullptr){
        for (size_t i = 0; i < height; i++)
        {
            delete[] array1[i];
        }
        delete[] array1;
    //}
}

void IntensityImageStudent::init_intensity_image()	{
    intensity_image = new Intensity*[height];
    for (size_t i = 0; i < height; i++)
    {
        intensity_image[i] = new Intensity[width];
    }

}

void IntensityImageStudent::cpy_intensity_array(Intensity** array1, Intensity** array2, int width, int height)	{
    for (size_t i = 0; i < height; i++)
    {
        memcpy(array1[i], array2[i], width);
    }

}