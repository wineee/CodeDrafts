#include "widget.h"
#include <QDebug>

Slider::Slider(QWidget *parent) : QSlider(parent)
{
    setOrientation(Qt::Horizontal);
}
void Slider::mousePressEvent(QMouseEvent *ev) {
    QSlider::mousePressEvent(ev);
    double pos = ev->pos().x() / (double)width();
    setValue(pos * (maximum() - minimum()) + minimum());
    emit MySliderClicked();
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(800, 500, 400, 300);
    m_button = new QPushButton(this);
    m_layout = new QGridLayout(this);
    m_layout->addWidget(m_button);
    setLayout(m_layout);

    m_player = new QMediaPlayer;
    MusicPath = R"(/home/rewine/音乐/CloudMusic/test1.mp3)";
    m_player->setMedia(QUrl::fromLocalFile(MusicPath));
    //m_player->setVolume(50);

    m_progress = new Slider(this);
    m_layout->addWidget(m_progress);
    //m_progress->resize(80, 30);

    m_progress->setMinimum(0);
    m_progress->setMaximum(1000);
    m_progress->setValue(0);

    isPlay = 0;
    connect(m_button, &QPushButton::clicked, this, [=]() {
        isPlay = !isPlay;
        if (isPlay)
            m_player->play();
        else
            m_player->stop();
    });

//    connect(m_player, &QMediaPlayer::positionChanged, this, [=](qint64 position) {
//        qDebug() << position << " " << m_player->duration();
//    });
    timer = new QTimer();
    timer->setInterval(1000 / 4);
    timer->start();
    connect(timer, &QTimer::timeout, this, [=](){
         m_progress->setValue(1000 * m_player->position() / m_player->duration());
         qDebug() << m_player->position() << " " << m_player->duration() ;
    });
    connect(m_progress, &Slider::sliderMoved, this, [=]() {
        timer->stop();
        m_player->setPosition(m_progress->value() * m_player->duration() / 1000);
    });
    connect(m_progress, &Slider::sliderReleased, this, [=]() {
        timer->start();
    });
    connect(m_progress, &Slider::MySliderClicked, this, [=]() {
        m_player->setPosition(m_progress->value() * m_player->duration() / 1000);
    });
}

Widget::~Widget()
{
}

