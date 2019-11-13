#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_player = new QMediaPlayer;
    m_videoWidget = new QVideoWidget;
    m_player->setVideoOutput(m_videoWidget);
    m_player->setMedia(QUrl::fromLocalFile("/Users/quintin/Developer/simple-caption-editor/test_video.mov"));
    m_player->play();
    m_player->setVolume(10);

    ui->videoLayout->addWidget(m_videoWidget);
    m_videoWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

