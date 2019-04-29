#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;

using namespace cv;



int getVal(char *buffer,int pos)
{
	return *reinterpret_cast<uint32_t *>(&buffer[pos]);
}

int getValImg(char *buffer,int pos)
{
	return int(*reinterpret_cast<uint32_t *>(&buffer[pos]));	
}


void readBMP(const string &file)
{
    static constexpr size_t headerSize = 54;

    ifstream bmp(file, ios::binary);

	char buffer[headerSize];
	bmp.read(buffer,headerSize);	


    int fileSize=getVal(buffer,2);
    int dataOffset=getVal(buffer,10); 
    int width=getVal(buffer,18); 
    int height=getVal(buffer,22);
    int depth=getVal(buffer,28);  

	//---------------------------
	cout<<"Profundidad:\t"<<depth<<endl;
	cout<<"Data Offset:\t"<<dataOffset<<endl;     
	cout<<"Width:\t\t"<<width<<endl;
	cout<<"Height:\t\t"<<height<<endl;
	cout<<"File Size :\t"<<fileSize<<endl;
	
	//---------------------------
	
	int sizeMatrix=width*height*3;
	
	char img[sizeMatrix];
	char imgRes[sizeMatrix];
    bmp.read(img, sizeMatrix);

    for(int i = 0; i < height; i ++)
      for(int j = 0; j < width * 3; j ++)
	      imgRes[i * width * 3 + j] = img[(height - 1 - i) * width * 3 + j];	
      
      	
	Mat imgMat(height, width, CV_8UC3, imgRes);
    imshow("My Image", imgMat);
    waitKey(0);

}




void readBMP_8(const string & filename)
{
    static constexpr size_t headerSize = 54;

    ifstream bmp(filename, ios::binary);

	char buffer[headerSize];
	bmp.read(buffer,headerSize);	

	int fileSize=getVal(buffer,2);
    int dataOffset=getVal(buffer,10); 
    int width=getVal(buffer,18); 
    int height=getVal(buffer,22);
    int depth=getVal(buffer,28);  

    

	cout<<"Profundidad:\t"<<depth<<endl;
	cout<<"Data Offset:\t"<<dataOffset<<endl;     
	cout<<"Width:\t\t"<<width<<endl;
	cout<<"Height:\t\t"<<height<<endl;
	cout<<"File Size :\t"<<fileSize<<endl;

	int sizeMatrix=width*height;
	
	char img[sizeMatrix];
	char imgRes[sizeMatrix*3];
    bmp.read(img, sizeMatrix);

    for(int i = 0; i < height; i ++)
    {
		for(int j = 0; j < width * 3; j ++)
		{
			int red, green, blue;
			
			int Color = (int)img[(height - 1 - i) * width + j];

			red   = (int)(Color >> 5) * 255 / 7;
			green = (int)((Color >> 2) & 0x07) * 255 / 7;
			blue  = (int)(Color & 0x03) * 255 / 5;

			imgRes[i * width * 3 + (j * 3)] = (uchar)blue;
			imgRes[i * width * 3 + (j * 3) + 1] = (uchar)green;
			imgRes[i * width * 3 + (j * 3) + 2] = (uchar)red;
		}
    }
	Mat imgMat(height, width, CV_8UC3, imgRes);
    imshow("My Image", imgMat);
    waitKey(0);
    
}




int main( int argc, char** argv )
{

	readBMP_8("Lion_8.bmp");

    return 0;
}

