#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "openCV.h"
#include <QImage>

OpenCV::OpenCV ()
{
    m_openCVEffect = OPENEV_EFFECT::NO_EFFECT;
}

void OpenCV::CheckEffect (QImage& image)
{
    if ( m_openCVEffect == OPENEV_EFFECT::GRAYSCALE )
    {
        Grayscale ( image );
    }
    else if ( m_openCVEffect == OPENEV_EFFECT::FLIP )
    {
        Flip ( image );
    }
    else
    {
        NoEffect ( image );
    }
}

void OpenCV::UpdateEffect ( int effect )
{
    m_openCVEffect = effect;

    rotateStep = 0;
}

void OpenCV::Grayscale ( QImage& src )
{
    cv::Mat res ( src.height (), src.width (), CV_8UC4, ( uchar* ) src.bits (), src.bytesPerLine () );
      
    src = QImage ( ( uchar* ) res.data, res.cols, res.rows, QImage::Format_Grayscale8 );
}

void OpenCV::Flip ( QImage& src )
{
    cv::Mat res ( src.height (), src.width (), CV_8UC4, ( uchar* ) src.bits (), src.bytesPerLine () );

    cv::flip ( res, res, 0 );

    src = QImage ( ( uchar* ) res.data, res.cols, res.rows, QImage::Format_ARGB32 );
}

void OpenCV::NoEffect ( QImage& src )
{
    cv::Mat res ( src.height (), src.width (), CV_8UC4, ( uchar* ) src.bits (), src.bytesPerLine () );

    src = QImage ( ( uchar* ) res.data, res.cols, res.rows, QImage::Format_ARGB32 );
}

OpenCV::~OpenCV ()
{

}