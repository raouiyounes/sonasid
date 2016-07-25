/*
 * Image.h

 *
 *  Created on: 1 mars 2016
 *      Author: younes
 */
#include <vector>
#include <eigen3/Eigen/Dense>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#ifndef IMAGE_H_
#define IMAGE_H_
using namespace Eigen;
using namespace cv;
typedef vector<std::vector<double> > struct1;

class Image {
public:
	int number_of_line;
	cv::Mat descriptors;
	std::vector<KeyPoint> keypoints_1;
	char *image_str;
	MatrixXd desc_brics;
	MatrixXd detect_surf;
	struct1 descriptor_vect;
	vector<float> standart_deviation();
public:
	Image();
	vector<float>  compute_mean();
	int SURFExtractor();
	int clusterKmean();
	void ComputeDesc();
	virtual ~Image();

};

#endif /* IMAGE_H_ */
