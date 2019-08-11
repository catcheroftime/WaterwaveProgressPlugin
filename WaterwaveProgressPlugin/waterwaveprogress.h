#ifndef WATERWAVEPROGRESS_H
#define WATERWAVEPROGRESS_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>
#include <QtUiPlugin/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT  WaterwaveProgress : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(int progressSize READ progressSize WRITE setProgressSize)
    Q_PROPERTY(Shape progressShape READ progressShape WRITE setProgressShape)
    Q_ENUMS(Shape)
    Q_PROPERTY(int borderWidth READ borderWidth WRITE setBorderWidth )
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor)
    Q_PROPERTY(QColor waterwaveColor READ waterwaveColor WRITE setWaterwaveColor)
    Q_PROPERTY(QColor bgColor READ bgColor WRITE setBgColor)

    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor)
    Q_PROPERTY(QFont textFont READ textFont WRITE setTextFont)

    Q_PROPERTY(int waveHeight READ waveHeight WRITE setWaveHeight)
    Q_PROPERTY(int waveWidth READ waveWidth WRITE setWaveWidth)
    Q_PROPERTY(int percent READ percent WRITE setPercent)

public:
    enum Shape {Square, Round};

    WaterwaveProgress(QWidget *parent = 0);

    int progressSize();
    void setProgressSize(int size);

    Shape progressShape();
    void setProgressShape(Shape shape);

    int borderWidth();
    void setBorderWidth(int thickness);

    QColor borderColor();
    void setBorderColor(QColor color);

    QColor waterwaveColor();
    void setWaterwaveColor(QColor color);

    QColor bgColor();
    void setBgColor(QColor color);

    QColor textColor();
    void setTextColor(QColor color);

    QFont textFont();
    void setTextFont(QFont font);

    int waveHeight();
    void setWaveHeight(int height);

    int waveWidth();
    void setWaveWidth(int width);

    int percent();
    void setPercent(int percent);

protected:
    void paintEvent(QPaintEvent *);
    QSize sizeHint();

private:
    int m_size;
    Shape m_shape;
    int m_borderWidth;
    QColor m_borderColor;
    QColor m_bgColor;

    QColor m_textColor;
    QFont m_textFont;

    QColor m_waterwaveColor;
    int m_waveHeight;
    int m_waveWidth;
    float m_offset;
    int m_percent;

    QTimer * m_timer;

private:
    void drawWaterwave(QPainter &painter);
    void drawText(QPainter &painter);


};

#endif
