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

    /*
    Feature left_eye = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
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