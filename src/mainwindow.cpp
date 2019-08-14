#include "mainwindow.h"
#include "color.h"
#include "intensity.h"
#include "openCV.h"
#include "../build/ui_mainwindow.h"
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitView ();

    colorSelected = COLOR_THEME::RED;
    intensitySelected = GRAD_TO_INTENSITY;
    intensityRange = INTENSITY_RANGE;
    windDirection = WIND_DIRECTION::NO_WIND;

    intensityInfo = new Intensity ( colorSelected, intensitySelected, intensityRange, windDirection );
    
    openCV = new OpenCV ();

    StartTimer ();
}

MainWindow::~MainWindow ()
{
    delete ui;

    delete graphicsScene;

    delete intensityInfo;

    delete openCV;
}


#pragma region View

void MainWindow::InitView ()
{
    graphicsScene = new QGraphicsScene ( this );

    ui->graphicsView->setScene ( graphicsScene );

    image = QImage ( WIDTH, HEIGHT, QImage::Format_RGB32 );
}

void MainWindow::UpdateView ()
{
    intensityInfo->SetBaseIntensityValues ();

    // Set pixel value
    for ( int row = WIDTH - 1; row >= 0; --row )
    {
        for ( int col = HEIGHT - 1; col >= 0; --col )
        {
            int intensity = intensityInfo->GetIntensityValuePerPixel ( row, col );

            int r = intensityInfo->GetRChannel ( intensity );
            int g = intensityInfo->GetGChannel ( intensity );
            int b = intensityInfo->GetBChannel ( intensity );

            image.setPixel ( row, col, qRgb ( r, g, b ) );
        }
    }

    graphicsScene->addPixmap ( QPixmap::fromImage ( image ) );
}

#pragma endregion


void MainWindow::StartTimer ()
{
    QTimer *timer = new QTimer ( this );

    connect ( timer, SIGNAL ( timeout () ), this, SLOT ( UpdateView () ) );

    timer->start ();
}


#pragma region SLOTS

void MainWindow::redClicked ()
{
    colorSelected = COLOR_THEME::RED;

    intensityInfo->UpdateColor ( colorSelected );
}

void MainWindow::blueClicked ()
{
    colorSelected = COLOR_THEME::BLUE;

    intensityInfo->UpdateColor ( colorSelected );
}

void MainWindow::randomClicked ()
{
    colorSelected = COLOR_THEME::RANDOM;

    intensityInfo->UpdateColor ( colorSelected );
}

void MainWindow::sliderMoved ( int value )
{
    intensitySelected = value;

    intensityRange = intensitySelected * GRADIENT_RANGE;

    intensityInfo->UpdateIntensity ( intensitySelected, intensityRange );
}

void MainWindow::noWind ()
{
    windDirection = WIND_DIRECTION::NO_WIND;

    intensityInfo->UpdateWindDirection ( windDirection );
}

void MainWindow::leftWind ()
{
    windDirection = WIND_DIRECTION::LEFT;
    intensityInfo->UpdateWindDirection ( windDirection );
}

void MainWindow::rightWind ()
{
    windDirection = WIND_DIRECTION::RIGHT;
    intensityInfo->UpdateWindDirection ( windDirection );
}

void MainWindow::openCVNoEffect ()
{
}

void MainWindow::openCVEffect1 ()
{
    openCV->Effect1 ();
}

void MainWindow::openCVEffect2 ()
{
}

#pragma endregion
