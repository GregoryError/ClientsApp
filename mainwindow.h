#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QApplication>
#include <QtWidgets>
#include <QScroller>
#include <QPixmap>
#include <QPalette>
#include <QScrollBar>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void CallSupp();
    void GoUrl();
    void GoSocial();
};

#endif // MAINWINDOW_H
