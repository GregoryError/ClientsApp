#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QRect rq = QApplication::desktop()->availableGeometry();

    QTabWidget *tab = new QTabWidget(this);
    //this->setStyleSheet("QWidget {background-image: url(:/background_2.png);}");

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
        wid = (rq.width() / 2) / 8;
        QSize deskSize(wid, rq.height() / 2);
        tab->setIconSize(deskSize);
    }

    tab->setStyleSheet("QTabBar::tab { width: 180px; }");
    tab->setStyleSheet("QTabBar::tab { height: 180px; }");

    ///////////////////////////////////////////////////////////////////


    QWidget *serv1 = new QWidget;

    QPixmap img(":/logo.png");
    auto logo = new QLabel;
    logo->setPixmap(img);

    auto right = new QLabel;

    right->setStyleSheet("QLabel {background-image: url(:/rightfield.png);}");

    QPushButton *butt = new QPushButton("Новости");
    butt->setStyleSheet("QPushButton {background-image: url(:/empty.png); font: 20pt Segoe UI;}");
    butt->setMaximumWidth(rq.width() / 3 );
 // QPushButton *butt1 = new QPushButton("Тарифы");
 // butt1->setStyleSheet("QPushButton {background-image: url(:/empty.png); font: 20pt Segoe UI;}");
 // butt1->setMaximumWidth(rq.width() / 3 );
    QPushButton *butt2 = new QPushButton("Cайт");
    butt2->setStyleSheet("QPushButton {background-image: url(:/empty.png); font: 20pt Segoe UI;}");
    butt2->setMaximumWidth(rq.width() / 3 );
    QPushButton *butt0 = new QPushButton("Соц. сети");
    butt0->setStyleSheet("QPushButton {background-image: url(:/empty.png); font: 20pt Segoe UI;}");
    butt0->setMaximumWidth(rq.width() / 3 );
    QPushButton *butt3 = new QPushButton("Мой счет");
    butt3->setStyleSheet("QPushButton {background-image: url(:/empty.png); font: 20pt Segoe UI;}");
    butt3->setMaximumWidth(rq.width() / 3 );
    QPushButton *butt4 = new QPushButton("Платежи");
    butt4->setStyleSheet("QPushButton {background-image: url(:/empty.png); font: 20pt Segoe UI;}");
    butt4->setMaximumWidth(rq.width() / 3 );
    QPushButton *butt5 = new QPushButton("Позвонить");
    butt5->setStyleSheet("QPushButton {background-image: url(:/empty.png); font: 20pt Segoe UI;}");
    butt5->setMaximumWidth(rq.width() / 3 );
    QVBoxLayout *VButtLyt = new QVBoxLayout;


    VButtLyt->addWidget(butt);
    //VButtLyt->addWidget(butt1);
    VButtLyt->addWidget(butt2);
    VButtLyt->addWidget(butt0);
    VButtLyt->addWidget(butt3);
    VButtLyt->addWidget(butt4);
    VButtLyt->addWidget(butt5);
   // VButtLyt->addWidget(butt6);


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
    QPushButton *pb = new QPushButton("Звонок в техподдержку");
    QPushButton *pb2 = new QPushButton("Перейти на сайт");
    QPushButton *pb3 = new QPushButton("Социальные сети");
    QPushButton *pb4 = new QPushButton("Заявка на мастера");

    QVBoxLayout *ly = new QVBoxLayout;
    ly->addWidget(pb);
    ly->addWidget(pb2);
    ly->addWidget(pb3);
    ly->addWidget(pb4);
    serv->setLayout(ly);
    serv->setStyleSheet("QWidget {background-image: url(:/background_2.png);}");

    tab->addTab(serv, QPixmap(":/Сервис.png"), NULL);

    QWidget *serv4 = new QWidget;
    QPushButton *pb4_1 = new QPushButton("Звонок в техподдержку");
    QPushButton *pb4_2 = new QPushButton("Перейти на сайт");
    QPushButton *pb4_3 = new QPushButton("Социальные сети");
    QPushButton *pb4_4 = new QPushButton("Заявка на мастера");

    QVBoxLayout *ly4 = new QVBoxLayout;
    ly4->addWidget(pb4_1);
    ly4->addWidget(pb4_2);
    ly4->addWidget(pb4_3);
    ly4->addWidget(pb4_4);
    serv4->setLayout(ly4);
    serv4->setStyleSheet("QWidget {background-image: url(:/background_2.png);}");

    tab->addTab(serv4, QPixmap(":/Настройки.png"), NULL);

    tab->resize(rq.width(), rq.height());

    this->connect(butt5, SIGNAL(clicked()), this, SLOT(CallSupp()));
    this->connect(butt2, SIGNAL(clicked()), this, SLOT(GoUrl()));
    this->connect(butt0, SIGNAL(clicked()), this, SLOT(GoSocial()));

    tab->show();
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

MainWindow::~MainWindow()
{

}







