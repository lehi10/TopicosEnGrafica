#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    int alpha_param=0;
    int beta_param=0;


private slots:
    void on_actionOpen_Image_triggered();



    void on_alpha_valueChanged(double arg1);


    void on_beta_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;




};

#endif // MAINWINDOW_H
