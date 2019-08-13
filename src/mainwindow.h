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
    void UpdateUI ();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *graphicsScene;
    QImage image;

    Color *colorInfo;
   
    int colorSelected;
    int intensityValues[WIDTH][HEIGHT];
    std::map<int, int> intensityToColor;

    void InitUI ();
    void InitIntensity ();
    void StartTimer ();
    int GetIntensity ( int row, int col );
 };

#endif // MAINWINDOW_H
