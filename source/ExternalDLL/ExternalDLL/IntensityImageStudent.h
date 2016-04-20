/*
 * @author Alexander Hustinx
 * @author Rolf Smit
 * @author NeoTech Software
 * @author Ole Agterberg
 * @author Ferdi Stoeltie
 * @date 13-04-2016
 * @brief 
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "IntensityImage.h"
#include <map>
class IntensityImageStudent : public IntensityImage {
public:
	/*
	 *@brief	
	 */
	IntensityImageStudent();

	/*
	*@brief
	*/
	IntensityImageStudent(const IntensityImageStudent &other);
	IntensityImageStudent(const int width, const int height);
	~IntensityImageStudent();

	void set(const int width, const int height);
	void set(const IntensityImageStudent &other);

	void setPixel(int x, int y, Intensity pixel);
	void setPixel(int i, Intensity pixel);

	Intensity getPixel(int x, int y) const;
	Intensity getPixel(int i) const;

private:
    void delete_intensity_array();
    void init_intensity_image();
    Intensity **intensity_image;
};