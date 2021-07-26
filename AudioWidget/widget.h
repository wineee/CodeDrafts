#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QStringList>
#include <QDir>
#include <QPushButton>
#include <QLayout>
#include <QProgressBar>
#include <QTimer>
#include <QSlider>


#include <QMouseEvent>
#include <QCoreApplication>

class Slider : public QSlider
{
    Q_OBJECT
public:
    explicit Slider(QWidget *parent = nullptr);
    ~Slider() = default;
protected:
    void mousePressEvent(QMouseEvent *ev);//重写QSlider的mousePressEvent事件
signals:
    void MySliderClicked();
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *m_button;
    QLayout *m_layout;
    Slider *m_progress;
    QTimer *timer;

    bool isPlay = false;
    QString MusicPath;

    QMediaPlayer *m_player;
private slots:
};
#endif // WIDGET_H
