/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSlider *verticalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 751);
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 460, 121, 41));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton->setFont(font1);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(100, 100, 751, 251));
        graphicsView->setInteractive(true);
        graphicsView->setRenderHints(QPainter::Antialiasing);
        graphicsView->setCacheMode(QGraphicsView::CacheNone);
        graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 530, 121, 41));
        pushButton_2->setFont(font1);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(100, 600, 121, 41));
        pushButton_3->setFont(font1);
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(800, 460, 20, 181));
        verticalSlider->setMinimum(1);
        verticalSlider->setMaximum(15);
        verticalSlider->setPageStep(1);
        verticalSlider->setValue(15);
        verticalSlider->setOrientation(Qt::Vertical);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 400, 121, 21));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 400, 231, 21));
        label_3->setAlignment(Qt::AlignCenter);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(330, 600, 121, 41));
        pushButton_4->setFont(font1);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(330, 530, 121, 41));
        pushButton_5->setFont(font1);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(330, 460, 121, 41));
        pushButton_6->setFont(font1);
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(580, 460, 121, 41));
        pushButton_7->setFont(font1);
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(580, 530, 121, 41));
        pushButton_8->setFont(font1);
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(580, 600, 121, 41));
        pushButton_9->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(530, 400, 231, 21));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(720, 400, 161, 21));
        label_5->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(blueClicked()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(randomClicked()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(redClicked()));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(sliderMoved(int)));
        QObject::connect(pushButton_5, SIGNAL(clicked()), MainWindow, SLOT(leftWind()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), MainWindow, SLOT(noWind()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), MainWindow, SLOT(rightWind()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), MainWindow, SLOT(openCVBlur()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), MainWindow, SLOT(openCVFlip()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), MainWindow, SLOT(openCVNoEffect()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fire App", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Red", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Blue", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Random", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "COLOR", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "WIND DIRECTION", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Right", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Left", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "N/A", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "N/A", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "Flip", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "Blur", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "OPENCV", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "INTENSITY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
