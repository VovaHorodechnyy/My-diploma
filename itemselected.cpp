#include "itemselected.h"
#include "ui_itemselected.h"


ItemSelected::ItemSelected(QWidget* parent ,const QList<QVariant> &url):
    QWidget(parent),
    ui(new Ui::ItemSelected)
{



    ui->setupUi(this);
    if(url.at(0).toString() == "")
    {
        this->close();

    }
    m_sUrl = url.at(0).toString();
    CParser parser;
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url.at(0).toString())));
    QEventLoop event;
    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    QString html = response->readAll();
    CBigAd ad = parser.parse_bigad(html);
    set_pix_url(ad.get_ttl_img());
    ui->plainTextEdit->setPlainText(ad.get_descr());
    ui->lbl_price->setText(ad.get_price());
    ui->lbl_gpos->setText(url.at(1).toString());
    ui->lbl_numb->setText(ad.get_numb());
    ui->lbl_publ->setText(ad.get_publ());
    ui->lbl_ad_author->setText(ad.get_ad_author());
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    for(QString url: ad.get_vec())
    {
        add_img_2_list(url);
    }


    setWindowTitle(ad.get_ttl());
    fill_table(ad);





}
void ItemSelected::stop_act()
{
    int a = screen->is_hundred_per();
    if(screen->is_hundred_per() == 100){
        ptimer->stop();
        screen -> close();
        this->show();
        this->setFocus();
        delete screen;
        delete ptimer;
    }

}
void ItemSelected::fill_table(CBigAd & ad)
{

    ui->tableWidget_2->setRowCount(28);

    ui->tableWidget_2->setItem(0, 0, new QTableWidgetItem("Выберите рубрику"));
    ui->tableWidget_2->setItem(0, 1, new QTableWidgetItem(ad.get_hdng()));

    ui->tableWidget_2->setItem(1, 0, new QTableWidgetItem("Страна"));
    ui->tableWidget_2->setItem(1, 1, new QTableWidgetItem(ad.get_country()));

    ui->tableWidget_2->setItem(2, 0, new QTableWidgetItem("Минимальное количество ночей"));
    ui->tableWidget_2->setItem(2, 1, new QTableWidgetItem(ad.get_cnt_nights()));

    ui->tableWidget_2->setItem(3, 0, new QTableWidgetItem("Возможна сдача почасовой"));
    ui->tableWidget_2->setItem(3, 1, new QTableWidgetItem(ad.get_s_hourly()));

    ui->tableWidget_2->setItem(4, 0, new QTableWidgetItem("Тип дома"));
    ui->tableWidget_2->setItem(4, 1, new QTableWidgetItem(ad.get_type_h()));

    ui->tableWidget_2->setItem(5, 0, new QTableWidgetItem("Тип объекта"));
    ui->tableWidget_2->setItem(5, 1, new QTableWidgetItem(ad.get_type_o()));

    ui->tableWidget_2->setItem(6, 0, new QTableWidgetItem("Общая площадь"));
    ui->tableWidget_2->setItem(6, 1, new QTableWidgetItem(ad.get_total_area()));

    ui->tableWidget_2->setItem(7, 0, new QTableWidgetItem("Название ЖК"));
    ui->tableWidget_2->setItem(7, 1, new QTableWidgetItem(ad.get_lcd_name()));

    ui->tableWidget_2->setItem(8, 0, new QTableWidgetItem("Этаж"));
    ui->tableWidget_2->setItem(8, 1, new QTableWidgetItem(ad.get_floor()));

    ui->tableWidget_2->setItem(9, 0, new QTableWidgetItem("Этажность"));
    ui->tableWidget_2->setItem(9, 1, new QTableWidgetItem(ad.get_floor()));

    ui->tableWidget_2->setItem(10, 0, new QTableWidgetItem("Количество комнат"));
    ui->tableWidget_2->setItem(10, 1, new QTableWidgetItem(ad.get_floor()));

    ui->tableWidget_2->setItem(11, 0, new QTableWidgetItem("Количество спальных мест"));
    ui->tableWidget_2->setItem(11, 1, new QTableWidgetItem(ad.get_floor()));

    ui->tableWidget_2->setItem(12, 0, new QTableWidgetItem("Питание"));
    ui->tableWidget_2->setItem(12, 1, new QTableWidgetItem(ad.get_nutrition()));

    ui->tableWidget_2->setItem(13, 0, new QTableWidgetItem("Санузел"));
    ui->tableWidget_2->setItem(13, 1, new QTableWidgetItem(ad.get_bathroom()));

    ui->tableWidget_2->setItem(14, 0, new QTableWidgetItem("Ремонт"));
    ui->tableWidget_2->setItem(14, 1, new QTableWidgetItem(ad.get_repairs()));

    ui->tableWidget_2->setItem(15, 0, new QTableWidgetItem("Бытовая техника"));
    ui->tableWidget_2->setItem(15, 1, new QTableWidgetItem(ad.get_appliances()));

    ui->tableWidget_2->setItem(16, 0, new QTableWidgetItem("Мультимедиа"));
    ui->tableWidget_2->setItem(16, 1, new QTableWidgetItem(ad.get_meadia()));

    ui->tableWidget_2->setItem(17, 0, new QTableWidgetItem("Комфорт"));
    ui->tableWidget_2->setItem(17, 1, new QTableWidgetItem(ad.get_comfort()));

    ui->tableWidget_2->setItem(18, 0, new QTableWidgetItem("Инфраструктура (до 500 метров)"));
    ui->tableWidget_2->setItem(18, 1, new QTableWidgetItem(ad.get_infrst()));

    ui->tableWidget_2->setItem(19, 0, new QTableWidgetItem("Ландшафт (до 1 км.)"));
    ui->tableWidget_2->setItem(19, 1, new QTableWidgetItem(ad.get_landscape()));

    ui->tableWidget_2->setItem(20, 0, new QTableWidgetItem("Готов сотрудничать с риэлторами"));
    ui->tableWidget_2->setItem(20, 1, new QTableWidgetItem(ad.get_coop_real()));

    ui->tableWidget_2->setItem(21, 0, new QTableWidgetItem("Кредитование"));
    ui->tableWidget_2->setItem(21, 1, new QTableWidgetItem(ad.get_crediting()));

    ui->tableWidget_2->setItem(22, 0, new QTableWidgetItem("Коммуникации"));
    ui->tableWidget_2->setItem(22, 1, new QTableWidgetItem(ad.get_comunication()));

    ui->tableWidget_2->setItem(23, 0, new QTableWidgetItem("Отопление"));
    ui->tableWidget_2->setItem(23, 1, new QTableWidgetItem(ad.get_htng()));

    ui->tableWidget_2->setItem(24, 0, new QTableWidgetItem("Планировка"));
    ui->tableWidget_2->setItem(24, 1, new QTableWidgetItem(ad.get_layout()));

    ui->tableWidget_2->setItem(25, 0, new QTableWidgetItem("Площадь кухни"));
    ui->tableWidget_2->setItem(25, 1, new QTableWidgetItem(ad.get_kitchen_area()));

    ui->tableWidget_2->setItem(26, 0, new QTableWidgetItem("Год постройки / сдачи"));
    ui->tableWidget_2->setItem(26, 1, new QTableWidgetItem(ad.get_year_c_d()));

    ui->tableWidget_2->setItem(27, 0, new QTableWidgetItem("Планировка"));
    ui->tableWidget_2->setItem(27, 1, new QTableWidgetItem(ad.get_layout()));


}
void ItemSelected::add_img_2_list(const QString &url)
{
    if(url != "")
    {
        QNetworkAccessManager manager;
        QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
        QEventLoop event;
        connect(response,SIGNAL(finished()),&event,SLOT(quit()));
        event.exec();
        QByteArray jpegData = response->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(jpegData);

        QLabel *lbl = new QLabel;
        QWidget* wgt = new QWidget;
        QLayout* l = new QHBoxLayout;
        lbl->setPixmap(pixmap.scaled(400,390));
        l->addWidget(lbl);
        wgt->setLayout( l );
        QListWidgetItem* item = new QListWidgetItem( ui->listWidget );
        item->setSizeHint( wgt->sizeHint() );
        ui->listWidget->setItemWidget( item, wgt );


    }
}
void ItemSelected::set_pix_url(const QString & url_img)
{
    if(url_img != "")
    {
        QNetworkAccessManager manager;
        QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url_img)));
        QEventLoop event;
        connect(response,SIGNAL(finished()),&event,SLOT(quit()));
        event.exec();
        QByteArray jpegData = response->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(jpegData);
        ui->title_img->setPixmap(pixmap.scaled(400,390));
    }
    else
    {
        QPixmap img(":images/no_image.png");

        ui->title_img->setPixmap(img.scaled(300,280));

    }


}
ItemSelected::ItemSelected(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemSelected)
{
    ui->setupUi(this);
    QPixmap img(":images/no_image.png");

    ui->title_img->setPixmap(img.scaled(300,280));


//    QNetworkAccessManager manager;
//    QNetworkReply *response = manager.get(QNetworkRequest(QUrl("https://www.olx.ua/obyavlenie/vigdna-tsna-na-2-kmn-levada-zatishna-IDAHihA.html#fadc77ba12;promoted")));
//    QEventLoop event;
//    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
//    event.exec();
//    QString html = response->readAll();
//    CParser a ;
//    CBigAd Ad = a.parse_bigad(html);
//    int b = 5;
//    b++;

















}

ItemSelected::~ItemSelected()
{
    delete ui;
}

void ItemSelected::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl(m_sUrl));
}
