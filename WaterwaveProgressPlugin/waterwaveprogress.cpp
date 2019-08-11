#include "waterwaveprogress.h"

#include <QPainterPath>
#include <QPainter>
#include <QDebug>

#define PI 3.1415

WaterwaveProgress::WaterwaveProgress(QWidget *parent) :
    QWidget(parent)
  , m_size(200)
  , m_shape(Shape::Round)
  , m_borderWidth(4)
  , m_borderColor(Qt::black)
  , m_bgColor(QColor(160,160,160))
  , m_textColor(Qt::white)
  , m_textFamily("Microsoft YaHei")
  , m_textSize(25)
  , m_waterwaveColor(QColor(5,125,255))
  , m_waveHeight(10)
  , m_waveWidth(30)
  , m_offset(0.0)
  , m_percent(50)
{
    this->setFixedSize(QSize(m_size,m_size));

    m_timer=new QTimer(this);
    m_timer->setInterval(80);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(update()));
    m_timer->start();
}

int WaterwaveProgress::progressSize()
{
    return m_size;
}

void WaterwaveProgress::setProgressSize(int size)
{
    m_size = size;
    this->setFixedSize(QSize(m_size,m_size));
}

WaterwaveProgress::Shape WaterwaveProgress::progressShape()
{
    return m_shape;
}

void WaterwaveProgress::setProgressShape(WaterwaveProgress::Shape shape)
{
    m_shape = shape;
}

int WaterwaveProgress::borderWidth()
{
    return m_borderWidth;
}

void WaterwaveProgress::setBorderWidth(int thickness)
{
    m_borderWidth = thickness;
}

QColor WaterwaveProgress::borderColor()
{
    return m_borderColor;
}

void WaterwaveProgress::setBorderColor(QColor color)
{
    m_borderColor = color;
}

QColor WaterwaveProgress::waterwaveColor()
{
    return m_waterwaveColor;
}

void WaterwaveProgress::setWaterwaveColor(QColor color)
{
    m_waterwaveColor = color;
}

QColor WaterwaveProgress::bgColor()
{
    return m_bgColor;
}

void WaterwaveProgress::setBgColor(QColor color)
{
    m_bgColor = color;
}

QColor WaterwaveProgress::textColor()
{
    return m_textColor;
}

void WaterwaveProgress::setTextColor(QColor color)
{
    m_textColor = color;
}

QString WaterwaveProgress::textFamily()
{
    return m_textFamily;
}

void WaterwaveProgress::setTextFamily(QString family)
{
    m_textFamily = family;
}

int WaterwaveProgress::textSize()
{
    return m_textSize;
}

void WaterwaveProgress::setTextSize(int textSize)
{
    if ( textSize < 0 || textSize > 25)
        return;
    m_textSize = textSize;
}

int WaterwaveProgress::waveHeight()
{
    return m_waveHeight;
}

void WaterwaveProgress::setWaveHeight(int height)
{
    m_waveHeight = height;
}

int WaterwaveProgress::waveWidth()
{
    return m_waveWidth;
}

void WaterwaveProgress::setWaveWidth(int width)
{
    if (m_waveWidth < 0)
        return;
    m_waveWidth = width;
}

int WaterwaveProgress::percent()
{
    return m_percent;
}

void WaterwaveProgress::setPercent(int percent)
{
    if (percent < 0 || percent >100)
        return;
    else
        m_percent = percent;
}


void WaterwaveProgress::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    drawWaterwave(painter);
    drawText(painter);
}

QSize WaterwaveProgress::sizeHint()
{
    return QSize(m_size,m_size);
}

void WaterwaveProgress::drawWaterwave(QPainter &painter)
{
    painter.setRenderHint(QPainter::Antialiasing);

    double waveMidHeight = m_borderWidth + (double)(m_size-2*m_borderWidth)*(100-m_percent)/100;

    QPainterPath water_path1;
    QPainterPath water_path2;

    water_path1.moveTo((double)0,(double)m_size);
    water_path2.moveTo((double)0,(double)m_size);
    for (double x=0.0; x<=m_size; ++x ) {
        double waterY1 = m_waveHeight* sin(x/m_waveWidth+m_offset) + waveMidHeight;
        water_path1.lineTo(x, waterY1);

        double waterY2 = m_waveHeight* sin(x/m_waveWidth+m_offset + m_waveWidth) + waveMidHeight;
        water_path2.lineTo(x, waterY2);
    }

    water_path1.lineTo(m_size, m_size);
    water_path2.lineTo(m_size, m_size);

    if (m_offset < m_size)
        m_offset +=0.6;
    else
        m_offset = m_offset - m_size;

    painter.setPen(QPen(m_borderColor,m_borderWidth));
    painter.setBrush( QBrush(m_bgColor));
    QPainterPath borderpath;
    if (m_shape == Shape::Round) {
        borderpath.addEllipse(m_borderWidth,m_borderWidth,m_size-2*m_borderWidth,m_size-2*m_borderWidth);
        painter.drawEllipse(m_borderWidth/2,m_borderWidth/2,m_size-m_borderWidth,m_size-m_borderWidth );
    } else {
        borderpath.addRect(m_borderWidth,m_borderWidth,m_size-2*m_borderWidth,m_size-2*m_borderWidth);
        painter.drawRect(m_borderWidth/2,m_borderWidth/2,m_size-m_borderWidth,m_size-m_borderWidth );
    }

    painter.setPen(QPen(m_waterwaveColor));
    QPainterPath new_path1 = borderpath.intersected(water_path1);
    painter.fillPath(new_path1, QBrush(m_waterwaveColor));

    QColor bg_waterwaveColor = m_waterwaveColor;
    bg_waterwaveColor.setAlpha(120);
    painter.setPen(QPen(bg_waterwaveColor));
    QPainterPath new_path2 = borderpath.intersected(water_path2);
    painter.fillPath(new_path2, QBrush(bg_waterwaveColor));

}

void WaterwaveProgress::drawText(QPainter &painter)
{
    int font_size = m_size*m_textSize/100;
    QFont font{m_textFamily, font_size};
    painter.setPen(m_textColor);
    painter.setFont(font);
    painter.drawText(this->rect(), Qt::AlignCenter, QString("%0%").arg(QString::number(m_percent)));
}
