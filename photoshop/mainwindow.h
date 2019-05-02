#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:    // A slot or function is defined which will be intiated by timer
    void DisplayImage();

public:
    explicit MainWindow(QWidget *parent = 0);
    QImage imdisplay;  //This will create QImage which is shown in Qt label
    QTimer* Timer;   // A timer is needed in GUI application
    ~MainWindow();

    QString FileName;

    //Image Parameters

    int alpha_param;
    int beta_param;

    bool edited;


private slots:
    void on_actionOpen_Image_triggered();



    void on_alpha_valueChanged(double arg1);


    void on_beta_valueChanged(int arg1);

    void on_actionHistograma_triggered();
    Mat calcularHistograma(Mat imRec);

    void on_actionGray_Scale_triggered();

    void on_edit_factors_button_clicked();

private:
    Ui::MainWindow *ui;




};

#endif // MAINWINDOW_H
