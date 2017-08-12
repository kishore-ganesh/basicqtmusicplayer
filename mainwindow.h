#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void playfilesmultiple();


signals: int emitter(int b);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_valueChanged(int value);

    void changevolume(int value);

    void on_pushButton_3_clicked();

    void on_toolButton_clicked();

    void showposition(int position);

    void on_pushButton_4_clicked();


    void on_pushButton_5_clicked();

    void domedia(QMediaPlayer::MediaStatus status);

    void on_pushButton_6_clicked();
void setPosition(int position);

void on_horizontalSlider_2_valueChanged(int value);

public slots:

    int converter(qint64);

    void duration(qint64);

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H


