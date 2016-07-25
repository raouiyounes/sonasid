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


using namespace cv;
using namespace std;
typedef vector<std::vector<double> > struct1;
namespace sonasid{


class Circles{
  IplImage *image_matrix;
struct1 descriptor_vect;
public: 
  int  number_of_line;
  Circles(char *image_path){
    image_matrix=cvLoadImage(image_path);


  }
public:
int SURFExtractor(int nb_of_features){
namedWindow( "Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE );
cvShowImage( "Hough Circnb_of_featuresle Transform Demo",  image_matrix );
  cvWaitKey(0);
	//  Mat img_1 = image_data;
	 	  //-- Step 1: Detect the keypoints using SURF Detector
	  int minHessian = 400;
	 SURF detector( minHessian );
	 	   int Threshl=40;
	   int Octaves=2;
	   float PatternScales=1.0f;
	  CvMat* prevgray = 0, *image = 0, *gray =0;
//IplImage* image_matrix=cvLoadImage("test_image.jpg");
image = cvCreateMat(image_matrix->height, image_matrix->width, CV_8UC1);
	  CvMemStorage* storage = cvCreateMemStorage(0);
	  cvCvtColor(image_matrix, image, CV_BGR2GRAY);
	  //Define sequence for storing surf keypoints and descriptors
	  CvSeq *imageKeypoints = 0, *imageDescriptors = 0;
	  int i,j;
	  ofstream file("surf.txt");
vector<double> descriptor_row;
	  CvSURFParams params = cvSURFParams(500, 1);
	  cvExtractSURF( image, 0, &imageKeypoints, &imageDescriptors, storage, params );
	  for( i = 0; i < imageDescriptors->total; i++ )
	  {
	float* r = (float*)cvGetSeqElem( imageDescriptors, i);
	j=0;
int dim=50;

//cout<<nb_of_features;
	// changer dim pour obtenir plus de features
	while(j<nb_of_features){
	  	  descriptor_row.push_back(*r);
	  r++;
	  	j++;
	file<<*r<<" ";
	}
	file<<"\n";
	descriptor_vect.push_back(descriptor_row);
	number_of_line++;
	descriptor_row.clear();
     }
  return 0;
}

  int extractBrisc(char *str)
  {

    Mat img;
    img=imread(str);
    IplImage* image=cvLoadImage(str);
      int i;
      CvMat *image1=0;
         ofstream outputFile("surf_db.txt");
       static CvScalar red_color[] ={0,0,255};
          image1 = cvCreateMat(image->height, image->width, CV_8UC1);
          cvCvtColor(image, image1, CV_BGR2GRAY);
          CvSURFParams params;
          std::vector<cv::KeyPoint> keypointsA;
          cv::Mat descriptorsA;
          int Threshl=40;
          int Octaves=2;
          float PatternScales=1.0f;
          cv::BRISK  BRISKD(Threshl,Octaves,PatternScales);//initialize algoritm
          BRISKD.create("Feature2D.BRISK");
          BRISKD.detect(image1, keypointsA);
          BRISKD.compute(image1, keypointsA,descriptorsA);
          cv::Ptr<cv::FeatureDetector> detector = cv::Algorithm::create<cv::FeatureDetector>("Feature2D.BRISK");
          detector->detect(image1, keypointsA);
          cv::Ptr<cv::DescriptorExtractor> descriptorExtractor =cv::Algorithm::create<cv::DescriptorExtractor>("Feature2D.BRISK");
          descriptorExtractor->compute(image1, keypointsA, descriptorsA);

          for(int i=0;i<keypointsA.size();i++){
        outputFile<<keypointsA[i].pt.x<<" "<<keypointsA[i].pt.y<<" ";
         outputFile<<descriptorsA.row(i)<<"\n";
      }


for( size_t i = 0; i <keypointsA.size(); i++ )
  {
      Point center(cvRound(keypointsA[i].pt.x), cvRound(keypointsA[i].pt.y));
     
      // circle center
      circle( img, center, 3, Scalar(0,255,0), -1, 8, 0 );
      // circle outline
      }

  namedWindow( "Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE );
  imshow( "Hough Cirimage_matrixcle Transform Demo", img );


outputFile <<"\n";
  }







};


}
  using namespace sonasid;
int main(){
    string str="imageDb/im6.JPG";
  char *ss;
   ss = (char*)str.c_str();
Circles *obj_sona=new Circles(ss);
  obj_sona->number_of_line=0;
   obj_sona->SURFExtractor(20);
 //  obj_sona->extractBrisc(ss);

  return 0;
} 

