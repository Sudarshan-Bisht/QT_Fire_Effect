#include "intensity.h"
#include "color.h"


Intensity::Intensity (int colorSelected , int intensitySelected, int  intensityRange, int windDirection )
{
    colorInfo = new Color ();

    m_colorSelected = colorSelected;
    m_intensitySelected = intensitySelected;
    m_intensityRange = intensityRange;
    m_windDirection = windDirection;

    InitIntensity ();
}

void Intensity::InitIntensity ()
{
    for ( int i = 0; i < m_intensityRange; i++ )
    {
        if ( m_colorSelected == COLOR_THEME::RANDOM )
        {
            intensityToColor[i] = colorInfo->GetRandomColor ( i / m_intensitySelected );
        }
        else if ( m_colorSelected == COLOR_THEME::BLUE )
        {
            intensityToColor[i] = colorInfo->GetBlueColor ( i / m_intensitySelected );
        }
        else
        {
            intensityToColor[i] = colorInfo->GetRedColor ( i / m_intensitySelected );
        }
    }
}

void Intensity::SetBaseIntensityValues ()
{
    // Initialize last row intensity values. Later used to calculate rest of the intensity valyes.
    for ( int row = WIDTH - 1; row >= 0; --row )
    {
        for ( int col = HEIGHT - 1; col >= 0; --col )
        {
            if ( col == ( HEIGHT - 1 ) ) // Last row intensity values are hardcoded.
            {
                if ( m_windDirection == WIND_DIRECTION::LEFT )
                {
                    if ( row < WIDTH / 3 )
                    {
                        intensityValues[row][col] = ( std::rand () % ( m_intensityRange / 2 ) );
                    }
                    else if ( ( row >= WIDTH / 3 ) && ( row <= ( WIDTH * 2 ) / 3 ) )
                    {
                        intensityValues[row][col] = ( std::rand () % ( m_intensityRange * 2 / 3 ) );
                    }
                    else
                    {
                        intensityValues[row][col] = ( std::rand () % m_intensityRange );
                    }
                }
                else if ( m_windDirection == WIND_DIRECTION::RIGHT )
                {
                    if ( row < WIDTH / 3 )
                    {
                        intensityValues[row][col] = ( std::rand () % ( m_intensityRange ) );
                    }
                    else if ( ( row >= WIDTH / 3 ) && ( row <= ( WIDTH * 2 ) / 3 ) )
                    {
                        intensityValues[row][col] = ( std::rand () % ( m_intensityRange * 2 / 3 ) );
                    }
                    else
                    {
                        intensityValues[row][col] = ( std::rand () % ( m_intensityRange / 2 ) );
                    }
                }
                else
                {
                    intensityValues[row][col] = ( std::rand () % m_intensityRange );
                }
            }
        }
    }
}

int Intensity::GetIntensityValuePerPixel ( int i, int j )
{
    int retval = 0;

    if ( j == ( HEIGHT - 1 ) )
    {
        retval = intensityValues[i][j];
    }
    else
    {
        if ( i == ( WIDTH - 1 ) )
        {
            retval = ( ( intensityValues[i][j + 1] + intensityValues[i - 1][j + 1] ) / 3 ) - 1;
        }
        else if ( i == 0 )
        {
            retval = ( ( intensityValues[i][j + 1] + intensityValues[i + 1][j + 1] ) / 3 ) - 1;
        }
        else
        {
            retval = ( ( intensityValues[i][j + 1] + intensityValues[i + 1][j + 1] + intensityValues[i - 1][j + 1] ) / 3 ) - 1;
        }
    }

    intensityValues[i][j] = retval;

    return retval;
}

int Intensity::GetRChannel ( int intensity )
{
    return ( intensityToColor[intensity] >> 16 ) & ( 0x0000FF );
}

int Intensity::GetGChannel ( int intensity )
{
    return ( intensityToColor[intensity] >> 8 ) & ( 0x000000FF );
}

int Intensity::GetBChannel ( int intensity )
{
    return ( intensityToColor[intensity] ) & ( 0x000000FF );
}

void Intensity::UpdateColor ( int color )
{
    m_colorSelected = color;
    InitIntensity ();
}

void Intensity::UpdateIntensity ( int intensitySelected, int intensityRange )
{
    m_intensitySelected = intensitySelected;
    m_intensityRange = intensityRange;
}

void Intensity::UpdateWindDirection ( int windDirection )
{
    m_windDirection = windDirection;
}

Intensity::~Intensity ()
{
    delete colorInfo;
}