#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initViewDefault();
    void initStyle();

private slots:  
    void on_spinBox_size_editingFinished();

    void on_spinBox_borderwidth_editingFinished();

    void on_comboBox_shape_currentIndexChanged(int index);

    void on_spinBox_percent_editingFinished();

    void on_spinBox_wavewidth_editingFinished();

    void on_spinBox_waveheight_editingFinished();

    void on_ptn_bordercolor_clicked();

    void on_ptn_waterwavecolor_clicked();

    void on_ptn_bgcolor_clicked();

    void on_ptn_textcolor_clicked();

    void on_ptn_font_clicked();

private:
    Ui::MainWindow *ui;

private:
    QString color2string(QColor color);
    bool selectColor(QColor &selectcolor, QColor currentcolor);
};

#endif // MAINWINDOW_H
