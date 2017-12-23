#include "mainwindow.h"

#include <QGeoPositionInfoSource>


struct Button                                                       // Making buttons
{                                                                   // Making buttons
    QPushButton *butt = new QPushButton;                            // Making buttons
    Button() = default;                                             // Making buttons
    Button(const QString &name, QRect &size)                        // Making buttons
    {                                                               // Making buttons
        butt->setText(name);
        butt->setStyleSheet("QPushButton {color: white;"
                            "background-image: url(:/empty.png);"
                            " background-image: url(:/empty.png);"
                            " border-style: outset;"
                            " border-width: 3px;"
                            " border-radius: 10px;"
                            " border-color: beige;"
                            " font:  50px Segoe UI;"
                            " min-width: 10em;"
                            " padding: 6px;}");
        butt->setMaximumWidth(size.width() / 3 );                   // Making buttons
        butt->setMinimumHeight(size.height() / 13);                 // Making buttons
    }
};




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QRect rq = QApplication::desktop()->availableGeometry();



    int wid(0);
    if(rq.width() < rq.height())
    {
        tab->setTabPosition(QTabWidget::South);
        wid = (rq.width()-20) / 5;
        QSize size(wid, wid);
        tab->setIconSize(size);
   }
    else
    {
        tab->setTabPosition(QTabWidget::East);
        wid = (rq.width() / 2) / 8;
        QSize deskSize(wid, rq.height() / 2);
        tab->setIconSize(deskSize);
    }

    tab->setStyleSheet("QTabBar::tab { width: 180px; }");
    tab->setStyleSheet("QTabBar::tab { height: 180px; }");

    this->resize(400, 400);

    QWidget *serv1 = new QWidget;

    QPixmap img(":/logo.png");
    auto logo = new QLabel;
    logo->setPixmap(img);

    auto right = new QLabel;

    right->setStyleSheet("QLabel {background-image: url(:/rightfield.png);}");

    Button butt("Новости", rq), butt1("Сайт", rq), butt2("Соц. сети", rq), butt3("Оплата", rq), butt4("Позвонить нам", rq);

    QVBoxLayout *VButtLyt = new QVBoxLayout;

    VButtLyt->addWidget(butt.butt);
    VButtLyt->addWidget(butt1.butt);
    VButtLyt->addWidget(butt2.butt);
    VButtLyt->addWidget(butt3.butt);
    VButtLyt->addWidget(butt4.butt);

    QVBoxLayout *main = new QVBoxLayout;
    QHBoxLayout *vll = new QHBoxLayout;
    vll->addWidget(right);
    vll->addWidget(logo);
    vll->addWidget(right);
    main->addLayout(vll);


    QHBoxLayout *Btn_in_lft = new QHBoxLayout;
    logo->setStyleSheet("QLabel {background-image: url(:/empty.png);}");  // этот мопед работает!

    Btn_in_lft->addLayout(VButtLyt);
    Btn_in_lft->addWidget(right);

    main->addLayout(Btn_in_lft);
    serv1->setLayout(main);

    serv1->setStyleSheet("QWidget {background-image: url(:/background_2.png);}");

                                              //////////////////////////////////////////////// Creating the first tab

    tab->addTab(serv1, QPixmap(":/Начало.png"), NULL);


    QScrollArea* sa = new QScrollArea;                                       // Scroll pattern take begin here
    sa->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sa->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QScroller::grabGesture(sa->viewport(), QScroller::LeftMouseButtonGesture);
    QPixmap img2(":/description.jpg");
    auto wgt = new QWidget;
    QPalette pal;
    pal.setBrush(wgt->backgroundRole(), QBrush(img2));
    wgt->setPalette(pal);
    wgt->setAutoFillBackground(true);
    wgt->setFixedSize(img2.width(), img2.height());
    sa->setWidgetResizable(true);
    sa->verticalScrollBar()->setSingleStep(1);
    sa->setWidget(wgt);
    //sa->setStyleSheet("QScrollArea {image: url(:/empty.png);}");

    tab->addTab(sa, QPixmap(":/Акаунт.png"), NULL);     // Передаем скролл на вторую вкладку

    QWidget *serv = new QWidget;

    Button pb("Ближайшие точки оплат", rq),
           pb1("Обещанный платеж", rq),
           pb2("История платежей", rq),
           pb3("Заявка на мастера", rq),
           pb4("Чат с техподдержкой", rq),
           pb5("Управление доступом", rq);

    QVBoxLayout *ly = new QVBoxLayout;
    ly->addWidget(pb.butt);
    ly->addWidget(pb1.butt);
    ly->addWidget(pb2.butt);
    ly->addWidget(pb3.butt);
    ly->addWidget(pb4.butt);
    ly->addWidget(pb5.butt);

    serv->setLayout(ly);
    serv->setStyleSheet("QWidget {background-image: url(:/background_2.png);}");

    tab->addTab(serv, QPixmap(":/Сервис.png"), NULL);

    QWidget *serv4 = new QWidget;

    QString *text = new QString;

    auto source = QGeoPositionInfoSource::createDefaultSource(this);
    if(source){
    text->append("sourceName: " + source->sourceName()); //return: core location
    source->setPreferredPositioningMethods(QGeoPositionInfoSource::AllPositioningMethods);
    source->startUpdates();
    source->setUpdateInterval(1000);
    source->requestUpdate();
    }

    QLabel *lbl = new QLabel;
    QGeoPositionInfo info = source->lastKnownPosition();
    QGeoCoordinate coordinate = info.coordinate();
    latitude = QString::number(coordinate.latitude(), 'f', 6);
    longitude = QString::number(coordinate.longitude(), 'f', 6);
    QString all(*text);


    all += " Coordinates: ";
    all += latitude;
    all += ",";
    all += longitude;
    lbl->setText(all);



   location owner(latitude, longitude);











    Button
           pb6("Координаты", rq),
           pb7("Настройки дизайна", rq),
           pb8("Публичный договор", rq);




