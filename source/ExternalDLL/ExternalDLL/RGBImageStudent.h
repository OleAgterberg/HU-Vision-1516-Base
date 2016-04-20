/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "RGBImage.h"
#include <vector>
#include <map>
#include <array>
#include <stdint.h>
#define rgb (uint8_t)3 // constexpr not supported by vc2013 current build (needs newer build -> November++ build)
class RGBImageStudent : public RGBImage {
public:

	RGBImageStudent();
	RGBImageStudent(const RGBImageStudent &other);
	RGBImageStudent(const int width, const int height);
	~RGBImageStudent();
	/*
	 *@brief Cropping of image, if new width and height are greater than current, 
	 *			resize image and fill extra pixels with black (or white).
	 *			If new width or height is smaller, keep old width and/or height.
	 *@*/
	void set(const int width, const int height);
	/*
	 *@brief Copy contents?
	 *@*/
	void set(const RGBImageStudent &other);

	void setPixel(int x, int y, RGB pixel);

	/*
	 * @brief set pixel i, if i > width, count on next row.
	 **/
	void setPixel(int i, RGB pixel);

	RGB getPixel(int x, int y) const;
	RGB getPixel(int i) const;

private:
    // 
    RGB **rgb_image;



};