#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QAudioInput>
#include "xyseriesiodevice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_player = nullptr;
    QMediaPlaylist *m_playlist = nullptr;

    XYSeriesIODevice *m_device = nullptr;
    QtCharts::QChart *m_chart = nullptr;
    QtCharts::QLineSeries *m_series = nullptr;
    QAudioInput *m_audioInput = nullptr;
};
#endif // MAINWINDOW_H
