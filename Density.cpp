/*
 * Density.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: younes
 */

#include "Density.h"
#include <string>
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
#define pi 3.14
using namespace std;
using namespace Eigen;
namespace sonasid {
Mat img = cv::imread("b.jpg", 0); // force grayscale
Mat thresh=Mat::zeros(img.size(),CV_8UC1);
ofstream annotation("file.txt");
void onMouse( int event, int x, int y, int, void* );
vector<int>  anot_x;
vector<int>  anot_y;
Density::Density() {
	// TODO Auto-generated constructor stub
	index=0;
}

MatrixXd Density::getXY(){
	Mat img = cv::imread("b.jpg", 0); // force grayscale
	Mat thresh=Mat::zeros(img.size(),CV_8UC1);
MatrixXd anot_coord(5,2);
	Mat binary;
Mat img_loc=this->img;

threshold(img,binary,50,255,THRESH_TOZERO);
namedWindow("thresh");
cout<<"hhhhhhh";

setMouseCallback( "thresh", onMouse, 0 );
numberof_annot++;

imshow("thresh",img);
cvWaitKey(4000);
MatrixXd annot(4,2);
for(int i=0;i<2;i++){
	annot(i,0)=anot_x.at(i);
	annot(i,1)=anot_y.at(i);
}
return annot;
}


Density::~Density() {
	// TODO Auto-generated destructor stub
}

Mat Density::computeF0(){

int anotate;
MatrixXd patch(3,3);
Mat imgMat;
float pixelValue;
vector<int> x_patch,y_patch;
VectorXd pixel(2);
MatrixXd sigma(2,2);
int i,j;  //dimensions of the image

/*
for(i=0;i<imgMat.rows;i++)
	for(j=0;j<imgMat.cols;j++){
pixelValue=imgMat.at<double>(i,j);

// build the patch
for (int l = 0; l < 3; l++)
	for (int m = 0; m < 3; m++) {
		if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < imgMat.rows && j + 1 < imgMat.cols) {
			patch(0, 0) = pixelValue;
			patch(0, 1) = imgMat.at<double>(i - 1, j);
			patch(0, 2) = imgMat.at<double>(i + 1, j);
			patch(1, 0) = imgMat.at<double>(i, j - 1);
			patch(1, 1) = imgMat.at<double>(i, j + 1);
			patch(1, 2) = imgMat.at<double>(i - 1, j - 1);
			patch(2, 0) = imgMat.at<double>(i - 1, j + 1);
			patch(2, 2) = imgMat.at<double>(i + 1, j + 1);
			patch(2, 1) = imgMat.at<double>(i + 1, j - 1);
		}

		else
			cout << "error in the patch's dimension";
	}

x_patch.push_back(i-1);
x_patch.push_back(i);
x_patch.push_back(i+1);


y_patch.push_back(j-1);
y_patch.push_back(j);
y_patch.push_back(j+1);
float std_x_patch=0.0,std_y_patch=0.0;http://www.cplusplus.com/doc/tutorial/files/

float m_x_patch=(x_patch.at(0)+x_patch.at(1)+x_patch.at(2))/3;
float m_y_patch=(y_patch.at(0)+y_patch.at(1)+y_patch.at(2))/3;

for(int t=0;t<3;t++){
	std_x_patch+=pow((x_patch.at(t)-m_x_patch),2);
	std_y_patch+=pow((y_patch.at(t)-m_y_patch),2);
}
pixel(0)=i;
pixel(1)=j;

sigma(0,0)=std_x_patch;
sigma(0,1)=0;
sigma(1,0)=0;
sigma(1,1)=std_y_patch;

/*
for(anotate=0;anotate<numberof_annot;anotate++)
N=N+(1/(2*pi*sigma))*exp(pow(pixel-P,2)/(2*pi*sigma^2))
*/


//}
MatrixXd N(imgMat.rows,imgMat.cols);
VectorXd P(numberof_annot);
float sigma_1=5.2;
float pixel_luminance;
for(i=0;i<imgMat.rows;i++)
	for(j=0;j<imgMat.cols;j++){
pixel_luminance=imgMat.at<float>(i,j);
for(anotate=0;anotate<numberof_annot;anotate++)
N(i,j)=N(i,j)+(1/(2*pi*sigma_1))*exp(pow(pixel_luminance-P(anotate),2)/(2*pi*sigma_1*sigma_1));
}
}


void onMouse( int event, int x, int y, int, void* )
{
    if( event != CV_EVENT_LBUTTONDOWN )
            return;
    Point pt = Point(x,y);
 //   std::cout<<"x="<<pt.x<<"\t y="<<pt.y<<"\t value="<<thresh.at<uchar>(x,y)<<"\n";
    annotation<<pt.x<<" "<<pt.y<<endl;
    anot_x.push_back(pt.x);
    anot_y.push_back(pt.y);

}

MatrixXd Density::readAnnotations(){
	int numberof_annot;
	MatrixXd annot_loc(numberof_annot,2);
	ifstream myfile ("file.txt");
	stringstream ss;
	string s;
	int j=0;
	string line;
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) && j++<numberof_annot)
	    {
ss<<line;
for(int col=0;col<2;col++){
getline( ss,s,' ');
cout<<atoi(s.c_str());
annot_loc(j,col)=atoi(s.c_str());
cout<<annot_loc(j,col);
ss<<"";
}
	    }
	    myfile.close();
	  }

return annot_loc;
}


}
