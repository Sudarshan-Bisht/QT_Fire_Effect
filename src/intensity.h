#ifndef INTENSITY_H
#define INTENSITY_H

#include <map>
#include "color.h"

enum WIND_DIRECTION { NO_WIND, LEFT, RIGHT };

class Intensity
{

public:
    Intensity ( int colorSelected, int intensitySelected, int  intensityRange, int windDirection );
    ~Intensity ();

    void InitIntensity ();

    void SetBaseIntensityValues ();
    int GetIntensityValuePerPixel ( int i, int j );

    int GetRChannel ( int intensity );
    int GetGChannel ( int intensity );
    int GetBChannel ( int intensity );

    void UpdateColor ( int color );
    void UpdateWindDirection ( int windDirection );
    void UpdateIntensity ( int intensitySelected, int intensityRange );

private:
    Color *colorInfo;

    int m_colorSelected;
    int m_intensitySelected;
    int m_intensityRange;
    int m_windDirection;
    std::map<int, int> intensityToColor;
    int intensityValues[WIDTH][HEIGHT];
 };

#endif // INTENSITY_H
