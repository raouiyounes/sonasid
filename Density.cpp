/*
 * Density.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: younes
 */

#include "Density.h"
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <fstream>
using namespace std;
using namespace Eigen;
namespace sonasid {

Mat img = cv::imread("b.jpg", 0); // force grayscale
Mat thresh=Mat::zeros(img.size(),CV_8UC1);
ofstream annotation("file.txt");
void onMouse( int event, int x, int y, int, void* );

Density::Density() {
	// TODO Auto-generated constructor stub

	index=0;

}


MatrixXd Density::getXY(){

	Mat img = cv::imread("b.jpg", 0); // force grayscale
	Mat thresh=Mat::zeros(img.size(),CV_8UC1);

	Mat binary;
Mat img_loc=this->img;

threshold(img,binary,50,255,THRESH_TOZERO);
namedWindow("thresh");
setMouseCallback( "thresh", onMouse, 0 );
imshow("thresh",img);
cvWaitKey(0);
}


Density::~Density() {
	// TODO Auto-generated destructor stub
}



void onMouse( int event, int x, int y, int, void* )
{
    if( event != CV_EVENT_LBUTTONDOWN )
            return;
    Point pt = Point(x,y);
    std::cout<<"x="<<pt.x<<"\t y="<<pt.y<<"\t value="<<thresh.at<uchar>(x,y)<<"\n";

    annotation<<pt.x<<" "<<pt.y<<endl;
}


} /* namespace sonasid */
