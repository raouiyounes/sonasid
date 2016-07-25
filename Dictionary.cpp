/*
 * Dictionary.cpp
 *
 *  Created on: 3 mars 2016
 *      Author: younes
 */

#include "Dictionary.h"
#include <vector>
#include <iostream>
#define ROWS 10
#define COLS 65
using namespace std;
typedef vector<std::vector<double> > struct1;


Dictionary::Dictionary(int nb_rows,int nb_view) {
	number_of_view=nb_view;
	// TODO Auto-generated constructor stub
vector<float> mean_tab,std_tab;
Mat points(nb_rows*number_of_view,2, CV_32FC2);
int i,j;
k_db=0;
for(i=0;i<number_of_view;i++){
	this->image_str="str.jpg";
	this->SURFExtractor();
	std_tab=this->standart_deviation();
	mean_tab=this->compute_mean();
	for(j=0;j<mean_tab.size();j++){
points.at<double>(k_db,0)=std_tab.at(j);
points.at<double>(k_db,1)=mean_tab.at(j);
k_db++;

	}
}
points_db=points;
}


int Dictionary::clusterKmean(){

const int MAX_CLUSTERS = 5;
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
clusterCount = MIN(clusterCount, sampleCount);
Mat centers;



/* generate random sample from multigaussian distribution */
for( k = 0; k < clusterCount; k++ )
{
Point center;
center.x = rng.uniform(0, img.cols);
center.y = rng.uniform(0, img.rows);
}

kmeans(points_db, clusterCount, labels,
TermCriteria( TermCriteria::EPS+TermCriteria::COUNT, 10, 1.0),
3, KMEANS_PP_CENTERS, centers);

img = Scalar::all(0);

cout<<"zzzzzzzzzzzzzzzds"<< this->k_db;
for( i = 0; i < this->k_db; i++ )
{
int clusterIdx = labels.at<int>(i);
//cout<<clusterIdx<<"\n";
//Point ipt = points.at<Point2f>(i);
}
return 0;
}








/*
Dictionary::Dictionary(Dictionary &ob){




}
*/


Dictionary::~Dictionary() {
	// TODO Auto-generated destructor stub
}





vector<IplImage*> Dictionary::load_image_db(){
       IplImage *im;
       vector<IplImage*> ims;
       int i;
       char buffer[20];
       for (i=1;i<16;i++)
       {
           sprintf(buffer,  "rooms/im%d.png",i);
           im=cvLoadImage(buffer,1);
           ims.push_back(im);
       }
       return ims;
   }





