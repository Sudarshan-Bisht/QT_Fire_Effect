#ifndef OPENCV_H
#define OPENCV_H

#include <QImage>

enum OPENEV_EFFECT { NO_EFFECT, BLUR, FLIP };

class OpenCV 
{

public:
    OpenCV ();
    ~OpenCV ();

    void CheckEffect ( QImage& image );
    void UpdateEffect ( int effect );

private:
    int m_openCVEffect;

    int rotateStep;
    void Blur ( QImage& image );
    void Flip ( QImage& image );
    void NoEffect ( QImage& image );

 };

#endif // OPENCV_H
