#include <QMargins>
#include <QtCharts/QValueAxis>
#include <QAudioDecoder>
#include <QAudioFormat>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));

    //video player
    m_player = new QMediaPlayer;
    m_player->setVideoOutput(ui->playerWidget);
    m_player->setMedia(QUrl::fromLocalFile("/Users/quintin/Developer/simple-caption-editor/test_video.mov"));
    m_player->play();
    m_player->setVolume(10);

    //audio soundwave
    m_series = new QtCharts::QLineSeries;
    m_chart = new QtCharts::QChart;
    m_chart->layout()->setContentsMargins(0, 0, 0, 0);
    m_chart->setBackgroundRoundness(0);
    m_chart->addSeries(m_series);

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,100);
    axisX->setLabelFormat("%g");
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-1, 1);
    m_chart->addAxis(axisX, Qt::AlignBottom);
    m_series->attachAxis(axisX);
    m_chart->addAxis(axisY, Qt::AlignLeft);
    m_series->attachAxis(axisY);
    m_chart->legend()->hide();

    QString sampleCaption = QString("现在是一趟开往Fleminton的专列\n开往墨尔本杯赛马场\nHello 大家好 我是dev小Q\n又和大家见面了\n今天是11月5号星期二\n是维州的一个公共假期 墨尔本杯\n全州放假\n因为我夫人她公司会发门票\n刚好就有机会能过来(参加这项赛事)\n墨尔本杯呢 历史非常悠久\n它开始于1861年 距今已经有158年的历史\n墨尔本杯刚开始是给富商名流 准备的一项赛事\n属于贵族活动 到了现代开始慢慢得平民化\n现在我们普通人 大家都能参加\n这项赛事呢  现在是一项\n集体育、时尚、美食、美酒\n包括社交活动 于一身的一项赛事\n着装呢 对男性女性要求都非常高\n男性的话 你必须要穿着正装\n然后领带也要系\n如果你不穿这些服装的话 (工作人员)都不会让你进\n女士的话 一定要穿裙子\n然后戴头饰\n这个没有硬性的要求\n但是这个头饰它就很重要了\n你可以戴头饰 或者带帽子\n这些都是一种比拼的东西吧\n反正大家来这里 女性就是来这比美\n男性就是来这耍帅\n所以这个场合还是非常有趣的\n墨尔本杯自从发展到现在以来呢\n它这个比赛奖金 现在慢慢的水涨船高\n去年是730万澳币的总奖金\n今年是涨到了800万\n今年第一名的奖金涨到了4.4M\n也就是440万澳币 所以奖金累计的是非常高\n这个赛事呢 在澳洲来说非常著名\n它是一个号称是\nA race that stops the nation的一个活动\n就是一项能够停摆整个国家的一个赛事\n它的受关注程度 (可以说)是非常高的\n它一共呢 是为期 其实是4天\n所以这个墨尔本它不只是一项赛事 \n它叫嘉年华赛事(Melborune Cup Carnival)\n今天主要是正赛 因为是11月的第二个周二\n其他还有几天的赛事 一共是4天\n四天赛事下来以后 排名前12的人会得到奖金\n奖金从440万澳币今年 一直到十几万澳币不等\n我们等会应该就去会场 现在大家都在这个地方\n可能都在social \n他们定的一个function 一个function\n一个小区一个小区域的 感觉还挺好\n就是在看比赛之前 \n我们先过来吃点东西 聊聊天\n这就是鬼佬他们的生活方式\n反正就是社交嘛 啊~ Networking嘛\n这也是这项赛事中很重要的一个方面\n本来正式比赛是下午3点\n因为她们客户可能11点 早上11点就来了\n她们还得为了工作 先见一下客户 \n然后谈一谈 混个脸熟 \n其实时间长了你会发现 其实整个世界都是一样的\n每个公司之间都会隔开 会分成一个区一个区\n这里其实也没什么东西 大家就是在这里吃喝玩乐\n现在吃一吃 (菲姐)她们公司准备的小吃\n(你吃一个~)\n看看今天的菲姐 哇~ 好美呀 (*╯3╰)\n(这里是一个赌马点 你得在这里下注才能赌马)\n这里想赌个钱~ 还得取现金\n所以大家都在这边的ATM机取现\n好难呀~ 要不你就得上网赌\n刚才花了20-30刀买了几张赌马票\n大概1点20开赛\n赌了4个骑手 希望能中点钱吧\n现在状态已经起来了 大家都很嗨了\n现在是下午1点 离正赛还有两个小时\n马上三点就可以有 正式比赛\n逃离了菲菲姐的公司团队 现在准备一个人转一转\n这里就是Fleminton赛马场的主会场了 \n现在这里全是人 人山人海~\n(这里的朋友们都很激动啊~ ^_^)\n在现场的感觉还是不一样\n很多人在这里站着都是赌了马的\n所以他们心情都很复杂\n现在我们再看一下回放 \n现在过来吃一点 炸鸡翅炸薯条\n晃悠了一两个小时 等会3点就是正赛\n看完正赛我们就回家了\n现在是最重要的一场比赛 \n也就是当天下午3点钟\nMelbourne Cup的正赛\n大家都很激动 现在比赛开始啦~\n让我们拭目以待吧\n你买的是几号？\n(啊~ 9，24， 3)\n这个比赛是3.2公里的赛事\n现在还没有结束 我感觉自己看得都累了\n这些马得多累~\n现在还有800米\n(要撞线啦~~~)\n(最后结局是一场比赛都没中哟~ (灬ꈍ ꈍ灬))\n");
    ui->captionArea->setText(sampleCaption);

//    QAudioFormat desiredFormat;
//    desiredFormat.setChannelCount(2);
//    desiredFormat.setCodec("audio/x-raw");
//    desiredFormat.setSampleType(QAudioFormat::UnSignedInt);
//    desiredFormat.setSampleRate(48000);
//    desiredFormat.setSampleSize(16);

//    QAudioDecoder *decoder = new QAudioDecoder(this);
//    decoder->setAudioFormat(desiredFormat);
//    decoder->setSourceFilename("/Users/quintin/Developer/simple-caption-editor/test_video.mov");

//    connect(decoder, SIGNAL(bufferReady()), this, SLOT(readBuffer()));
//    decoder->start();
    // Now wait for bufferReady() signal and call decoder->read()


    for (double i = 0.0 ;i<100.0;i+= 0.2) {
        m_series->append(i,  rand()%((1 + 1) + 1) - 1);
    }

    ui->graphicsView->setChart(m_chart);
}

MainWindow::~MainWindow()
{
    delete ui;
}

