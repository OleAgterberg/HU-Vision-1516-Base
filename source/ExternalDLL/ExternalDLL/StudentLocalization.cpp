#include "StudentLocalization.h"

bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}
std::vector<unsigned int> StudentLocalization::getEyeCandy(const std::vector<unsigned int>& histo_x, const std::vector<unsigned int>& histo_y)	const {
	/*
	 * Link between depth and length of rise and fall
	 * Test the Rise, and Test the Fall (start with deepest plots)
	 * 
	 **/
	std::vector<unsigned int> x_rises;
	int deepest_point = 255;
	unsigned const int max_pixel_range = 5;
	int check_pixels_range = 0;
	
	int current_fall = -1;
	std::cout << "histo y is very very big for his age: " << histo_y.size() << std::endl;
	for (int i = 0; i < histo_y.size(); i++)	{
		// Check if pixels in range belong to the same fall
		if (check_pixels_range > 1)	{
			if (histo_y[i] < deepest_point)	{
				std::cout << "i found a deep in a deep " << histo_y[i] << std::endl;
				deepest_point = histo_y[i];	// new found deepest point in current fall
				x_rises[current_fall] = i;	// set new fall as current point fall
				check_pixels_range = max_pixel_range;
			}
			check_pixels_range--;
		}
		// Old fall has been identified, and new one is being set
		else {
			deepest_point = 255;
			if (histo_y[i] < deepest_point)	{ // dit hoort een nieuw dal te zijn
				
				++current_fall;				// set new fall, since old one has been identified
				std::cout << "New fall found: " << histo_y[i] << std::endl;
				deepest_point = histo_y[i]; // new found deepest point in current fall
				x_rises.push_back(i);	// set new fall as current point fall
				check_pixels_range = max_pixel_range;
				//x_rises[current_fall] = i;	// set new fall as current point fall
			}
		}	
	}
	return x_rises;
}
bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {
	Feature head_top = features.getFeature(Feature::FEATURE_HEAD_TOP);
	Feature head_left = features.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE);
	Feature head_right = features.getFeature(Feature::FEATURE_HEAD_RIGHT_SIDE);
	Feature nose_bottom_left = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM);
	Feature nose_bottom_right = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM);

	std::vector<Point2D<double>> head_top_points = head_top.getPoints();
	std::vector<Point2D<double>> head_left_points = head_left.getPoints();
	std::vector<Point2D<double>> head_right_points = head_right.getPoints();
	std::vector<Point2D<double>> nose_bottom_left_points = nose_bottom_left.getPoints();
	std::vector<Point2D<double>> nose_bottom_right_points = nose_bottom_right.getPoints();

	// get first rect around the eyes
	Point2D<double> top_left;
	Point2D<double> bottom_right;
	top_left.x = head_left_points[0].x;
	top_left.y = head_top_points[0].y;
	bottom_right.x = head_right_points[0].x;
	bottom_right.y = nose_bottom_right_points[0].y;
	//int height = nose_bottom_points[0].getY() - head_top_points[0].getY();
	//std::cout << "height between head top and nose bottom is: " << height << std::endl;
	
	int width = head_right_points[0].getX() - head_left_points[0].getX();

	std::cout << "width between left and right side of head is: " << width << std::endl;
	std::vector<unsigned int> histo_general;
	std::vector<unsigned int> histo_y;
	std::vector<unsigned int> histo_x;
	histo_general.resize(256, 0);
	histo_y.resize(bottom_right.y - top_left.y, 0);
	//histo_x.resize(bottom_right.x - top_left.x, 0);
	for (int i = top_left.y; i < bottom_right.y; i++)
	{
		for (int j = top_left.x; j < bottom_right.x; j++)	{
			Intensity newIntensity = image.getPixel(j, i);
			if (newIntensity == 255)
				histo_y[i - top_left.y]++;
			if(newIntensity <= 255)
				histo_general[newIntensity]++;
			
		}
	}
/*	for (int j = top_left.x; j < bottom_right.x; j++)
	{
		for (int i = top_left.y; i < bottom_right.y; i++) 
		{
			Intensity newIntensity = image.getPixel(i, j);
			if (newIntensity == 255)
				histo_x[i]++;
			
		}
	}*/
	std::vector<unsigned int> eyeCandyResults = getEyeCandy(histo_x, histo_y);
	for (unsigned int i = 0; i < eyeCandyResults.size(); i++)	{
		std::cout << "deepest points of falls found: " << eyeCandyResults[i] << std::endl;
	}
/*	for (size_t i = 0; i < histo_general.size(); i++)
	{
		std::cout << "Histo y: " << histo_general[i] << std::endl;
	}*/
	for (size_t i = 0; i < histo_y.size(); i++)
	{
		//std::cout << "y: " << i << "value: " << histo_y[i] << std::endl;
	}
	std::cout << std::endl;
/*  Feature left_eye = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
    Feature right_eye = features.getFeature(Feature::FEATURE_EYE_RIGHT_RECT);
    std::vector<Point2D<double>> left_points = left_eye.getPoints();
    std::vector<Point2D<double>> right_points = right_eye.getPoints();

    std::cout << " size of rect: " << left_points.size() << std::endl;
    for (Point2D<double> n : left_points){
        std::cout << "(" << n.getX() << "," << n.getY() << ")\n";
    }
    */
	std::cout << "width between left and right side of head is: " << width << std::endl;
	return true;
}