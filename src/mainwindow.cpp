#include "mainwindow.h"
#include "color.h"
#include "../build/ui_mainwindow.h"
#include <QTimer>

enum WIND_DIRECTION { NO_WIND, LEFT, RIGHT };

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitUI ();

    colorInfo = new Color ();

    colorSelected = COLOR_THEME::RED;

    intensitySelected = GRAD_TO_INTENSITY;
    intensityRange = INTENSITY_RANGE;

    windDirection = WIND_DIRECTION::NO_WIND;

    InitIntensity ();
    
    StartTimer ();
}

void MainWindow::InitUI ()
{
    graphicsScene = new QGraphicsScene ( this );

    ui->graphicsView->setScene ( graphicsScene );

    image = QImage ( WIDTH, HEIGHT, QImage::Format_RGB32 );
}

void MainWindow::InitIntensity ()
{
    for ( int i = 0; i < intensityRange; i++ )
    {
        if ( colorSelected == COLOR_THEME::RANDOM )
        {
            intensityToColor[i] = colorInfo->GetRandomColor ( i / intensitySelected );
        }
        else if ( colorSelected == COLOR_THEME::BLUE )
        {
            intensityToColor[i] = colorInfo->GetBlueColor ( i / intensitySelected );
        }
        else
        {
            intensityToColor[i] = colorInfo->GetRedColor ( i / intensitySelected );
        }
    }
}

void MainWindow::StartTimer ()
{
    QTimer *timer = new QTimer ( this );

    connect ( timer, SIGNAL ( timeout () ), this, SLOT ( UpdateUI () ) );

    timer->start ();
}

void MainWindow::UpdateUI ()
{
    SetBaseIntensityValues ();

    // Set pixel value
    for ( int row = WIDTH - 1;  row >= 0; --row )
    {
        for ( int col = HEIGHT - 1; col >= 0; --col )
        {
            int intensity = GetIntensityValue ( row, col );

            int r = ( intensityToColor[intensity] >> 16 ) & ( 0x0000FF );
            int g = ( intensityToColor[intensity] >> 8 ) & ( 0x000000FF );
            int b = ( intensityToColor[intensity] ) & ( 0x000000FF );
   
            image.setPixel ( row, col, qRgb ( r, g, b ) );
        }
    }

    graphicsScene->addPixmap (  QPixmap::fromImage (image ));
}

void MainWindow::SetBaseIntensityValues ()
{
    // Initialize last row intensity values. Later used to calculate rest of the intensity valyes.
    for ( int row = WIDTH - 1; row >= 0; --row )
    {
        for ( int col = HEIGHT - 1; col >= 0; --col )
        {
            if ( col == ( HEIGHT - 1 ) ) // Last row intensity values are hardcoded.
            {
                if ( windDirection == WIND_DIRECTION::LEFT )
                {
                    if ( row < WIDTH / 3 )
                    {
                        intensityValues[row][col] = ( std::rand () % ( intensityRange/2 ) );
                    }
                    else if ( ( row >= WIDTH / 3) && ( row <= ( WIDTH * 2 ) / 3 ))
                    {
                        intensityValues[row][col] = ( std::rand () % (intensityRange * 2 /3) );
                    }
                    else
                    {
                        intensityValues[row][col] = ( std::rand () % intensityRange );
                    }
                }
                else if ( windDirection == WIND_DIRECTION::RIGHT )
                {
                    if ( row < WIDTH / 3 )
                    {
                        intensityValues[row][col] = ( std::rand () % ( intensityRange ) );
                    }
                    else if ( ( row >= WIDTH / 3 ) && ( row <= ( WIDTH * 2 ) / 3 ) )
                    {
                        intensityValues[row][col] = ( std::rand () % ( intensityRange * 2 / 3 ) );
                    }
                    else
                    {
                        intensityValues[row][col] = ( std::rand () % ( intensityRange / 2 ) );
                    }
                }
                else
                {
                    intensityValues[row][col] = ( std::rand () % intensityRange );
                }
            }
        }
    }
}

int MainWindow::GetIntensityValue (int i, int j)
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

void MainWindow::redClicked ()
{
    colorSelected = COLOR_THEME::RED;

    InitIntensity ();
}

void MainWindow::blueClicked ()
{
    colorSelected = COLOR_THEME::BLUE;

    InitIntensity ();
}

void MainWindow::randomClicked ()
{
    colorSelected = COLOR_THEME::RANDOM;

    InitIntensity ();
}

void MainWindow::sliderMoved ( int value )
{
    intensitySelected = value;

    intensityRange = intensitySelected * GRADIENT_RANGE;

    InitIntensity ();
}

void MainWindow::noWind ()
{
    windDirection = WIND_DIRECTION::NO_WIND;
}

void MainWindow::leftWind ()
{
    windDirection = WIND_DIRECTION::LEFT;
}

void MainWindow::rightWind ()
{
    windDirection = WIND_DIRECTION::RIGHT;
}

MainWindow::~MainWindow()
{
    delete graphicsScene;

    delete ui;

    delete colorInfo;
}
