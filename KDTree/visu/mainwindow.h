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
    void paintEvent(QPaintEvent *e);
    //void wheelEvent ( QWheelEvent * event );

private:
    Ui::MainWindow *ui;
    qreal scale;
};

#endif // MAINWINDOW_H
