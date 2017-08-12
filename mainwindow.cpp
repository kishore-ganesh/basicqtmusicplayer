#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "QFileDialog"
#include <QMediaPlayer>
#include <QString>


QMediaPlayer *player=new QMediaPlayer;
QStringList files;
QStringList list;
int sizeoflist;
int checker;
int j=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(duration(qint64)));

    QObject::connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(converter(qint64)));
    QObject::connect(this, SIGNAL(emitter(int)), ui->lcdNumber, SLOT(display(int)));
    QObject::connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(domedia(QMediaPlayer::MediaStatus)));
    QObject::connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), this,  SLOT(setPosition(int)));

}

int playmusic(QString);
int converter(qint64 b);

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    //QString files=QFileDialog::getOpenFileName(this, tr("Open file"),QString(), tr("Music files(*.mp3)") );
    files=QFileDialog::getOpenFileNames(this, tr("Open file"),QString(), tr("Music files(*.mp3)") );
    sizeoflist=files.size();
    for (int i=0; i<sizeoflist; i++)
    {playmusic(files.at(i).toLocal8Bit().constData());
    //QString songname=player->currentMedia();
    QFileInfo fi(files.at(i).toLocal8Bit().constData());
    QString songname= fi.fileName();
    ui->label_4->setText(songname);
    checker=i;
    }



}




int playmusic(QString a)
{player->setMedia(QUrl::fromLocalFile(a));


    player->setVolume(50);
    player->play();












return 0;}




void MainWindow::changevolume(int value)
{
    player->setVolume(value);

}




void MainWindow::on_pushButton_2_clicked()
{
    player->pause();
}



void MainWindow::on_pushButton_3_clicked()
{
    player->play();
}

void MainWindow::duration(qint64 duration)
{ui->horizontalSlider_2->setRange(0, duration) ;
            ui->horizontalSlider_2->setEnabled(duration > 0);
            ui->horizontalSlider_2->setPageStep(duration / 10);
float time;
time =duration/1000;
int minutes=time/60;
QString minute=QString::number(minutes);
int seconds=time-(minutes*60);
QString second=QString::number(seconds);

//ui->label->setText(minutes":"seconds);
ui->label_2->setText(minute);
ui->label_3->setText(second);

}


int MainWindow::converter(qint64 b)
{ui->horizontalSlider_2->setValue(b);
    emit emitter(1);
}





void MainWindow::on_pushButton_4_clicked()
{playfilesmultiple();

}




void MainWindow::on_pushButton_5_clicked()
{ list=QFileDialog::getOpenFileNames(this, tr("Open file"),QString(), tr("Music files(*.mp3)") );
    sizeoflist=list.size();

    playmusic(list.at(j).toLocal8Bit().constData());
    //QString songname=player->currentMedia();
    QFileInfo fi(list.at(j).toLocal8Bit().constData());
    QString songname= fi.fileName();
    ui->label_4->setText(songname);
    checker=j;



}

void MainWindow::domedia(QMediaPlayer::MediaStatus status)

{
    if (status==QMediaPlayer::EndOfMedia)
    {MainWindow::playfilesmultiple();

}}

void MainWindow::playfilesmultiple()
{j++;
    playmusic(list.at(j).toLocal8Bit().constData());
    //QString songname=player->currentMedia();
    QFileInfo fi(list.at(j).toLocal8Bit().constData());
    QString songname= fi.fileName();
    ui->label_4->setText(songname);
}



void MainWindow::on_pushButton_6_clicked()
{j--;
    playmusic(list.at(j).toLocal8Bit().constData());
    //QString songname=player->currentMedia();
    QFileInfo fi(list.at(j).toLocal8Bit().constData());
    QString songname= fi.fileName();
    ui->label_4->setText(songname);

}

void MainWindow::setPosition(int position)
{qint64 qintposition=position;
     if (qAbs(player->position() - position) > 100)
    player->setPosition(position);}


