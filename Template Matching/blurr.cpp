#include <iostream>
#include <stdio.h>

#include <cv.h>
#include <highgui.h>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;

const float minVal = 0;
const float maxVal = 19935;

float normalize(int input)
{    

    return (input - minVal) / (maxVal - minVal);
}


int main( int argc, char** argv )
{	
	string imageName = "faceForTM.jpg";
	
	Mat image, gray_image,blur;
	image = imread( imageName, 1 );
	
	cvtColor( image, gray_image, CV_BGR2GRAY );
    GaussianBlur(image,blur,Size(5,5),10.0); 


	namedWindow( imageName, CV_WINDOW_AUTOSIZE );
	namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

	imshow( imageName, image );
	imshow( "Gray image", blur );
	
	imwrite("BlurryFace_1.jpg",blur);
	
/*
	namedWindow( imageName, CV_WINDOW_AUTOSIZE );
	namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

	imshow( imageName, image );
	imshow( "Gray image", gray_image );
*/
	waitKey(0);

	return 0;
}






