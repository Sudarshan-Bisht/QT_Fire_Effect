#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../build/ui_mainwindow.h"
#include "color.h"

namespace Ui {
class MainWindow;
}

constexpr int WIDTH = 600;
constexpr int HEIGHT = 200;

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
    void UpdateUI ();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *graphicsScene;
    QImage image;

    Color *colorInfo;
   
    int colorSelected;
    int intensitySelected;
    int intensityRange;
    int intensityValues[WIDTH][HEIGHT];
    std::map<int, int> intensityToColor;

    int windDirection;

    void InitUI ();
    void InitIntensity ();
    void StartTimer ();
    void SetBaseIntensityValues ();
    int GetIntensityValue ( int row, int col );
 };

#endif // MAINWINDOW_H
