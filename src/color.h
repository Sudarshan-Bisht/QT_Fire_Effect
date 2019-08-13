#ifndef COLOR_H
#define COLOR_H


#include<vector>

constexpr int GRADIENT_RANGE = 27;
constexpr int GRAD_TO_INTENSITY = 10;
constexpr int INTENSITY_RANGE = GRAD_TO_INTENSITY * GRADIENT_RANGE;

constexpr int COLOR_FACTOR = ( 0x00FFFFFF / ( INTENSITY_RANGE - 1 ) );

enum COLOR_THEME { RED, BLUE, RANDOM };

class Color 
{

public:
    Color();
    ~Color();

    unsigned int GetRedColor ( int index );
    unsigned int GetBlueColor ( int index );
    unsigned int GetRandomColor ( int index );

private:
    std::vector<unsigned int> redColor;
    std::vector<unsigned int> blueColor;
    std::vector<unsigned int> randomColor;

    void InitRedColor ();
    void InitBlueColor ();
    void InitRandomColor ();
 };

#endif // COLOR_H
