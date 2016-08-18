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
std::vector<unsigned int> StudentLocalization::getEyeCandy(const std::vector<unsigned int>& histo, const int offset, bool deep)	const {
	/*
	 * Link between depth and length of rise and fall
	 * Test the Rise, and Test the Fall (start with deepest plots)
	 * 
	 **/
	std::vector<unsigned int> x_rises;
	int deepest_point = deep ? 255 : 0;
	unsigned const int max_pixel_range = 5;
	int check_pixels_range = 0;
	
	int current_fall = -1;
    //std::cout << "histo y is very very big for his age: " << histo.size() << std::endl;
    for (int i = 0; i < histo.size(); i++)	{
		// Check if pixels in range belong to the same fall
		if (check_pixels_range > 1)	{
            if (deep ? histo[i] < deepest_point : histo[i] > deepest_point)	{
                //std::cout << "i found a deep in a deep " << histo[i] << std::endl;
                deepest_point = histo[i];	// new found deepest point in current fall
				x_rises[current_fall] = i;	// set new fall as current point fall
				check_pixels_range = max_pixel_range;
			}
			check_pixels_range--;
		}
		// Old fall has been identified, and new one is being set
		else {
			deepest_point = deep ? 255 : 0;
            if (deep ? histo[i] < deepest_point : histo[i] > deepest_point)	{ // nieuw dal 
				
				++current_fall;				// set new fall, since old one has been identified
                //std::cout << "New fall found: " << histo[i] << " at point: " << i + 16 << std::endl;
                deepest_point = histo[i]; // new found deepest point in current fall
                x_rises.push_back(i);	// set new fall as current point fall
				check_pixels_range = max_pixel_range;
				//x_rises[current_fall] = i;	// set new fall as current point fall
			}
		}	
	}
    std::cout << "rises: \n";
    for (auto a : x_rises){
        std::cout << a + offset << std::endl;
    }
	return x_rises;
}

std::vector<std::vector<int>> get_dalls(std::vector<unsigned int> dal_points, 
                                        std::vector<unsigned int> top_points, 
                                        std::vector<unsigned int> histo, 
                                        int offset ){
    std::vector<std::vector<int>> dalls; // = { 0, 0, 0 }; // 0: deep   1: y-begin    2: y-end
    //deepest_dall.resize(3, 0);   // 0: deep   1: y-begin    2: y-end
    for (int dal : dal_points){
        int high_top = -1, low_top = -1;
        for (int i = 1; i < top_points.size(); i++){
            if (dal < top_points[i]){
                high_top = top_points[i];
                low_top = top_points[i - 1];
                break;
            }
        }
        if (high_top != -1){
            //std::cout << "low_top = " << low_top + offset << "  high_top = " << high_top + offset << std::endl;
            int deep = histo[low_top] + histo[high_top] - (2 * histo[dal]);
            std::vector<int> dall = { 0, 0, 0 };
            dall[0] = deep;
            dall[1] = low_top + offset;
            dall[2] = high_top + offset;
            dalls.push_back(dall);
            
            /*if (deep > deepest_dall[0]){
                deepest_dall[0] = deep;
                deepest_dall[1] = low_top + offset;
                deepest_dall[2] = high_top + offset;
            }*/
        }
    }
    return dalls;
}

// points: (x,y) top_left (x,y) bottom_right
std::vector<unsigned int> StudentLocalization::histogram_x(const IntensityImage &image) const{
    std::vector<unsigned int> histo_x;
    histo_x.resize(bottom_right->x - top_left->x, 0);
    for (int x = top_left->x; x < bottom_right->x; x++)
    {
        for (int y = top_left->y; y < bottom_right->y; y++)	{
            Intensity newIntensity = image.getPixel(x, y);
            if (newIntensity == 255)
                histo_x[x - top_left->x]++;
        }
    }
    return histo_x;
}

std::vector<unsigned int> StudentLocalization::histogram_y(const IntensityImage &image) const{
    std::vector<unsigned int> histo;
    histo.resize(bottom_right->y - top_left->y, 0);

    for (int y = top_left->y; y < bottom_right->y; y++)
    {
        for (int x = top_left->x; x < bottom_right->x; x++)	{
            Intensity newIntensity = image.getPixel(x, y);
            if (newIntensity == 255)
                histo[y - top_left->y]++;
        }
    }
    return histo;
}

