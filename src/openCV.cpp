#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "openCV.h"

OpenCV::OpenCV ()
{

}

void OpenCV::Effect1 ()
{
    cv::Mat image;
    //image = cv::imread ( "test.jpeg", CV_LOAD_IMAGE_COLOR );   // Read the file

    if ( image.data != nullptr )
    {
        cv::namedWindow ( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.
        imshow ( "Display window", image );                   // Show our image inside it.

        cv::waitKey ( 0 );
    }
}

OpenCV::~OpenCV ()
{

}