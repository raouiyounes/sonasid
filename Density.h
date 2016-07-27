/*
 * Density.h
 *
 *  Created on: Jul 25, 2016
 *      Author: younes
 */

#ifndef DENSITY_H_
#define DENSITY_H_

#include "Image.h"
#include <vector>
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

namespace sonasid {

class Density: public Image {
	MatrixXd PtsAnnotation;

public:
	 int numberof_annot;
	char *img_str;
	Mat img;
	int index;
	Density();
	MatrixXd getXY();
	virtual ~Density();
	friend void onMouse( int event, int x, int y, int, void* );
	MatrixXd readAnnotations();
	Mat computeF0();



};

} /* namespace sonasid */

#endif /* DENSITY_H_ */
