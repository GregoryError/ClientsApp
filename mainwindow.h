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
#include <QString>
#include <QObject>
#include <QGeoPositionInfoSource>
#include "location.h"
#include <QVector>


// Navigation



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString latitude;
    QString longitude;
    QString maximumlat;
    QString maximumlong;
    MainWindow(QWidget *parent = 0);
    QTabWidget *tab = new QTabWidget(this);

   // QString latitude;
   // QString longitude;

    ~MainWindow();
public slots:
    void CallSupp();
    void GoUrl();
    void GoSocial();
    void ScreenSpin();
    void PayPoints();
    void OpenMap();
    void NewsTab();

    void showCoord();




};





#endif // MAINWINDOW_H








