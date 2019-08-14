#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../build/ui_mainwindow.h"
#include "color.h"
#include "intensity.h"
#include "openCV.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void redClicked ();
    void blueClicked ();
    void randomClicked ();
    void noWind ();
    void leftWind ();
    void rightWind ();
    void sliderMoved ( int value );
    void openCVNoEffect ();
    void openCVGrayscale ();
    void openCVFlip ();
    void UpdateView ();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *graphicsScene;
    QImage image;

    Intensity *intensityInfo;
    
    OpenCV *openCV;

    int colorSelected;
    int intensitySelected;
    int intensityRange;
    int windDirection;
    int openCVEffect;

    void InitView ();
    void StartTimer ();
 };

#endif // MAINWINDOW_H
