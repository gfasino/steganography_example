#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
typedef unsigned char byte;

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 3)
    {
     cout <<" Usage: display_image image1 image2" << endl;
     return -1;
    }

    Mat image, image2;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file
    image2= imread(argv[2], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(!image.data || !image2.data)
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

	int shift = 2;
	int oppsh = 8-shift;

	auto win = "Window ";
	//assume images have same resolution

	int size = image.total() * image.elemSize();
	for (int i=0;i<size;i++)
	{
		//clear first image
		//cout<<(int)image.data[i]<<"X\n";
		byte _byt = image.data[i];
		byte _byt2= image2.data[i];
		_byt = _byt>>shift;
		_byt = _byt<<shift;
		_byt2= _byt2>>oppsh;
	
		image.data[i]=_byt+_byt2;
		//cout<<(int)image.data[i]<<"X\n";
	}

	int x=0;
	auto winName = win + std::to_string(x);
	namedWindow( winName, WINDOW_AUTOSIZE );// Create a window for display.
	imshow( winName, image);                   // Show our image inside it.
	waitKey(0);                                          // Wait for a keystroke in the window

	//write result
	imwrite("out.png", image);
    return 0;
}
