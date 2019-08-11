#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initViewDefault();
    initStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initViewDefault()
{
    ui->spinBox_size->setValue(ui->waterwaveProgress->progressSize());

    if (ui->waterwaveProgress->progressShape() == WaterwaveProgress::Shape::Square)
        ui->comboBox_shape->setCurrentIndex(1);
    else
        ui->comboBox_shape->setCurrentIndex(0);

    ui->spinBox_borderwidth->setValue(ui->waterwaveProgress->borderWidth());
    ui->spinBox_percent->setValue(ui->waterwaveProgress->percent());
    ui->spinBox_waveheight->setValue(ui->waterwaveProgress->waveHeight());
    ui->spinBox_wavewidth->setValue(ui->waterwaveProgress->waveWidth());

    QColor wavecolor = ui->waterwaveProgress->waterwaveColor();
    QColor bordercolor = ui->waterwaveProgress->borderColor();
    QColor bgcolor = ui->waterwaveProgress->bgColor();
    QColor textcolor = ui->waterwaveProgress->textColor();

    ui->ptn_waterwavecolor->setStyleSheet(QString("background:")+color2string(wavecolor));
    ui->ptn_bordercolor->setStyleSheet(QString("background:")+color2string(bordercolor));
    ui->ptn_bgcolor->setStyleSheet(QString("background:")+color2string(bgcolor));
    ui->ptn_textcolor->setStyleSheet(QString("background:")+color2string(textcolor));

}

void MainWindow::initStyle()
{

}

void MainWindow::on_spinBox_size_editingFinished()
{
    int size = ui->spinBox_size->value();
    ui->waterwaveProgress->setProgressSize(size);
}

void MainWindow::on_spinBox_borderwidth_editingFinished()
{
    int borderwidth = ui->spinBox_borderwidth->value();
    ui->waterwaveProgress->setBorderWidth(borderwidth);
}

void MainWindow::on_comboBox_shape_currentIndexChanged(int index)
{
    if (index == 0)
        ui->waterwaveProgress->setProgressShape(WaterwaveProgress::Shape::Round);
    else
        ui->waterwaveProgress->setProgressShape(WaterwaveProgress::Shape::Square);
}


void MainWindow::on_spinBox_percent_editingFinished()
{
    int percent = ui->spinBox_percent->value();
    ui->waterwaveProgress->setPercent(percent);
}

void MainWindow::on_spinBox_wavewidth_editingFinished()
{
    int wavewidth = ui->spinBox_wavewidth->value();
    ui->waterwaveProgress->setWaveWidth(wavewidth);
}

void MainWindow::on_spinBox_waveheight_editingFinished()
{
    int waveheight = ui->spinBox_waveheight->value();
    ui->waterwaveProgress->setWaveHeight(waveheight);
}

void MainWindow::on_ptn_bordercolor_clicked()
{
    QColor selectcolor;
    QColor bordercolor = ui->waterwaveProgress->borderColor();
    bool ok = selectColor(selectcolor, bordercolor);
    if (ok) {
        ui->waterwaveProgress->setBorderColor(selectcolor);
        ui->ptn_bordercolor->setStyleSheet(QString("background:")+color2string(selectcolor));
    }
}

void MainWindow::on_ptn_waterwavecolor_clicked()
{
    QColor selectcolor;
    QColor wavecolor = ui->waterwaveProgress->waterwaveColor();
    bool ok = selectColor(selectcolor, wavecolor);
    if (ok) {
        ui->waterwaveProgress->setWaterwaveColor(selectcolor);
        ui->ptn_waterwavecolor->setStyleSheet(QString("background:")+color2string(selectcolor));
    }
}

void MainWindow::on_ptn_bgcolor_clicked()
{
    QColor selectcolor;
    QColor bgcolor = ui->waterwaveProgress->bgColor();
    bool ok = selectColor(selectcolor, bgcolor);
    if (ok) {
        ui->waterwaveProgress->setBgColor(selectcolor);
        ui->ptn_bgcolor->setStyleSheet(QString("background:")+color2string(selectcolor));
    }
}

void MainWindow::on_ptn_textcolor_clicked()
{
    QColor selectcolor;
    QColor textcolor = ui->waterwaveProgress->textColor();
    bool ok = selectColor(selectcolor, textcolor);
    if (ok) {
        ui->waterwaveProgress->setTextColor(selectcolor);
        ui->ptn_textcolor->setStyleSheet(QString("background:")+color2string(selectcolor));
    }
}

QString MainWindow::color2string(QColor color)
{
    QString result = QString("rgb(%0,%1,%2)").arg(color.red()).arg(color.green()).arg(color.blue());
    return result;
}

bool MainWindow::selectColor(QColor &selectcolor,QColor currentcolor)
{
    QColorDialog dialog;
    dialog.setCurrentColor(currentcolor);
    if (dialog.exec() == QDialog::Accepted) {
        selectcolor = dialog.currentColor();
        return true;
    }

    return false;
}


void MainWindow::on_ptn_font_clicked()
{
    QFontDialog dialog;
    dialog.setCurrentFont(ui->waterwaveProgress->textFont());
    if (dialog.exec() == QDialog::Accepted) {
        QFont selectcolor = dialog.currentFont();
        ui->waterwaveProgress->setTextFont(selectcolor);
    }
}