// function removed points between two points
std::vector<unsigned int> remove_points_between(std::vector<unsigned int> list, int begin, int end){
    std::vector<unsigned int> new_list;
    for (unsigned int i : list){
        if (i < begin || i > end){
            new_list.push_back(i);
        }
    }
    return new_list;
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
	top_left->x = head_left_points[0].x;
	top_left->y = head_top_points[0].y;
	bottom_right->x = head_right_points[0].x;
	bottom_right->y = nose_bottom_right_points[0].y;
    

	
	int width = head_right_points[0].getX() - head_left_points[0].getX();

	//std::cout << "width between left and right side of head is: " << width << std::endl;

    // histogram on y-as
    std::vector<unsigned int> histo_y;
    histo_y.resize(bottom_right->y - top_left->y, 0);
    histo_y = histogram_y(image);

    int offset = top_left->y;
    std::cout << offset << " = offset_y" << std::endl;
    std::vector<unsigned int> eyeCandyResults_dall = getEyeCandy(histo_y, offset, true);
    std::vector<unsigned int> eyeCandyResults_top = getEyeCandy(histo_y, offset, false);

    std::vector<int> deepest_dall_y = { 0, 0, 0 }; // 0: deep   1: y-begin    2: y-end
    std::vector<std::vector<int>> dalls_y; //= { 0, 0, 0 }; // 0: deep   1: y-begin    2: y-end
    dalls_y = get_dalls(eyeCandyResults_dall, eyeCandyResults_top, histo_y, offset);
    
/*
    // remove deepest dal
    std::vector<unsigned int> new_dalls_y, new_tops_y;
    new_dalls_y = remove_points_between(eyeCandyResults_dall, deepest_dall_y[1] - offset, deepest_dall_y[2] - offset);
    new_tops_y = remove_points_between(eyeCandyResults_top, deepest_dall_y[1] - offset, deepest_dall_y[2] - offset);
    // get second deepest dal
    std::vector<int> second_deepest_dall_y = { 0, 0, 0 }; // 0: deep   1: y-begin    2: y-end
    second_deepest_dall_y = get_deepest_dal(new_dalls_y, new_tops_y, histo_y, offset);
    std::cout << "second deepest dal in y = " << second_deepest_dall_y[0] << " begin: " << second_deepest_dall_y[1] << " end: " << second_deepest_dall_y[2] << std::endl;
*/

    for (auto i : dalls_y){
        if (i[0] > deepest_dall_y[0]){
            deepest_dall_y[0] = i[0];
            deepest_dall_y[1] = i[1];
            deepest_dall_y[2] = i[2];
        }
        std::cout << "dal in y = " << i[0] << " begin: " << i[1] << " end: " << i[2] << std::endl;
    }

    std::cout << "deepest dal in y = " << deepest_dall_y[0] << " begin: " << deepest_dall_y[1] << " end: " << deepest_dall_y[2] << std::endl;

    // use info of histo_y to scale the rect around the eyes
    top_left->y = deepest_dall_y[1];
    bottom_right->y = deepest_dall_y[2];

    // Start of histo_x
    std::vector<unsigned int> histo_x;
    histo_x.resize(bottom_right->x - top_left->x, 0);
    histo_x = histogram_x(image);

    offset = top_left->x;
    std::cout << offset << " = offset_x" << std::endl;
    eyeCandyResults_dall = getEyeCandy(histo_x, offset, true);
    eyeCandyResults_top = getEyeCandy(histo_x, offset, false);
    
    std::vector<int> deepest_dall_x = { 0, 0, 0 }; // 0: deep   1: x-begin    2: x-end
    std::vector<std::vector<int>> dalls_x;
    dalls_x = get_dalls(eyeCandyResults_dall, eyeCandyResults_top, histo_x, offset);


    for (auto i : dalls_x){
        if (i[0] > deepest_dall_x[0]){
            deepest_dall_x[0] = i[0];
            deepest_dall_x[1] = i[1];
            deepest_dall_x[2] = i[2];
        }
        std::cout << "dal in x = " << i[0] << " begin: " << i[1] << " end: " << i[2] << std::endl;
    }

    std::cout << "deepest dal in x = " << deepest_dall_x[0] << " begin: " << deepest_dall_x[1] << " end: " << deepest_dall_x[2] << std::endl;
    
	return true;
}