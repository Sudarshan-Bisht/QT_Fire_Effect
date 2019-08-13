#include "mainwindow.h"
#include "color.h"
#include "../build/ui_mainwindow.h"
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitUI ();

    colorInfo = new Color ();

    colorSelected = COLOR_THEME::RED;

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
    for ( int i = 0; i < INTENSITY_RANGE; i++ )
    {
        if ( colorSelected == COLOR_THEME::RANDOM )
        {
            intensityToColor[i] = colorInfo->GetRandomColor ( i / GRAD_TO_INTENSITY );
        }
        else if ( colorSelected == COLOR_THEME::BLUE )
        {
            intensityToColor[i] = colorInfo->GetBlueColor ( i / GRAD_TO_INTENSITY );
        }
        else
        {
            intensityToColor[i] = colorInfo->GetRedColor ( i / GRAD_TO_INTENSITY );
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
    // Initialize last row intensity values. Later used to calculate rest of the intensity valyes.
    for ( int row = WIDTH - 1; row >= 0; --row )
    {
        for ( int col = HEIGHT - 1; col >= 0; --col )
        {
            if ( col == ( HEIGHT - 1 ) ) // Last row intensity values are hardcoded.
            {
                intensityValues[row][col] = ( std::rand () % INTENSITY_RANGE );
            }
        }
    }

    // Set pixel value
    for ( int row = WIDTH - 1;  row >= 0; --row )
    {
        for ( int col = HEIGHT - 1; col >= 0; --col )
        {
            int intensity = GetIntensity ( row, col );

            int r = ( intensityToColor[intensity] >> 16 ) & ( 0x0000FF );
            int g = ( intensityToColor[intensity] >> 8 ) & ( 0x000000FF );
            int b = ( intensityToColor[intensity] ) & ( 0x000000FF );
   
            image.setPixel ( row, col, qRgb ( r, g, b ) );
        }
    }

    graphicsScene->addPixmap (  QPixmap::fromImage (image ));
}


int MainWindow::GetIntensity (int i, int j)
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
            retval = ( ( intensityValues[i][j+1] + intensityValues[i -1][j+1] ) / 3 ) - 1;
        }
        else if ( i == 0 )
        {
            retval = ( ( intensityValues[i][j+1] + intensityValues[i + 1][j + 1] ) / 3 ) - 1;
        }
        else
        {
            retval = ( ( intensityValues[i][j+1] + intensityValues[i + 1][j + 1] + intensityValues[i - 1][j + 1] ) / 3 ) - 1;
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

MainWindow::~MainWindow()
{
    delete graphicsScene;

    delete ui;

    delete colorInfo;
}

