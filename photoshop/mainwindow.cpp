#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "opencv2/core/core.hpp"

#include <QTimer>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>

#include <QFileDialog>
#include <QMessageBox>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(DisplayImage()));
    Timer->start(); //Will start the timer
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayImage()
{
    if(FileName!="")
    {
        Mat img;
        img = imread(FileName.toStdString());

        cv::resize(img, img, Size(512, 384), 0, 0, INTER_LINEAR);

        cv::cvtColor(img,img,CV_BGR2RGB);
        int alpha=alpha_param;
        int beta=beta_param;
        img.convertTo(img, -1, alpha, beta);


        QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
        ui->display_image->setPixmap(QPixmap::fromImage(imdisplay));
    }

}



void MainWindow::on_actionOpen_Image_triggered()
{
    QString filename_input=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "/home/lehi/Documentos",
                "Image Files (*.png *.jpg *.bmp)"
                );
    QMessageBox::information(this,tr("File Name"),filename_input);
    FileName=filename_input;

}


void MainWindow::on_alpha_valueChanged(double arg1)
{
    alpha_param=arg1;
}



void MainWindow::on_beta_valueChanged(int arg1)
{
    beta_param=arg1;
}
