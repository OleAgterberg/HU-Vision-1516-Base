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

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {
    Feature head_top = features.getFeature(Feature::FEATURE_HEAD_TOP);
    Feature head_left = features.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE);
    Feature head_right = features.getFeature(Feature::FEATURE_HEAD_RIGHT_SIDE);
    Feature nose_bottom = features.getFeature(Feature::FEATURE_NOSE_BOTTOM);
    Feature mouth_center = features.getFeature(Feature::FEATURE_MOUTH_CENTER);
    
    std::vector<Point2D<double>> head_top_points = head_top.getPoints();
    std::vector<Point2D<double>> head_left_points = head_left.getPoints();
    std::vector<Point2D<double>> head_right_points = head_right.getPoints();
    std::vector<Point2D<double>> nose_bottom_points = nose_bottom.getPoints();
    std::vector<Point2D<double>> mouth_center_points = mouth_center.getPoints();

	int height = nose_bottom_points[0].getY() - head_top_points[0].getY();
	std::cout << "height between head top and nose bottom is: " << height << std::endl;
	
	int width = head_right_points[0].getX() - head_left_points[0].getX();

	std::cout << "width between left and right side of head is: " << width << std::endl;
	std::vector<unsigned int> histo_general;
	std::vector<unsigned int> histo_y;
	histo_general.resize(256, 0);
	histo_y.resize(image.getHeight(), 0);
	for (int i = 0; i < image.getHeight(); i++)
	{
		for (int j = 0; j < image.getWidth(); j++)	{
			Intensity newIntensity = image.getPixel(j, i);
			if (newIntensity == 255)
				histo_y[i]++;
			if(newIntensity <= 255)
				histo_general[newIntensity]++;
			
		}
	}
/*	for (size_t i = 0; i < histo_general.size(); i++)
	{
		std::cout << "Histo y: " << histo_general[i] << std::endl;
	}*/
	for (size_t i = 0; i < histo_y.size(); i++)
	{
		std::cout << "y: " << i << "value: " << histo_y[i] << std::endl;
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
	return true;
}