#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QRect rq = QApplication::desktop()->availableGeometry();
    if(rq.width() < rq.height())
    w.resize(rq.width(), rq.height());
    else
    {
        w.resize(rq.width() / 3, rq.height());

    }

    w.show();

    return a.exec();
}
