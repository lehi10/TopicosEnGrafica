#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>


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
    this->alpha_param=1.0;
    if(FileName!="" &&  edited == false)
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
    edited=false;

}


void MainWindow::on_alpha_valueChanged(double arg1)
{
    alpha_param=arg1;
}



void MainWindow::on_beta_valueChanged(int arg1)
{
    beta_param=arg1;
}


Mat MainWindow::calcularHistograma(Mat imRec){
    vector<Mat> planosBGR;
    split(imRec,planosBGR);

    Mat bHist, gHist, rHist;

    int histSize = 255;
    float range[] = {0,255};
    const float* histRanges = {range};
    bool uniform = TRUE, accumulate = FALSE;

    calcHist(&planosBGR[0],1,0,Mat(),bHist,1,&histSize,&histRanges,uniform,accumulate);
    calcHist(&planosBGR[1],1,0,Mat(),gHist,1,&histSize,&histRanges,uniform,accumulate);
    calcHist(&planosBGR[2],1,0,Mat(),rHist,1,&histSize,&histRanges,uniform,accumulate);
   // calcHist(const Mat* images, int nimages, const int* channels, InputArray mask, SparseMat& hist, int dims, const int* histSize, const float** ranges, bool uniform=true, bool accumulate=false )

    int hist_w = 512;
    int hist_h = 400;
    int delta = cvRound((double) hist_w/histSize);

    Mat histImgen(hist_h,hist_w,CV_8UC3,Scalar(0,0,0));
    normalize(bHist, bHist, 0,histImgen.rows,NORM_MINMAX, -1, Mat());
    normalize(gHist, gHist, 0,histImgen.rows,NORM_MINMAX, -1, Mat());
    normalize(rHist, rHist, 0,histImgen.rows,NORM_MINMAX, -1, Mat());

    for(int i = 1; i < histSize ; i++){
        line( histImgen,
                      Point( delta*(i-1), hist_h - cvRound(bHist.at<float>(i-1)) ) ,
                      Point( delta*(i), hist_h - cvRound(bHist.at<float>(i)) ),
                      Scalar( 255, 0, 0), 2, 8, 0  );

                line( histImgen, Point( delta*(i-1), hist_h - cvRound(gHist.at<float>(i-1)) ) ,
                      Point( delta*(i), hist_h - cvRound(gHist.at<float>(i)) ),
                      Scalar( 0, 255, 0), 2, 8, 0  );

                line( histImgen, Point( delta*(i-1), hist_h - cvRound(rHist.at<float>(i-1)) ) ,
                      Point( delta*(i), hist_h - cvRound(rHist.at<float>(i)) ),
                      Scalar( 0, 0, 255), 2, 8, 0  );
    }




    return histImgen;
}



void MainWindow::on_actionHistograma_triggered()
{

        Mat img, histograma;

        img = imread(FileName.toStdString());

        histograma=calcularHistograma(img);

        cv::resize(img, img, Size(512, 384), 0, 0, INTER_LINEAR);

        cv::cvtColor(img,img,CV_BGR2RGB);


        QImage imdisplay((uchar*)histograma.data, histograma.cols, histograma.rows, histograma.step, QImage::Format_RGB888);

        QLabel *newDlg = new QLabel();

        newDlg->setPixmap(QPixmap::fromImage(imdisplay));
        newDlg->show();
}

void MainWindow::on_actionGray_Scale_triggered()
{
    Mat img;
    img = imread(FileName.toStdString());

    cv::resize(img, img, Size(512, 384), 0, 0, INTER_LINEAR);

    cv::cvtColor(img,img,CV_BGR2RGB);
    cv::cvtColor(img,img,CV_BGR2GRAY);

    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_Indexed8);

    ui->display_image->setPixmap(QPixmap::fromImage(imdisplay));
    edited=true;

}


void MainWindow::on_edit_factors_button_clicked()
{
    Mat img;
    img = imread(FileName.toStdString());



    //img=ui->a_factor_input*img + ui->b_factor_input ;

    cv::resize(img, img, Size(512, 384), 0, 0, INTER_LINEAR);

    cv::cvtColor(img,img,CV_BGR2RGB);




    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_Indexed8);

    ui->display_image->setPixmap(QPixmap::fromImage(imdisplay));
    edited=true;
}
