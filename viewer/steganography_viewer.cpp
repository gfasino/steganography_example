#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
typedef unsigned char byte;

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

	auto win = "Window ";

	for(char x=0;x<8;x+=1){
		int size = image.total() * image.elemSize();
		for (int i=0;i<size;i++)
			image.data[i]=image.data[i]<<(x!=0);
		
		auto winName = win + std::to_string(x);
		namedWindow( winName, WINDOW_AUTOSIZE );// Create a window for display.
		imshow( winName, image );                   // Show our image inside it.
		waitKey(0);                                          // Wait for a keystroke in the window
	}
    return 0;
}
