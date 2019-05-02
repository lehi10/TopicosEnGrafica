/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Image;
    QAction *actionSave_Image;
    QAction *actionExit;
    QAction *actionBrightness;
    QAction *actionContrast;
    QAction *actionHistograma;
    QAction *actionGray_Scale;
    QWidget *centralWidget;
    QLabel *display_image;
    QDoubleSpinBox *alpha;
    QSpinBox *beta;
    QLabel *histograma_label;
    QLabel *label;
    QLineEdit *a_factor_input;
    QLineEdit *b_factor_input;
    QPushButton *edit_factors_button;
    QMenuBar *menuBar;
    QMenu *menuAsdasd;
    QMenu *menuEdit;
    QMenu *menuTools;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(864, 454);
        //MainWindow->setToolTipDuration(-1);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionOpen_Image = new QAction(MainWindow);
        actionOpen_Image->setObjectName(QString::fromUtf8("actionOpen_Image"));
        actionSave_Image = new QAction(MainWindow);
        actionSave_Image->setObjectName(QString::fromUtf8("actionSave_Image"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionBrightness = new QAction(MainWindow);
        actionBrightness->setObjectName(QString::fromUtf8("actionBrightness"));
        actionContrast = new QAction(MainWindow);
        actionContrast->setObjectName(QString::fromUtf8("actionContrast"));
        actionHistograma = new QAction(MainWindow);
        actionHistograma->setObjectName(QString::fromUtf8("actionHistograma"));
        actionGray_Scale = new QAction(MainWindow);
        actionGray_Scale->setObjectName(QString::fromUtf8("actionGray_Scale"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        display_image = new QLabel(centralWidget);
        display_image->setObjectName(QString::fromUtf8("display_image"));
        display_image->setGeometry(QRect(320, 20, 521, 311));
        alpha = new QDoubleSpinBox(centralWidget);
        alpha->setObjectName(QString::fromUtf8("alpha"));
        alpha->setGeometry(QRect(60, 20, 69, 27));
        beta = new QSpinBox(centralWidget);
        beta->setObjectName(QString::fromUtf8("beta"));
        beta->setGeometry(QRect(10, 20, 48, 27));
        histograma_label = new QLabel(centralWidget);
        histograma_label->setObjectName(QString::fromUtf8("histograma_label"));
        histograma_label->setGeometry(QRect(20, 110, 321, 261));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 21, 17));
        a_factor_input = new QLineEdit(centralWidget);
        a_factor_input->setObjectName(QString::fromUtf8("a_factor_input"));
        a_factor_input->setGeometry(QRect(20, 70, 31, 27));
        b_factor_input = new QLineEdit(centralWidget);
        b_factor_input->setObjectName(QString::fromUtf8("b_factor_input"));
        b_factor_input->setGeometry(QRect(90, 70, 31, 27));
        edit_factors_button = new QPushButton(centralWidget);
        edit_factors_button->setObjectName(QString::fromUtf8("edit_factors_button"));
        edit_factors_button->setGeometry(QRect(130, 70, 51, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 864, 25));
        menuAsdasd = new QMenu(menuBar);
        menuAsdasd->setObjectName(QString::fromUtf8("menuAsdasd"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuAsdasd->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuAsdasd->addAction(actionOpen_Image);
        menuAsdasd->addAction(actionSave_Image);
        menuAsdasd->addAction(actionExit);
        menuEdit->addAction(actionBrightness);
        menuEdit->addAction(actionContrast);
        menuEdit->addAction(actionGray_Scale);
        menuTools->addAction(actionHistograma);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen_Image->setText(QApplication::translate("MainWindow", "Open Image", 0, QApplication::UnicodeUTF8));
        actionSave_Image->setText(QApplication::translate("MainWindow", "Save Image", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionBrightness->setText(QApplication::translate("MainWindow", "Brightness", 0, QApplication::UnicodeUTF8));
        actionContrast->setText(QApplication::translate("MainWindow", "Contrast", 0, QApplication::UnicodeUTF8));
        actionHistograma->setText(QApplication::translate("MainWindow", "Histograma", 0, QApplication::UnicodeUTF8));
        actionGray_Scale->setText(QApplication::translate("MainWindow", "Gray Scale", 0, QApplication::UnicodeUTF8));
        display_image->setText(QString());
        histograma_label->setText(QString());
        label->setText(QApplication::translate("MainWindow", "A + ", 0, QApplication::UnicodeUTF8));
        edit_factors_button->setText(QApplication::translate("MainWindow", "Ok", 0, QApplication::UnicodeUTF8));
        menuAsdasd->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