//    lbl->setStyleSheet("QLabel {color: white;"
//                       " background-image: url(:/empty.png);"
//                       " border-style: outset;"
//                       " border-width: 5px;"
//                       " border-radius: 30px;"
//                       " border-color: beige;"
//                       " font:  60px Segoe UI;"
//                       " min-width: 10em;"
//                       " padding: 6px;}");
//
    QVBoxLayout *ly4 = new QVBoxLayout;
    ly4->addWidget(lbl);
    ly4->addWidget(pb6.butt);
    ly4->addWidget(pb7.butt);
    ly4->addWidget(pb8.butt);
    serv4->setLayout(ly4);
    serv4->setStyleSheet("QWidget {background-image: url(:/background_2.png);}");


    tab->addTab(serv4, QPixmap(":/Настройки.png"), NULL);

    tab->resize(rq.width(), rq.height());

    this->connect(butt4.butt, SIGNAL(clicked()), this, SLOT(CallSupp()));
    this->connect(butt1.butt, SIGNAL(clicked()), this, SLOT(GoUrl()));
    this->connect(butt2.butt, SIGNAL(clicked()), this, SLOT(GoSocial()));
    this->connect(butt.butt, SIGNAL(clicked()), this, SLOT(NewsTab()));
    this->connect(pb.butt, SIGNAL(clicked()), this, SLOT(PayPoints()));

    connect(pb6.butt, SIGNAL(clicked()), this, SLOT(showCoord()));


    QApplication::primaryScreen()->setOrientationUpdateMask(Qt::PortraitOrientation | Qt::LandscapeOrientation);
    QApplication::connect(QApplication::primaryScreen(), SIGNAL(orientationChanged(Qt::ScreenOrientation)), this, SLOT(ScreenSpin()));

    tab->show();
}



void MainWindow::showCoord()
{

    QString all;
    all = latitude;
    all += ",";
    all += longitude;

    QString URL("https://www.google.ru/maps/place/" + all);

    QUrl myUrl(URL);
    QDesktopServices::openUrl(myUrl);

}











void MainWindow::OpenMap()
{
   // QString URL("https://www.google.ru/maps/@"); //
   // QString b = QString::number(lng, 'f', 10);
   // QString a = QString::number(lat, 'f', 10);
   //
   //
   // URL += a;
   // URL += ",";
   // URL += b;
   //
   // QUrl myUrl(URL);
   // QDesktopServices::openUrl(myUrl);
}








void MainWindow::PayPoints()
{

    QString URL("https://www.google.ru/maps/@");

    QUrl myUrl(URL);
    QDesktopServices::openUrl(myUrl);
}


void MainWindow::NewsTab()
{
    tab->setCurrentIndex(1);
}


void MainWindow::CallSupp()
{
    QDesktopServices::openUrl(QUrl("tel:+78137898098"));
}

void MainWindow::GoUrl()
{
    QUrl myUrl("http://vbg.arriva.net.ru/");
    QDesktopServices::openUrl(myUrl);
}

void MainWindow::GoSocial()
{
    QUrl myUrl("https://vk.com/arrivanet");
    QDesktopServices::openUrl(myUrl);
}

void MainWindow::ScreenSpin()
{
    QRect rq = QApplication::desktop()->availableGeometry();
    tab->resize(rq.width(), rq.height());
    int wid(0);
    if(rq.width() < rq.height())
    {
        tab->setTabPosition(QTabWidget::South);
        wid = (rq.width()-20) / 5;
        QSize size(wid, wid);
        tab->setIconSize(size);
   }
    else
    {
        tab->setTabPosition(QTabWidget::East);
        wid = (rq.width() / 2) / 8;
        QSize deskSize(wid, rq.height() / 2);
        tab->setIconSize(deskSize);
    }
    tab->setStyleSheet("QTabBar::tab { width: 180px; }");
    tab->setStyleSheet("QTabBar::tab { height: 180px; }");
}


MainWindow::~MainWindow()
{

}








