#include "Color.h"

Color::Color()
{
    InitRedColor ();
    InitBlueColor ();
    InitRandomColor ();
}

void Color::InitRedColor ()
{
    // Red Color Gradients
    redColor.push_back ( 0x00000000 );
    redColor.push_back ( 0x00120000 );
    redColor.push_back ( 0x003A0002 );
    redColor.push_back ( 0x005A0004 );
    redColor.push_back ( 0x00790001 );
    redColor.push_back ( 0x009A0000 );
    redColor.push_back ( 0x00BB0000 );
    redColor.push_back ( 0x00DD0000 );
    redColor.push_back ( 0x00FF0000 );
    redColor.push_back ( 0x00FF1919 );
    redColor.push_back ( 0x00FF3333 );
    redColor.push_back ( 0x00FF3E20 );
    redColor.push_back ( 0x00FF4D4D );
    redColor.push_back ( 0x00FF603B );
    redColor.push_back ( 0x00FF6666 );
    redColor.push_back ( 0x00FF8054 );
    redColor.push_back ( 0x00FF8080 );
    redColor.push_back ( 0x00FF9999 );
    redColor.push_back ( 0x00FF9E6E );
    redColor.push_back ( 0x00FFB3B3 );
    redColor.push_back ( 0x00FFBD89 );
    redColor.push_back ( 0x00FFCCCC );
    redColor.push_back ( 0x00FFDBA4 );
    redColor.push_back ( 0x00FFE6E6 );
    redColor.push_back ( 0x00FFFABF );
    redColor.push_back ( 0x00FFFFDC );
    redColor.push_back ( 0x00FFFFF9 );
 }

void Color::InitBlueColor ()
{
    // Blue Color Gradients
    blueColor.push_back ( 0x00000112 );
    blueColor.push_back ( 0x00000328 );
    blueColor.push_back ( 0x0000073F );
    blueColor.push_back ( 0x00000C58 );
    blueColor.push_back ( 0x00001271 );
    blueColor.push_back ( 0x0000008C );
    blueColor.push_back ( 0x000000A8 );
    blueColor.push_back ( 0x000000C4 );
    blueColor.push_back ( 0x000000E1 );
    blueColor.push_back ( 0x000000FF );
    blueColor.push_back ( 0x001919FF );
    blueColor.push_back ( 0x003333FF );
    blueColor.push_back ( 0x004D4DFF );
    blueColor.push_back ( 0x00502AFF );
    blueColor.push_back ( 0x006666FF );
    blueColor.push_back ( 0x007947FF );
    blueColor.push_back ( 0x008080FF );
    blueColor.push_back ( 0x009D63FF );
    blueColor.push_back ( 0x009999FF );
    blueColor.push_back ( 0x00B3B3FF );
    blueColor.push_back ( 0x00BF7FFF );
    blueColor.push_back ( 0x00CCCCFF );
    blueColor.push_back ( 0x00E19AFF );
    blueColor.push_back ( 0x00E6E6FF );
    blueColor.push_back ( 0x00FFB7FF );
    blueColor.push_back ( 0x00FFD3FF );
    blueColor.push_back ( 0x00FFF1FF );
}

void Color::InitRandomColor ()
{
    // Random Color Gradients
    unsigned int color = 0x00000000;
    for ( int i = 0; i < GRADIENT_RANGE; ++i )
    {
        randomColor.push_back ( color );
        color += COLOR_FACTOR;
    }
}

unsigned int Color::GetRedColor ( int index )
{
    return redColor.at ( index );
}

unsigned int Color::GetBlueColor ( int index )
{
    return blueColor.at ( index );
}

unsigned int Color::GetRandomColor ( int index )
{
    return randomColor.at ( index );
}

Color::~Color ()
{
    redColor.clear ();
}