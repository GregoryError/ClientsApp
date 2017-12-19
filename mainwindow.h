#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QDesktopServices>
#include <QApplication>
#include <QtWidgets>
#include <QPainter>
#include <QDebug>
#include <QScrollArea>
#include <QScroller>
#include <QPixmap>
#include <QPalette>
#include <QLayout>
#include <QScrollBar>
#include <QListView>
#include <QFrame>
#include <QMap>

// Navigation

#include <QGeoRoute>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    QTabWidget *tab = new QTabWidget(this);

    ~MainWindow();
public slots:
    void CallSupp();
    void GoUrl();
    void GoSocial();
    void ScreenSpin();
    void PayPoints();
private slots:
    void NewsTab();
};

#endif // MAINWINDOW_H
