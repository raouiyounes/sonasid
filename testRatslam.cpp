//============================================================================
// Name        : testRatslam.cpp
// Author      : Younès
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "Image.h"
#include "Dictionary.cpp"
#include <cv.h>
#include <highgui.h>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"

#define ROWS 10
#define COLS 65

//using namespace ratslam;
using namespace cv;
using namespace std;
int main(void) {
	int i,j=0;
	std::vector<KeyPoint> keypoints_1;
	  cv::Mat descriptor_view;
	vector<double>  descript_row;
	  struct1  descript_struct;
	  ofstream myfile("test.txt"),descriptor_file("BriscDesc.txt");
	Image *x=new Image();
	x->image_str="test_image.jpg";
	x->SURFExtractor();
	int number_of_lines;
	number_of_lines=x->keypoints_1.size();

	Dictionary *dico=new Dictionary(number_of_lines,1);
int var=dico->clusterKmean();





	/*

	x->image_str="test_image.jpg";
x->SURFExtractor();
keypoints_1=x->keypoints_1;
x->number_of_line=0;
descript_struct=x->descriptor_vect;




for(i=0;i<descript_struct.size();i++){
descript_row=descript_struct.at(i);
for(j=0;j<ROWS;j++)
	descriptor_file<<descript_row.at(j)<<" ";
descriptor_file<<"\n";
}
for(i=0;i<keypoints_1.size();i++)
myfile<<keypoints_1[i].pt.x<<"\n";





vector<float> rrr;
rrr=x->standart_deviation();
x->clusterKmean();
*/
	puts("Hello World!!!");
	return EXIT_SUCCESS;
}
