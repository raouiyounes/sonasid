/*
 * Image.cpp
 *
 *  Created on: 1 mars 2016
 *      Author: younes
 */

#include "Image.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <opencv2/imgproc/imgproc_c.h>
#include <cv.h>
#include <highgui.h>
#define ROWS 10
#define COLS 65
using namespace cv;
 using namespace std;
Image::Image() {
	// TODO Auto-generated constructor stub
}

int Image::SURFExtractor(){
	  Mat img_1 = imread(image_str);
	 	  //-- Step 1: Detect the keypoints using SURF Detector
	  int minHessian = 400;
	  SurfFeatureDetector detector( minHessian );
	  detector.detect( img_1, keypoints_1 );
	   int Threshl=40;
	   int Octaves=2;
	   float PatternScales=1.0f;
	  CvMat* prevgray = 0, *image = 0, *gray =0;
IplImage* frame=cvLoadImage("test_image.jpg");
image = cvCreateMat(frame->height, frame->width, CV_8UC1);
	  CvMemStorage* storage = cvCreateMemStorage(0);
	  cvCvtColor(frame, image, CV_BGR2GRAY);
	  //Define sequence for storing surf keypoints and descriptors
	  CvSeq *imageKeypoints = 0, *imageDescriptors = 0;
	  int i,j;
vector<double> descriptor_row;
	  CvSURFParams params = cvSURFParams(500, 1);
	  cvExtractSURF( image, 0, &imageKeypoints, &imageDescriptors, storage, params );
	  for( i = 0; i < imageDescriptors->total; i++ )
	  {
	float* r = (float*)cvGetSeqElem( imageDescriptors, i);
	j=0;
	while(j<50){
descriptor_row.push_back(*r);
	r++;
	j++;
	}
	descriptor_vect.push_back(descriptor_row);
	number_of_line++;
	descriptor_row.clear();
	  }
	  return 0;
}


vector<float> Image::standart_deviation(){
vector<float> line_desc;
vector<float> line_std;
	int i,j;
float mean_line,std_line=0.0;
	VectorXd line(this->descriptor_vect.size());

for(i=0;i<this->descriptor_vect.size();i++){

for(j=0;j<descriptor_vect.at(i).size();j++)
line(j)=descriptor_vect.at(i).at(j);
mean_line=line.mean();
for(j=0;j<this->descriptor_vect.size();j++)
std_line+=pow(line(j)-mean_line,2);
line_std.push_back(sqrt(std_line));
}
return line_std;
}

vector<float>  Image::compute_mean(){

	vector<float> line_desc;
	vector<float> line_std;
	vector<float> line_mean;
		int i,j;
	float mean_line,std_line=0.0;
		VectorXd line(this->descriptor_vect.size());

	for(i=0;i<this->descriptor_vect.size();i++){

	for(j=0;j<ROWS;j++)
	line(j)=descriptor_vect.at(i).at(j);
	line_mean.push_back(line.mean());
	}
	return line_mean;
	}

int Image::clusterKmean(){const int MAX_CLUSTERS = 5;
Scalar colorTab[] =
{
Scalar(0, 0, 255),
Scalar(0,255,0),
Scalar(255,100,100),
Scalar(255,0,255),
Scalar(0,255,255)
};
Mat img(500, 500, CV_8UC3);
RNG rng(12345);
int i,j;
VectorXd line_desc_surf(ROWS);
vector<float> descriptor_line;
int k, clusterCount = rng.uniform(2, MAX_CLUSTERS+1);
int sampleCount = rng.uniform(1, 1001);

Mat points(sampleCount,2, CV_32FC2), labels;
vector<Point> test;
vector<float>  std_descriptor;
// getting the standard  devitaion

std_descriptor=this->standart_deviation();
for(i=0;i<this->number_of_line;i++){
//	descriptor_line=descriptor_vect.at(i);
		for(j=0;j<ROWS;j++){
				line_desc_surf(j)=descriptor_vect.at(i).at(j);
		}
		points.at<double>(i,0)=line_desc_surf.mean();
		points.at<double>(i,1)=std_descriptor.at(i);
 }


clusterCount = MIN(clusterCount, sampleCount);
Mat centers;


/* generate random sample from multigaussian distribution */
for( k = 0; k < clusterCount; k++ )
{
Point center;
center.x = rng.uniform(0, img.cols);
center.y = rng.uniform(0, img.rows);
}

kmeans(points, clusterCount, labels,
TermCriteria( TermCriteria::EPS+TermCriteria::COUNT, 10, 1.0),
3, KMEANS_PP_CENTERS, centers);

img = Scalar::all(0);
for( i = 0; i < sampleCount; i++ )
{
int clusterIdx = labels.at<int>(i);
cout<<clusterIdx<<"\n";
//Point ipt = points.at<Point2f>(i);
}
return 0;
}

void Image::ComputeDesc(){
const int BUFFSIZE=400;
char buff[BUFFSIZE];
char buff_appearance[3];
//MatrixXd descriptor(ROWS,COLS);
ifstream ifs("BriscDesc.txt");
stringstream ss;
string s;
int k,c,row,col;
for(row=0;row<ROWS-1;row++) {
ifs.getline(buff,BUFFSIZE);
ss<<buff;
for(col=0;col<COLS-2;col++){
getline( ss,s,',');
cout<<atoi(s.c_str())<<"\n";
descriptors.at<long>(row,col)=atoi(s.c_str());
ss<<"";
}
}



}
Image::~Image(){

}
