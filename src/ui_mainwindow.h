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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1029, 634);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 410, 121, 41));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 40, 741, 311));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 470, 121, 41));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 530, 121, 41));
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(840, 100, 20, 251));
        verticalSlider->setMinimum(1);
        verticalSlider->setMaximum(10);
        verticalSlider->setPageStep(1);
        verticalSlider->setValue(10);
        verticalSlider->setOrientation(Qt::Vertical);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(780, 40, 141, 51));
        QFont font;
        font.setPointSize(8);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 370, 121, 21));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 370, 181, 21));
        label_3->setAlignment(Qt::AlignCenter);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(350, 530, 121, 41));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 470, 121, 41));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(350, 410, 121, 41));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(blueClicked()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(randomClicked()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(redClicked()));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(sliderMoved(int)));
        QObject::connect(pushButton_5, SIGNAL(clicked()), MainWindow, SLOT(leftWind()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), MainWindow, SLOT(noWind()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), MainWindow, SLOT(rightWind()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Red", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Blue", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Random", nullptr));
        label->setText(QApplication::translate("MainWindow", "INTENSITY", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "COLOR", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "WIND DIRECTION", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Right", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Left", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "N/A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
