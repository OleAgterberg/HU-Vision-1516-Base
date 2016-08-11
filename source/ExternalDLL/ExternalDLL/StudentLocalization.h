/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "Localization.h"
#include <iostream>
class StudentLocalization :
	public Localization {
public:

	bool stepFindHead(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindChinContours(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const;
	std::vector<unsigned int> getEyeCandy(const std::vector<unsigned int>& histo, const int offset, bool deep) const;
    std::vector<unsigned int> histogram_x(const IntensityImage &image);
    std::vector<unsigned int> histogram_y(const IntensityImage &image);
private:
    Point2D<double>* top_left = nullptr;
    Point2D<double>* bottom_right = nullptr;

};

