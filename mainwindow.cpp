#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    m_listAds = read_xml();
    m_listUrls = new QList<URLParametres>;
    m_listHAd = new  QList<CHistoryAd> ;;
    ui->radioButton_5->setChecked(true);
    ui->listWidget->setResizeMode(QListWidget::Adjust);
    ui->listWidget->setIconSize(QSize(170,132));
    ui->listWidget->setAcceptDrops(true);
    ui->listWidget->setDragEnabled(false);
    m_vecHomeAds = new QVector<CAdHome>;
    fill_cmb_regions();
    connect( ui -> comboBoxRegions ,
            SIGNAL(currentIndexChanged(const QString&)) ,
            this ,
            SLOT(switchcall(const QString&))) ;
    load_home();
    m_nCurrentPage = 1;
    ui->lineEdit_3->setText(QString::number(m_nCurrentPage));
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    setStyle(QStyleFactory::create("QFusionStyle"));
    //dark style
    QPalette p = qApp->palette();
    p.setColor(QPalette::Window, QColor(0, 28, 53));
    p.setColor(QPalette::Button, QColor(0, 28, 53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    p.setColor(QPalette::WindowText, QColor(255,255,255));
    qApp->setPalette(p);
    //
    qDebug() << QSslSocket::supportsSsl();
    ui->lineEdit_3->setValidator( new QIntValidator(0, 1000, this) );
    ui->lineEdit->setValidator( new QIntValidator(0, 10000000, this) );
    ui->lineEdit_2->setValidator( new QIntValidator(0, 10000000, this) );

    //ui->listWidget->items

    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    if(!fileExists(PATH_FILE))
    {
        QFile file(PATH_FILE);
        file.open(QIODevice::WriteOnly);
        file.close();

    }
    ui->comboBoxCityRegion->hide();


}
void MainWindow::closeEvent (QCloseEvent *event)
{


        write_xml(*m_listAds);
        QWidget::closeEvent(event);

}
bool MainWindow::fileExists(QString path) {
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::load_home(const QString& aUrl )
{
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(aUrl)));
    QEventLoop event;
    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    QString html = response->readAll();
    QString end_s = "</table>";
    m_sCurrentURL = aUrl;
    size_t pos_id = html.indexOf("id=\"offers_table\"");
    size_t pos_table = html.indexOf("<table ",pos_id - 150);
    size_t bedfore_end = html.indexOf("adcontainer-tr",pos_id);
    size_t pos_end = html.indexOf(end_s,bedfore_end);
    m_vecHomeAds->clear();
    QString html_table = html.mid( pos_table , pos_end - pos_table + end_s.length()  );
    QStringList array = html_table.split("<tr class=\"wrap\"\n    rel=\"\" >");
    fill_vector(array);
    const std::size_t size = m_vecHomeAds -> size();
    ui->listWidget->clear();
    for(std::size_t ix = 0; ix < size ; ++ix)
    {
        CAdHome tmp = m_vecHomeAds->at(ix);
        // img
        const QIcon iconNoPhoto = QIcon::fromTheme("document-new", QIcon(":/images/no_image.png"));

        //img
        QListWidgetItem *item = new QListWidgetItem;
        if(ix == m_vecHomeAds->size() - 1)
        {

            QNetworkReply *response1 = manager.get(QNetworkRequest(QUrl(tmp.getUrl())));
            QEventLoop event1;
            connect(response1,SIGNAL(finished()),&event1,SLOT(quit()));
            event1.exec();
            QString html1 = response1->readAll();
            CBigAd b_ad = CParser::parse_bigad(html1);
            tmp.setImg(b_ad.get_ttl_img());
        }
        if(tmp.getImg() != "")
        {
            QNetworkReply *response_img = manager.get(QNetworkRequest(QUrl(tmp.getImg())));
            QEventLoop event_img;
            connect(response_img,SIGNAL(finished()),&event_img,SLOT(quit()));
            event_img.exec();
            QByteArray jpegData = response_img->readAll();
            QPixmap pixmap;
            pixmap.loadFromData(jpegData);
            QIcon *icon = new QIcon(pixmap);
            item->setIcon(*icon);
        }

        else
        {
            item->setIcon(iconNoPhoto);
        }
        QList<QVariant> qlist;
        qlist.push_back(tmp.getUrl());
        qlist.push_back(tmp.getGeoPos());
        qlist.push_back(tmp.getImg());
        qlist.push_back(tmp.getTitle());
        QVariant fullFilePathData(qlist);
        item->setData(Qt::UserRole, fullFilePathData);
        if(ui->listWidget->viewMode() == QListWidget::IconMode)
        {
            item->setTextAlignment(Qt::AlignLeft|Qt::AlignBottom);
            item->setSizeHint(QSize(200, 220));
            item->setText(tmp.getTitle());
        }
        else
        {
            item->setText(tmp.getTitle() + "\n" + tmp.getGeoPos() + "\n"+tmp.getSmalDescr() + "\n" + tmp.getPublicated() +"\n" + tmp.getPrice());
        }
        ui->listWidget->addItem(item);
        //ui->listWidget->addItem(array.at(ix));
    }

    ui->lineEdit_3->setText(QString::number(m_nCurrentPage));
}
void MainWindow::on_pushButton_clicked()
{
    URLParametres prms;
    if(ui->radioButton->isChecked())
        prms.fIsNew = true;
    if(ui->radioButton2->isChecked())
        prms.fIsCheap = true;
    if(ui->radioButton3->isChecked())
        prms.fIsExpensive = true;
    if(ui->checkBox->isChecked())
        prms.fIsInTtlNDesc = true;
    if(ui->checkBox_2->isChecked())
        prms.fIsPhoto = true;
    if(ui->lineEdit->text() != "")
        prms.nPriceFrom = ui->lineEdit->text().toInt();
    if(ui->lineEdit_2->text() != "")
        prms.nPriceTo = ui->lineEdit_2->text().toInt();
    if(ui->lineEdit_4->text() != "")
        prms.sSearch = ui->lineEdit_4->text();
    if(ui->radioButton_2->isChecked())
        prms.sCurrency = "";
    if(ui->radioButton_3->isChecked())
        prms.sCurrency = "USD";
    if(ui->radioButton_4->isChecked())
        prms.sCurrency = "EUR";
    prms.sRegion = ui->comboBoxRegions->currentText();
    prms.sCity = ui->comboBoxCity->currentText();
    prms.sCityRegion = ui->comboBoxCityRegion->currentText();
    m_sCurrentURL = m_objUrlBuilder.get_url_f_pararam(prms);
    m_nCurrentPage = 1;
    m_listUrls->push_back(prms);
    load_home(m_sCurrentURL);
//    QNetworkAccessManager manager;
//    QNetworkReply *response = manager.get(QNetworkRequest(QUrl("https://www.olx.ua/nedvizhimost/q-%D0%9B%D1%8C%D0%B2%D1%96%D0%B2/")));
//    QEventLoop event;
//    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
//    event.exec();
//    QString html = response->readAll();
//    QString end_s = "</table>";

//    size_t pos_id = html.indexOf("id=\"offers_table\"");
//    size_t pos_table = html.indexOf("<table ",pos_id - 150);
//    size_t bedfore_end = html.indexOf("adcontainer-tr",pos_id);
//    size_t pos_end = html.indexOf(end_s,bedfore_end);

//    QString html_table = html.mid( pos_table , pos_end - pos_table + end_s.length()  );
//    QStringList array = html_table.split("<tr class=\"wrap\"\n    rel=\"\" >");
//    fill_vector(array);
//    const std::size_t size = m_vecHomeAds -> size();
//    for(std::size_t ix = 0; ix < size ; ++ix)
//    {
//        CAdHome tmp = m_vecHomeAds->at(ix);
//        ui->listWidget->addItem(tmp.to_string());
//        //ui->listWidget->addItem(array.at(ix));
//    }

}
void MainWindow::fill_vector(QStringList& aList)
{
    const std::size_t size = aList.size();
    CParser parser;
    for(std::size_t ix = 1; ix < size ; ++ix)
    {

        m_vecHomeAds->push_back(parser.parse(aList.at(ix)));
    }

}
void MainWindow::replyFini(QNetworkReply* reply)
{
    QString answer = QString::fromUtf8(reply->readAll());
    qDebug() << "answer------------>"<<answer;
}
void MainWindow::fill_cmb_regions()
{
   ui->comboBoxRegions->addItem("");
   ui->comboBoxRegions->addItem("Винницкая область");
   ui->comboBoxRegions->addItem("Волынская область");
   ui->comboBoxRegions->addItem("Днепропетровская область");
   ui->comboBoxRegions->addItem("Донецкая область");
   ui->comboBoxRegions->addItem("Житомирская область");
   ui->comboBoxRegions->addItem("Закарпатская область");
   ui->comboBoxRegions->addItem("Запорожская область");
   ui->comboBoxRegions->addItem("Ивано-Франковская область");
   ui->comboBoxRegions->addItem("Киевская область");
   ui->comboBoxRegions->addItem("Кировоградская область");
   ui->comboBoxRegions->addItem("Крым (АРК)");
   ui->comboBoxRegions->addItem("Луганская область");
   ui->comboBoxRegions->addItem("Львовская область");
   ui->comboBoxRegions->addItem("Николаевская область");
   ui->comboBoxRegions->addItem("Одесская область");
   ui->comboBoxRegions->addItem("Полтавская область");
   ui->comboBoxRegions->addItem("Ровенская область");
   ui->comboBoxRegions->addItem("Сумская область");
   ui->comboBoxRegions->addItem("Тернопольская область");
   ui->comboBoxRegions->addItem("Харьковская область");
   ui->comboBoxRegions->addItem("Хмельницкая область");
   ui->comboBoxRegions->addItem("Херсонская область");
   ui->comboBoxRegions->addItem("Черкасская область");
   ui->comboBoxRegions->addItem("Черниговская область");
   ui->comboBoxRegions->addItem("Черновицкая область");
}
void MainWindow::switchcall(const QString& s)
{
    ui->comboBoxCity->clear();
    ui->comboBoxCity->addItem("Искать по всей области »");
    if(s == "Винницкая область")
        fill_cmb_vin();
    if(s == "Волынская область")
        fill_cmb_vol();
    if(s == "Днепропетровская область")
        fill_cmb_dnp();
    if(s == "Донецкая область")
        fill_cmb_don();
    if(s == "Житомирская область")
        fill_cmb_zht();
    if(s == "Закарпатская область")
        fill_cmb_zak();
    if(s == "Запорожская область")
        fill_cmb_zap();
    if(s == "Ивано-Франковская область")
        fill_cmb_if();
    if(s == "Киевская область")
        fill_cmb_ko();
    if(s == "Кировоградская область")
        fill_cmb_kir();
    if(s == "Крым (АРК)")
        fill_cmb_cri();
    if(s == "Луганская область")
        fill_cmb_lug();
    if(s == "Львовская область")
        fill_cmb_lv();
    if(s == "Николаевская область")
        fill_cmb_nik();
    if(s == "Одесская область")
        fill_cmb_od();
    if(s == "Полтавская область")
        fill_cmb_pol();
    if(s == "Ровенская область")
        fill_cmb_rov();
    if(s == "Сумская область")
        fill_cmb_sum();
    if(s == "Тернопольская область")
        fill_cmb_ter();
    if(s == "Харьковская область")
        fill_cmb_kha();
    if(s == "Херсонская область")
        fill_cmb_khe();
    if(s == "Хмельницкая область")
        fill_cmb_khm();
    if(s == "Черкасская область")
        fill_cmb_chk();
    if(s == "Черниговская область")
        fill_cmb_chn();
    if(s == "Черновицкая область")
        fill_cmb_chv();
}
void MainWindow::fill_cmb_vin()
{
    ui->comboBoxCity->addItem("Бар");
    ui->comboBoxCity->addItem("Бершадь");
    ui->comboBoxCity->addItem("Винница");
    ui->comboBoxCity->addItem("Гайсин");
    ui->comboBoxCity->addItem("Гнивань");
    ui->comboBoxCity->addItem("Жмеринка");
    ui->comboBoxCity->addItem("Ильинцы");
    ui->comboBoxCity->addItem("Казатин");
    ui->comboBoxCity->addItem("Калиновка");
    ui->comboBoxCity->addItem("Крыжополь");
    ui->comboBoxCity->addItem("Ладыжин");
    ui->comboBoxCity->addItem("Липовец");
    ui->comboBoxCity->addItem("Могилев-Подольский");
    ui->comboBoxCity->addItem("Немиров");
    ui->comboBoxCity->addItem("Песочин");
    ui->comboBoxCity->addItem("Погребище");
    ui->comboBoxCity->addItem("Стрижавка");
    ui->comboBoxCity->addItem("Тульчин");
    ui->comboBoxCity->addItem("Хмельник");
    ui->comboBoxCity->addItem("Чечельник");
    ui->comboBoxCity->addItem("Шаргород");
    ui->comboBoxCity->addItem("Ямполь");
}
void MainWindow::fill_cmb_vol()
{
     ui->comboBoxCity->addItem("Берестечко");
     ui->comboBoxCity->addItem("Владимир-Волынский");
     ui->comboBoxCity->addItem("Горохов");
     ui->comboBoxCity->addItem("Иваничи");
     ui->comboBoxCity->addItem("Камень-Каширский");
     ui->comboBoxCity->addItem("Киверцы");
     ui->comboBoxCity->addItem("Ковель");
     ui->comboBoxCity->addItem("Луцк");
     ui->comboBoxCity->addItem("Любешов");
     ui->comboBoxCity->addItem("Любомль");
     ui->comboBoxCity->addItem("Маневичи");
     ui->comboBoxCity->addItem("Нововолынск");
     ui->comboBoxCity->addItem("Ратно");
     ui->comboBoxCity->addItem("Рожище");
     ui->comboBoxCity->addItem("Старая Выжевка");
     ui->comboBoxCity->addItem("Турийск");
     ui->comboBoxCity->addItem("Устилуг");
     ui->comboBoxCity->addItem("Цумань");
     ui->comboBoxCity->addItem("Шацк");
}
void MainWindow::fill_cmb_dnp()
{
    ui->comboBoxCity->addItem("Апостолово");
    ui->comboBoxCity->addItem("Верхнеднепровск");
    ui->comboBoxCity->addItem("Вольногорск");
    ui->comboBoxCity->addItem("Днепр");
    ui->comboBoxCity->addItem("Желтые Воды");
    ui->comboBoxCity->addItem("Каменское");
    ui->comboBoxCity->addItem("Кривой Рог");
    ui->comboBoxCity->addItem("Марганец");
    ui->comboBoxCity->addItem("Никополь");
    ui->comboBoxCity->addItem("Новомосковск");
    ui->comboBoxCity->addItem("Орджоникидзе");
    ui->comboBoxCity->addItem("Павлоград");
    ui->comboBoxCity->addItem("Перещепино");
    ui->comboBoxCity->addItem("Першотравенск");
    ui->comboBoxCity->addItem("Подгородное");
    ui->comboBoxCity->addItem("Пятихатки");
    ui->comboBoxCity->addItem("Синельниково");
    ui->comboBoxCity->addItem("Терновка");
    ui->comboBoxCity->addItem("Чаплинка");
}
void MainWindow::fill_cmb_don()
{
    //37
    ui->comboBoxCity->addItem("Авдеевка");
    ui->comboBoxCity->addItem("Александровка");
    ui->comboBoxCity->addItem("Амвросиевка");
    ui->comboBoxCity->addItem("Артемовск");
    ui->comboBoxCity->addItem("Волноваха");
    ui->comboBoxCity->addItem("Горловка");
    ui->comboBoxCity->addItem("Дебальцево");
    ui->comboBoxCity->addItem("Дзержинск");
    ui->comboBoxCity->addItem("Димитров");
    ui->comboBoxCity->addItem("Доброполье");
    ui->comboBoxCity->addItem("Докучаевск");
    ui->comboBoxCity->addItem("Донецк");
    ui->comboBoxCity->addItem("Дружковка");
    ui->comboBoxCity->addItem("Енакиево");
    ui->comboBoxCity->addItem("Ждановка");
    ui->comboBoxCity->addItem("Зугрэс");
    ui->comboBoxCity->addItem("Кировское");
    ui->comboBoxCity->addItem("Константиновка");
    ui->comboBoxCity->addItem("Краматорск");
    ui->comboBoxCity->addItem("Красноармейск");
    ui->comboBoxCity->addItem("Красный Лиман");
    ui->comboBoxCity->addItem("Майорск");
    ui->comboBoxCity->addItem("Макеевка");
    ui->comboBoxCity->addItem("Мариуполь");
    ui->comboBoxCity->addItem("Марьинка");
    ui->comboBoxCity->addItem("Новоазовск");
    ui->comboBoxCity->addItem("Новогродовка");
    ui->comboBoxCity->addItem("Селидово");
    ui->comboBoxCity->addItem("Славянск");
    ui->comboBoxCity->addItem("Снежное");
    ui->comboBoxCity->addItem("Соледар");
    ui->comboBoxCity->addItem("Старобешево");
    ui->comboBoxCity->addItem("Торез");
    ui->comboBoxCity->addItem("Угледар");
    ui->comboBoxCity->addItem("Харцызск");
    ui->comboBoxCity->addItem("Шахтерск");
    ui->comboBoxCity->addItem("Ясиноватая");
}
void MainWindow::fill_cmb_zht()
{
    ui->comboBoxCity->addItem("Андрушевка");
    ui->comboBoxCity->addItem("Барановка");
    ui->comboBoxCity->addItem("Бердичев");
    ui->comboBoxCity->addItem("Володарск-Волынский");
    ui->comboBoxCity->addItem("Емильчино");
    ui->comboBoxCity->addItem("Житомир");
    ui->comboBoxCity->addItem("Иршанск");
    ui->comboBoxCity->addItem("Коростень");
    ui->comboBoxCity->addItem("Коростышев");
    ui->comboBoxCity->addItem("Малин");
    ui->comboBoxCity->addItem("Новоград-Волынский");
    ui->comboBoxCity->addItem("Овруч");
    ui->comboBoxCity->addItem("Олевск");
    ui->comboBoxCity->addItem("Попельня");
    ui->comboBoxCity->addItem("Радомышль");
    ui->comboBoxCity->addItem("Романов");
    ui->comboBoxCity->addItem("Черняхов");
}
void MainWindow::fill_cmb_zak()
{
    ui->comboBoxCity->addItem("Берегово");
    ui->comboBoxCity->addItem("Буштына");
    ui->comboBoxCity->addItem("Великий Бычков");
    ui->comboBoxCity->addItem("Виноградов");
    ui->comboBoxCity->addItem("Вышково");
    ui->comboBoxCity->addItem("Дубовое");
    ui->comboBoxCity->addItem("Иршава");
    ui->comboBoxCity->addItem("Королево");
    ui->comboBoxCity->addItem("Межгорье");
    ui->comboBoxCity->addItem("Мукачево");
    ui->comboBoxCity->addItem("Перечин");
    ui->comboBoxCity->addItem("Рахов");
    ui->comboBoxCity->addItem("Свалява");
    ui->comboBoxCity->addItem("Солотвина");
    ui->comboBoxCity->addItem("Тячев");
    ui->comboBoxCity->addItem("Ужгород");
    ui->comboBoxCity->addItem("Хуст");
    ui->comboBoxCity->addItem("Чоп");
}
void MainWindow::fill_cmb_zap()
{
    ui->comboBoxCity->addItem("Акимовка");
    ui->comboBoxCity->addItem("Беляевка");
    ui->comboBoxCity->addItem("Бердянск");
    ui->comboBoxCity->addItem("Васильевка");
    ui->comboBoxCity->addItem("Веселое");
    ui->comboBoxCity->addItem("Вольнянск");
    ui->comboBoxCity->addItem("Гуляйполе");
    ui->comboBoxCity->addItem("Днепрорудное");
    ui->comboBoxCity->addItem("Запорожье");
    ui->comboBoxCity->addItem("Каменка-Днепровская");
    ui->comboBoxCity->addItem("Куйбышево");
    ui->comboBoxCity->addItem("Кушугум");
    ui->comboBoxCity->addItem("Мелитополь");
    ui->comboBoxCity->addItem("Михайловка");
    ui->comboBoxCity->addItem("Молочанск");
    ui->comboBoxCity->addItem("Орехов");
    ui->comboBoxCity->addItem("Пологи");
    ui->comboBoxCity->addItem("Приморск");
    ui->comboBoxCity->addItem("Розовка");
    ui->comboBoxCity->addItem("Токмак");
    ui->comboBoxCity->addItem("Энергодар");
}
void MainWindow::fill_cmb_if()
{
    ui->comboBoxCity->addItem("Богородчаны");
    ui->comboBoxCity->addItem("Болехов");
    ui->comboBoxCity->addItem("Бурштын");
    ui->comboBoxCity->addItem("Галич");
    ui->comboBoxCity->addItem("Городенка");
    ui->comboBoxCity->addItem("Делятин");
    ui->comboBoxCity->addItem("Долина");
    ui->comboBoxCity->addItem("Ивано-Франковск");
    ui->comboBoxCity->addItem("Калуш");
    ui->comboBoxCity->addItem("Коломыя");
    ui->comboBoxCity->addItem("Косов");
    ui->comboBoxCity->addItem("Ланчин");
    ui->comboBoxCity->addItem("Надворная");
    ui->comboBoxCity->addItem("Перегинское");
    ui->comboBoxCity->addItem("Рогатин");
    ui->comboBoxCity->addItem("Снятын");
    ui->comboBoxCity->addItem("Тлумач");
    ui->comboBoxCity->addItem("Тысменица");
    ui->comboBoxCity->addItem("Яремче");
}
void MainWindow::fill_cmb_ko()
{
    ui->comboBoxCity->addItem("Барышевка");
    ui->comboBoxCity->addItem("Белая Церковь");
    ui->comboBoxCity->addItem("Березань");
    ui->comboBoxCity->addItem("Богуслав");
    ui->comboBoxCity->addItem("Борисполь");
    ui->comboBoxCity->addItem("Бородянка");
    ui->comboBoxCity->addItem("Боярка");
    ui->comboBoxCity->addItem("Бровары");
    ui->comboBoxCity->addItem("Буча");
    ui->comboBoxCity->addItem("Васильков");
    ui->comboBoxCity->addItem("Вишневое");
    ui->comboBoxCity->addItem("Володарка");
    ui->comboBoxCity->addItem("Вышгород");
    ui->comboBoxCity->addItem("Глеваха");
    ui->comboBoxCity->addItem("Гостомель");
    ui->comboBoxCity->addItem("Иванков");
    ui->comboBoxCity->addItem("Ирпень");
    ui->comboBoxCity->addItem("Кагарлык");
    ui->comboBoxCity->addItem("Киев");
    ui->comboBoxCity->addItem("Коцюбинское");
    ui->comboBoxCity->addItem("Макаров");
    ui->comboBoxCity->addItem("Мироновка");
    ui->comboBoxCity->addItem("Обухов");
    ui->comboBoxCity->addItem("Переяслав-Хмельницкий");
    ui->comboBoxCity->addItem("Припять");
    ui->comboBoxCity->addItem("Ржищев");
    ui->comboBoxCity->addItem("Рокитное");
    ui->comboBoxCity->addItem("Сквира");
    ui->comboBoxCity->addItem("Славутич");
    ui->comboBoxCity->addItem("Тараща");
    ui->comboBoxCity->addItem("Тетиев");
    ui->comboBoxCity->addItem("Узин");
    ui->comboBoxCity->addItem("Украинка");
    ui->comboBoxCity->addItem("Фастов");
    ui->comboBoxCity->addItem("Чернобыль");
    ui->comboBoxCity->addItem("Яготин");
}
void MainWindow::fill_cmb_kir()
{
    ui->comboBoxCity->addItem("Александрия");
    ui->comboBoxCity->addItem("Бобринец");
    ui->comboBoxCity->addItem("Власовка");
    ui->comboBoxCity->addItem("Гайворон");
    ui->comboBoxCity->addItem("Долинская");
    ui->comboBoxCity->addItem("Знаменка");
    ui->comboBoxCity->addItem("Кропивницкий");
    ui->comboBoxCity->addItem("Малая Виска");
    ui->comboBoxCity->addItem("Новая Прага");
    ui->comboBoxCity->addItem("Новоархангельск");
    ui->comboBoxCity->addItem("Новое");
    ui->comboBoxCity->addItem("Новомиргород");
    ui->comboBoxCity->addItem("Новоукраинка");
    ui->comboBoxCity->addItem("Первомайск");
    ui->comboBoxCity->addItem("Петрово");
    ui->comboBoxCity->addItem("Помошная");
    ui->comboBoxCity->addItem("Светловодск");
    ui->comboBoxCity->addItem("Смолино");
}
void MainWindow::fill_cmb_cri()
{
    ui->comboBoxCity->addItem("Алупка");
    ui->comboBoxCity->addItem("Алушта");
    ui->comboBoxCity->addItem("Армянск");
    ui->comboBoxCity->addItem("Бахчисарай");
    ui->comboBoxCity->addItem("Белогорск");
    ui->comboBoxCity->addItem("Береговое");
    ui->comboBoxCity->addItem("Джанкой");
    ui->comboBoxCity->addItem("Евпатория");
    ui->comboBoxCity->addItem("Знаменка");
    ui->comboBoxCity->addItem("Инкерман");
    ui->comboBoxCity->addItem("Керчь");
    ui->comboBoxCity->addItem("Красногвардейское");
    ui->comboBoxCity->addItem("Красноперекопск");
    ui->comboBoxCity->addItem("Раздольное");
    ui->comboBoxCity->addItem("Саки");
    ui->comboBoxCity->addItem("Севастополь");
    ui->comboBoxCity->addItem("Симферополь");
    ui->comboBoxCity->addItem("Старый Крым");
    ui->comboBoxCity->addItem("Судак");
    ui->comboBoxCity->addItem("Феодосия");
    ui->comboBoxCity->addItem("Черноморское");
    ui->comboBoxCity->addItem("Щёлкино");
    ui->comboBoxCity->addItem("Ялта");
}
void MainWindow::fill_cmb_lug()
{
    ui->comboBoxCity->addItem("Александровск");
    ui->comboBoxCity->addItem("Алмазная");
    ui->comboBoxCity->addItem("Алчевск");
    ui->comboBoxCity->addItem("Антрацит");
    ui->comboBoxCity->addItem("Артемовск");
    ui->comboBoxCity->addItem("Брянка");
    ui->comboBoxCity->addItem("Вахрушево");
    ui->comboBoxCity->addItem("Горное");
    ui->comboBoxCity->addItem("Горское");
    ui->comboBoxCity->addItem("Зимогорье");
    ui->comboBoxCity->addItem("Золотое");
    ui->comboBoxCity->addItem("Зоринск");
    ui->comboBoxCity->addItem("Ирмино");
    ui->comboBoxCity->addItem("Кировск");
    ui->comboBoxCity->addItem("Краснодон");
    ui->comboBoxCity->addItem("Краснопартизанск");
    ui->comboBoxCity->addItem("Красный Луч");
    ui->comboBoxCity->addItem("Кременная");
    ui->comboBoxCity->addItem("Лисичанск");
    ui->comboBoxCity->addItem("Луганск");
    ui->comboBoxCity->addItem("Лутугино");
    ui->comboBoxCity->addItem("Миусинск");
    ui->comboBoxCity->addItem("Молодогвардейск");
    ui->comboBoxCity->addItem("Новодружеск");
    ui->comboBoxCity->addItem("Новопсков");
    ui->comboBoxCity->addItem("Первомайск");
    ui->comboBoxCity->addItem("Перевальск");
    ui->comboBoxCity->addItem("Петровское");
    ui->comboBoxCity->addItem("Попасная");
    ui->comboBoxCity->addItem("Приволье");
    ui->comboBoxCity->addItem("Ровеньки");
    ui->comboBoxCity->addItem("Рубежное");
    ui->comboBoxCity->addItem("Сватово");
    ui->comboBoxCity->addItem("Свердловск");
    ui->comboBoxCity->addItem("Северодонецк");
    ui->comboBoxCity->addItem("Станица Луганская");
    ui->comboBoxCity->addItem("Старобельск");
    ui->comboBoxCity->addItem("Стаханов");
    ui->comboBoxCity->addItem("Суходольск");
    ui->comboBoxCity->addItem("Счастье");
    ui->comboBoxCity->addItem("Червонопартизанск");
}
void MainWindow::fill_cmb_lv()
{
    ui->comboBoxCity->addItem("Белз");
    ui->comboBoxCity->addItem("Бобрка");
    ui->comboBoxCity->addItem("Борислав");
    ui->comboBoxCity->addItem("Броды");
    ui->comboBoxCity->addItem("Буск");
    ui->comboBoxCity->addItem("Великие Мосты");
    ui->comboBoxCity->addItem("Винники");
    ui->comboBoxCity->addItem("Винники");
    ui->comboBoxCity->addItem("Глиняны");
    ui->comboBoxCity->addItem("Городок");
    ui->comboBoxCity->addItem("Добромиль");
    ui->comboBoxCity->addItem("Дрогобыч");
    ui->comboBoxCity->addItem("Дубляны");
    ui->comboBoxCity->addItem("Жидачев");
    ui->comboBoxCity->addItem("Жолква");
    ui->comboBoxCity->addItem("Золочев");
    ui->comboBoxCity->addItem("Каменка-Бугская");
    ui->comboBoxCity->addItem("Львов");
    ui->comboBoxCity->addItem("Мостиска");
    ui->comboBoxCity->addItem("Николаев");
    ui->comboBoxCity->addItem("Новояворовск");
    ui->comboBoxCity->addItem("Новый Роздол");
    ui->comboBoxCity->addItem("Перемышляны");
    ui->comboBoxCity->addItem("Пустомыты");
    ui->comboBoxCity->addItem("Рава-Русская");
    ui->comboBoxCity->addItem("Радехов");
    ui->comboBoxCity->addItem("Рудки");
    ui->comboBoxCity->addItem("Самбор");
    ui->comboBoxCity->addItem("Сколе");
    ui->comboBoxCity->addItem("Сокаль");
    ui->comboBoxCity->addItem("Сосновка");
    ui->comboBoxCity->addItem("Старый Самбор");
    ui->comboBoxCity->addItem("Стебник");
    ui->comboBoxCity->addItem("Стрый");
    ui->comboBoxCity->addItem("Трускавец");
    ui->comboBoxCity->addItem("Угнев");
    ui->comboBoxCity->addItem("Хыров");
    ui->comboBoxCity->addItem("Червоноград");
    ui->comboBoxCity->addItem("Яворов");
}
void MainWindow::fill_cmb_nik()
{
    ui->comboBoxCity->addItem("Александровка");
    ui->comboBoxCity->addItem("Арбузинка");
    ui->comboBoxCity->addItem("Баштанка");
    ui->comboBoxCity->addItem("Березнеговатое");
    ui->comboBoxCity->addItem("Братское");
    ui->comboBoxCity->addItem("Веселиново");
    ui->comboBoxCity->addItem("Вознесенск");
    ui->comboBoxCity->addItem("Врадиевка");
    ui->comboBoxCity->addItem("Доманевка");
    ui->comboBoxCity->addItem("Еланец");
    ui->comboBoxCity->addItem("Казанка");
    ui->comboBoxCity->addItem("Кривое Озеро");
    ui->comboBoxCity->addItem("Николаев");
    ui->comboBoxCity->addItem("Новая Одесса");
    ui->comboBoxCity->addItem("Новый Буг");
    ui->comboBoxCity->addItem("Очаков");
    ui->comboBoxCity->addItem("Первомайск");
    ui->comboBoxCity->addItem("Снигиревка");
    ui->comboBoxCity->addItem("Южноукраинск");
}
void MainWindow::fill_cmb_od()
{
    ui->comboBoxCity->addItem("Ананьев");
    ui->comboBoxCity->addItem("Арциз");
    ui->comboBoxCity->addItem("Балта");
    ui->comboBoxCity->addItem("Белгород-Днестровский");
    ui->comboBoxCity->addItem("Беляевка");
    ui->comboBoxCity->addItem("Березовка");
    ui->comboBoxCity->addItem("Болград");
    ui->comboBoxCity->addItem("Великодолинское");
    ui->comboBoxCity->addItem("Измаил");
    ui->comboBoxCity->addItem("Ильичевск");
    ui->comboBoxCity->addItem("Килия");
    ui->comboBoxCity->addItem("Кодыма");
    ui->comboBoxCity->addItem("Котовск");
    ui->comboBoxCity->addItem("Любашевка");
    ui->comboBoxCity->addItem("Овидиополь");
    ui->comboBoxCity->addItem("Одесса");
    ui->comboBoxCity->addItem("Раздельная");
    ui->comboBoxCity->addItem("Рени");
    ui->comboBoxCity->addItem("Татарбунары");
    ui->comboBoxCity->addItem("Теплодар");
    ui->comboBoxCity->addItem("Ширяево");
    ui->comboBoxCity->addItem("Южное");
}
void MainWindow::fill_cmb_pol()
{
    ui->comboBoxCity->addItem("Гадяч");
    ui->comboBoxCity->addItem("Глобино");
    ui->comboBoxCity->addItem("Горишные Плавни");
    ui->comboBoxCity->addItem("Градижск");
    ui->comboBoxCity->addItem("Гребенка");
    ui->comboBoxCity->addItem("Дергачи");
    ui->comboBoxCity->addItem("Диканька");
    ui->comboBoxCity->addItem("Зеньков");
    ui->comboBoxCity->addItem("Карловка");
    ui->comboBoxCity->addItem("Кобеляки");
    ui->comboBoxCity->addItem("Котельва");
    ui->comboBoxCity->addItem("Кременчуг");
    ui->comboBoxCity->addItem("Лохвица");
    ui->comboBoxCity->addItem("Лубны");
    ui->comboBoxCity->addItem("Миргород");
    ui->comboBoxCity->addItem("Новые Санжары");
    ui->comboBoxCity->addItem("Пирятин");
    ui->comboBoxCity->addItem("Полтава");
    ui->comboBoxCity->addItem("Решетиловка");
    ui->comboBoxCity->addItem("Хорол");
    ui->comboBoxCity->addItem("Червонозаводское");
    ui->comboBoxCity->addItem("Чутово");
}
void MainWindow::fill_cmb_rov()
{
    ui->comboBoxCity->addItem("Березне");
    ui->comboBoxCity->addItem("Вараш");
    ui->comboBoxCity->addItem("Владимирец");
    ui->comboBoxCity->addItem("Дубно");
    ui->comboBoxCity->addItem("Дубровица");
    ui->comboBoxCity->addItem("Заречное");
    ui->comboBoxCity->addItem("Здолбунов");
    ui->comboBoxCity->addItem("Квасилов");
    ui->comboBoxCity->addItem("Костополь");
    ui->comboBoxCity->addItem("Млинов");
    ui->comboBoxCity->addItem("Острог");
    ui->comboBoxCity->addItem("Радивилов");
    ui->comboBoxCity->addItem("Ровно");
    ui->comboBoxCity->addItem("Рокитное");
    ui->comboBoxCity->addItem("Сарны");
    ui->comboBoxCity->addItem("Корец");
}
void MainWindow::fill_cmb_sum()
{
    ui->comboBoxCity->addItem("Ахтырка");
    ui->comboBoxCity->addItem("Белополье");
    ui->comboBoxCity->addItem("Бурынь");
    ui->comboBoxCity->addItem("Ворожба");
    ui->comboBoxCity->addItem("Воронеж");
    ui->comboBoxCity->addItem("Глухов");
    ui->comboBoxCity->addItem("Дружба");
    ui->comboBoxCity->addItem("Конотоп");
    ui->comboBoxCity->addItem("Краснополье");
    ui->comboBoxCity->addItem("Кролевец");
    ui->comboBoxCity->addItem("Лебедин");
    ui->comboBoxCity->addItem("Путивль");
    ui->comboBoxCity->addItem("Ромны");
    ui->comboBoxCity->addItem("Свесса");
    ui->comboBoxCity->addItem("Середина-Буда");
    ui->comboBoxCity->addItem("Сумы");
    ui->comboBoxCity->addItem("Тростянец");
    ui->comboBoxCity->addItem("Шостка");
}
void MainWindow::fill_cmb_ter()
{
    ui->comboBoxCity->addItem("Бережаны");
    ui->comboBoxCity->addItem("Борщев");
    ui->comboBoxCity->addItem("Бучач");
    ui->comboBoxCity->addItem("Великая Березовица");
    ui->comboBoxCity->addItem("Гусятин");
    ui->comboBoxCity->addItem("Залещики");
    ui->comboBoxCity->addItem("Збараж");
    ui->comboBoxCity->addItem("Зборов");
    ui->comboBoxCity->addItem("Козова");
    ui->comboBoxCity->addItem("Копычинцы");
    ui->comboBoxCity->addItem("Кременец");
    ui->comboBoxCity->addItem("Лановцы");
    ui->comboBoxCity->addItem("Монастыриска");
    ui->comboBoxCity->addItem("Подволочиск");
    ui->comboBoxCity->addItem("Подгайцы");
    ui->comboBoxCity->addItem("Почаев");
    ui->comboBoxCity->addItem("Скалат");
    ui->comboBoxCity->addItem("Теребовля");
    ui->comboBoxCity->addItem("Тернополь");
    ui->comboBoxCity->addItem("Хоростков");
    ui->comboBoxCity->addItem("Чертков");
    ui->comboBoxCity->addItem("Шумск");
}
void MainWindow::fill_cmb_kha()
{
    ui->comboBoxCity->addItem("Балаклея");
    ui->comboBoxCity->addItem("Барвенково");
    ui->comboBoxCity->addItem("Богодухов");
    ui->comboBoxCity->addItem("Валки");
    ui->comboBoxCity->addItem("Великий Бурлук");
    ui->comboBoxCity->addItem("Волчанск");
    ui->comboBoxCity->addItem("Высокий");
    ui->comboBoxCity->addItem("Дергачи");
    ui->comboBoxCity->addItem("Змиев");
    ui->comboBoxCity->addItem("Изюм");
    ui->comboBoxCity->addItem("Комсомольское");
    ui->comboBoxCity->addItem("Красноград");
    ui->comboBoxCity->addItem("Купянск");
    ui->comboBoxCity->addItem("Лозовая");
    ui->comboBoxCity->addItem("Люботин");
    ui->comboBoxCity->addItem("Мерефа");
    ui->comboBoxCity->addItem("Новая Водолага");
    ui->comboBoxCity->addItem("Первомайский");
    ui->comboBoxCity->addItem("Солоницевка");
    ui->comboBoxCity->addItem("Харьков");
    ui->comboBoxCity->addItem("Чугуев");
}
void MainWindow::fill_cmb_khe()
{
    ui->comboBoxCity->addItem("Антоновка");
    ui->comboBoxCity->addItem("Белозерка");
    ui->comboBoxCity->addItem("Берислав");
    ui->comboBoxCity->addItem("Великая Александровка");
    ui->comboBoxCity->addItem("Великая Лепетиха");
    ui->comboBoxCity->addItem("Геническ");
    ui->comboBoxCity->addItem("Голая Пристань");
    ui->comboBoxCity->addItem("Каланчак");
    ui->comboBoxCity->addItem("Камышаны");
    ui->comboBoxCity->addItem("Каховка");
    ui->comboBoxCity->addItem("Новая Каховка");
    ui->comboBoxCity->addItem("Новая Маячка");
    ui->comboBoxCity->addItem("Новоалексеевка");
    ui->comboBoxCity->addItem("Новотроицкое");
    ui->comboBoxCity->addItem("Пойма");
    ui->comboBoxCity->addItem("Скадовск");
    ui->comboBoxCity->addItem("Таврийск");
    ui->comboBoxCity->addItem("Херсон");
}
void MainWindow::fill_cmb_khm()
{
    ui->comboBoxCity->addItem("Виньковцы");
    ui->comboBoxCity->addItem("Волочиск");
    ui->comboBoxCity->addItem("Городок");
    ui->comboBoxCity->addItem("Деражня");
    ui->comboBoxCity->addItem("Дунаевцы");
    ui->comboBoxCity->addItem("Изяслав");
    ui->comboBoxCity->addItem("Каменец-Подольский");
    ui->comboBoxCity->addItem("Красилов");
    ui->comboBoxCity->addItem("Летичев");
    ui->comboBoxCity->addItem("Нетешин");
    ui->comboBoxCity->addItem("Полонное");
    ui->comboBoxCity->addItem("Понинка");
    ui->comboBoxCity->addItem("Славута");
    ui->comboBoxCity->addItem("Староконстантинов");
    ui->comboBoxCity->addItem("Теофиполь");
    ui->comboBoxCity->addItem("Хмельницкий");
    ui->comboBoxCity->addItem("Шепетовка");
}
void MainWindow::fill_cmb_chk()
{
    ui->comboBoxCity->addItem("Ватутино");
    ui->comboBoxCity->addItem("Городище");
    ui->comboBoxCity->addItem("Драбов");
    ui->comboBoxCity->addItem("Жашков");
    ui->comboBoxCity->addItem("Звенигородка");
    ui->comboBoxCity->addItem("Золотоноша");
    ui->comboBoxCity->addItem("Каменка");
    ui->comboBoxCity->addItem("Канев");
    ui->comboBoxCity->addItem("Корсунь-Шевченковский");
    ui->comboBoxCity->addItem("Лысянка");
    ui->comboBoxCity->addItem("Маньковка");
    ui->comboBoxCity->addItem("Монастырище");
    ui->comboBoxCity->addItem("Смела");
    ui->comboBoxCity->addItem("Тальное");
    ui->comboBoxCity->addItem("Умань");
    ui->comboBoxCity->addItem("Христиновка");
    ui->comboBoxCity->addItem("Черкассы");
    ui->comboBoxCity->addItem("Чернобай");
    ui->comboBoxCity->addItem("Чигирин");
    ui->comboBoxCity->addItem("Шпола");
}
void MainWindow::fill_cmb_chn()
{
    ui->comboBoxCity->addItem("Бахмач");
    ui->comboBoxCity->addItem("Бобровица");
    ui->comboBoxCity->addItem("Борзна");
    ui->comboBoxCity->addItem("Городня");
    ui->comboBoxCity->addItem("Десна");
    ui->comboBoxCity->addItem("Ичня");
    ui->comboBoxCity->addItem("Козелец");
    ui->comboBoxCity->addItem("Корюковка");
    ui->comboBoxCity->addItem("Мена");
    ui->comboBoxCity->addItem("Нежин");
    ui->comboBoxCity->addItem("Новгород-Северский");
    ui->comboBoxCity->addItem("Носовка");
    ui->comboBoxCity->addItem("Прилуки");
    ui->comboBoxCity->addItem("Седнев");
    ui->comboBoxCity->addItem("Семеновка");
    ui->comboBoxCity->addItem("Чернигов");
    ui->comboBoxCity->addItem("Щорс");
}
void MainWindow::fill_cmb_chv()
{
    ui->comboBoxCity->addItem("Берегомет");
    ui->comboBoxCity->addItem("Вашковцы");
    ui->comboBoxCity->addItem("Вижница");
    ui->comboBoxCity->addItem("Герца");
    ui->comboBoxCity->addItem("Глыбокая");
    ui->comboBoxCity->addItem("Заставна");
    ui->comboBoxCity->addItem("Кельменцы");
    ui->comboBoxCity->addItem("Кицмань");
    ui->comboBoxCity->addItem("Красноильск");
    ui->comboBoxCity->addItem("Новоднестровск");
    ui->comboBoxCity->addItem("Новоселица");
    ui->comboBoxCity->addItem("Путила");
    ui->comboBoxCity->addItem("Сокиряны");
    ui->comboBoxCity->addItem("Сторожинец");
    ui->comboBoxCity->addItem("Хотин");
    ui->comboBoxCity->addItem("Черновцы");
}
//ui->comboBoxCity->addItem();


void MainWindow::fraud_url()
{
    if(m_sCurrentURL.indexOf("?") == -1)
    {
        m_sCurrentURL += "?page=" + QString::number(m_nCurrentPage);
        return;
    }
    m_sCurrentURL += "&page=" + QString::number(m_nCurrentPage);
}

void MainWindow::on_pushButton_2_clicked()
{

    if(m_nCurrentPage == 1)
        return;

    --m_nCurrentPage;
    QString tmp = m_sCurrentURL;
    if(tmp.indexOf("?") == -1)
    {
        tmp += "?page=" + QString::number(m_nCurrentPage);
        load_home(tmp);
        return;
    }
    tmp += "&page=" + QString::number(m_nCurrentPage);
    load_home(tmp);
}

void MainWindow::on_pushButton_3_clicked()
{


    ++m_nCurrentPage;
    QString tmp = m_sCurrentURL;
    if(tmp.indexOf("?") == -1)
    {
        tmp += "?page=" + QString::number(m_nCurrentPage);
        load_home(tmp);
        return;
    }
    tmp += "&page=" + QString::number(m_nCurrentPage);
    load_home(tmp);
}

void MainWindow::on_pushButton_4_clicked()
{

}

void MainWindow::on_radioButton_5_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->setViewMode    (QListWidget::ListMode);
    ui->listWidget->setDragEnabled(false);
    load_home(m_sCurrentURL);
}

void MainWindow::on_radioButton_6_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->setViewMode    (QListWidget::IconMode  );
    ui->listWidget->setDragEnabled(false);
    load_home(m_sCurrentURL);
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString title = item->data(Qt::UserRole).toList().at(3).toString();
    QString url = item->data(Qt::UserRole).toList().at(0).toString();
    QString url_img = item->data(Qt::UserRole).toList().at(2).toString();
    QString gpos = item->data(Qt::UserRole).toList().at(1).toString();
    CHistoryAd ad(title,url,url_img,gpos);
    m_listHAd->push_back(ad);

    ItemSelected *w = new ItemSelected(nullptr,(item->data(Qt::UserRole).toList()));
    w->show();


}

void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

}

void MainWindow::add_to_favorite()
{
    for (int i = 0; i < ui->listWidget->selectedItems().size(); ++i) {
            // Get curent item on selected row
            QListWidgetItem *item = ui->listWidget->item(ui->listWidget->currentRow());
            if(!CFavoriteAd::is_exist(m_listAds,item->data(Qt::UserRole).toList().at(3).toString()))
            {
                QString title = item->data(Qt::UserRole).toList().at(3).toString();
                QString url = item->data(Qt::UserRole).toList().at(0).toString();
                QString url_img = item->data(Qt::UserRole).toList().at(2).toString();
                QString gpos = item->data(Qt::UserRole).toList().at(1).toString();
                CFavoriteAd ad(title,url,url_img,gpos);//4,1,3
                m_listAds->push_back(ad);
            }


    }
//    debug off
//    QMessageBox msgBox;
//    msgBox.setText(QString::number(m_listAds->size()));
//    msgBox.exec();
}

void MainWindow::open_big_ad()
{
    for (int i = 0; i < ui->listWidget->selectedItems().size(); ++i) {
            // Get curent item on selected row
            QListWidgetItem *item = ui->listWidget->item(ui->listWidget->currentRow());

            QString title = item->data(Qt::UserRole).toList().at(3).toString();
            QString url = item->data(Qt::UserRole).toList().at(0).toString();
            QString url_img = item->data(Qt::UserRole).toList().at(2).toString();
            QString gpos = item->data(Qt::UserRole).toList().at(1).toString();
            CHistoryAd ad(title,url,url_img,gpos);
            m_listHAd->push_back(ad);

            ItemSelected *w = new ItemSelected(nullptr,(item->data(Qt::UserRole).toList()));

            w->show();

    }
}

void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{

    QPoint globalPos = ui->listWidget->mapToGlobal(pos);

       // Create menu and insert some actions
       QMenu myMenu;
       myMenu.addAction("В избранное", this, SLOT(add_to_favorite()));
       myMenu.addAction("Открыть",  this, SLOT(open_big_ad()));
       // Show context menu at handling position
       myMenu.exec(globalPos);
}

void MainWindow::on_action_triggered()
{
    Favorites * widget = new Favorites(nullptr,m_listAds);

    widget->show();
}

void MainWindow::on_action_2_triggered()
{
    CHistory *dialog = new CHistory(nullptr,m_listHAd,m_listUrls,&m_sCurrentURL,m_vecHomeAds,ui->listWidget,&m_nCurrentPage,ui->lineEdit_3);

    dialog->show();
}
void MainWindow::fill_cmb_vinnitsa()
{
    ui->comboBoxCityRegion->addItem("Замостянский");
    ui->comboBoxCityRegion->addItem("Ленинский");
    ui->comboBoxCityRegion->addItem("Старогородской");
}
void MainWindow::fill_cmb_dnepr()
{
    ui->comboBoxCityRegion->addItem("Амур-Нижнеднепровский");
    ui->comboBoxCityRegion->addItem("Бабушкинский");
    ui->comboBoxCityRegion->addItem("Жовтневый");
    ui->comboBoxCityRegion->addItem("Индустриальный");
    ui->comboBoxCityRegion->addItem("Кировский");
    ui->comboBoxCityRegion->addItem("Красногвардейский");
    ui->comboBoxCityRegion->addItem("Ленинский");
    ui->comboBoxCityRegion->addItem("Самарский");
}
void MainWindow::fill_cmb_donetsk()
{
    ui->comboBoxCityRegion->addItem("Будённовский");
    ui->comboBoxCityRegion->addItem("Ворошиловский");
    ui->comboBoxCityRegion->addItem("Калининский");
    ui->comboBoxCityRegion->addItem("Киевский");
    ui->comboBoxCityRegion->addItem("Кировский");
    ui->comboBoxCityRegion->addItem("Куйбышевский");
    ui->comboBoxCityRegion->addItem("Ленинский");
    ui->comboBoxCityRegion->addItem("Петровский");
    ui->comboBoxCityRegion->addItem("Пролетарский");
}
void MainWindow::fill_cmb_zhitomir()
{
    ui->comboBoxCityRegion->addItem("Аэропорт");
    ui->comboBoxCityRegion->addItem("Богуния");
    ui->comboBoxCityRegion->addItem("Бумажная фабрика");
    ui->comboBoxCityRegion->addItem("Вокзал");
    ui->comboBoxCityRegion->addItem("Гормолзавод");
    ui->comboBoxCityRegion->addItem("Житний рынок");
    ui->comboBoxCityRegion->addItem("Корбутовка");
    ui->comboBoxCityRegion->addItem("Крошня");
    ui->comboBoxCityRegion->addItem("Максютова");
    ui->comboBoxCityRegion->addItem("Малеванка");
    ui->comboBoxCityRegion->addItem("Маликова");
    ui->comboBoxCityRegion->addItem("Марьяновка");
    ui->comboBoxCityRegion->addItem("Музыкальная фабрика");
    ui->comboBoxCityRegion->addItem("Подол");
    ui->comboBoxCityRegion->addItem("Полевая");
    ui->comboBoxCityRegion->addItem("Промавтоматика");
    ui->comboBoxCityRegion->addItem("Путятинка");
    ui->comboBoxCityRegion->addItem("Сенный рынок");
    ui->comboBoxCityRegion->addItem("Смаковка");
    ui->comboBoxCityRegion->addItem("Смолянка");
    ui->comboBoxCityRegion->addItem("Химволокно");
    ui->comboBoxCityRegion->addItem("Центр");
    ui->comboBoxCityRegion->addItem("Чудновский");
    ui->comboBoxCityRegion->addItem("Чулочная фабрика");
}
void MainWindow::fill_cmb_zaporozhe()
{
    ui->comboBoxCityRegion->addItem("Александровский");
    ui->comboBoxCityRegion->addItem("Вознесеновский");
    ui->comboBoxCityRegion->addItem("Днепровский");
    ui->comboBoxCityRegion->addItem("Заводский");
    ui->comboBoxCityRegion->addItem("Коммунарский");
    ui->comboBoxCityRegion->addItem("Хортицкий");
    ui->comboBoxCityRegion->addItem("Шевченковский");
}
void MainWindow::fill_cmb_kiev()
{
    ui->comboBoxCityRegion->addItem("Голосеевский");
    ui->comboBoxCityRegion->addItem("Дарницкий");
    ui->comboBoxCityRegion->addItem("Деснянский");
    ui->comboBoxCityRegion->addItem("Днепровский");
    ui->comboBoxCityRegion->addItem("Оболонский");
    ui->comboBoxCityRegion->addItem("Печерский");
    ui->comboBoxCityRegion->addItem("Подольский");
    ui->comboBoxCityRegion->addItem("Святошинский");
    ui->comboBoxCityRegion->addItem("Соломенский");
    ui->comboBoxCityRegion->addItem("Шевченковский");
}
void MainWindow::fill_cmb_kropivnitskiy()
{
    ui->comboBoxCityRegion->addItem("Кировский район");
    ui->comboBoxCityRegion->addItem("Ленинский район");
    ui->comboBoxCityRegion->addItem("Ярмолинецкий");
}
void MainWindow::fill_cmb_lugansk()
{
    ui->comboBoxCityRegion->addItem("Артёмовский");
    ui->comboBoxCityRegion->addItem("Жовтневый");
    ui->comboBoxCityRegion->addItem("Каменнобродский");
    ui->comboBoxCityRegion->addItem("Ленинский");
}
void MainWindow::fill_cmb_lvov()
{
    ui->comboBoxCityRegion->addItem("Галицкий");
    ui->comboBoxCityRegion->addItem("Железнодорожный");
    ui->comboBoxCityRegion->addItem("Лычаковский");
    ui->comboBoxCityRegion->addItem("Сиховский");
    ui->comboBoxCityRegion->addItem("Франковский");
    ui->comboBoxCityRegion->addItem("Шевченковский");
}
void MainWindow::fill_cmb_nikolaev_106()
{
    ui->comboBoxCityRegion->addItem("Заводский");
    ui->comboBoxCityRegion->addItem("Ингульский");
    ui->comboBoxCityRegion->addItem("Корабельный");
    ui->comboBoxCityRegion->addItem("Центральный");
}
void MainWindow::fill_cmb_odessa()
{
    ui->comboBoxCityRegion->addItem("Киевский");
    ui->comboBoxCityRegion->addItem("Коминтерновский");
    ui->comboBoxCityRegion->addItem("Малиновский");
    ui->comboBoxCityRegion->addItem("Приморский");
    ui->comboBoxCityRegion->addItem("Суворовский");
}
void MainWindow::fill_cmb_kharkov()
{
    ui->comboBoxCityRegion->addItem("Индустриальный");
    ui->comboBoxCityRegion->addItem("Киевский");
    ui->comboBoxCityRegion->addItem("Коминтерновский");
    ui->comboBoxCityRegion->addItem("Московский");
    ui->comboBoxCityRegion->addItem("Октябрьский");
    ui->comboBoxCityRegion->addItem("Фрунзенский");
    ui->comboBoxCityRegion->addItem("Холодногорский");
    ui->comboBoxCityRegion->addItem("Червонозаводской");
    ui->comboBoxCityRegion->addItem("Шевченковский");
}
void MainWindow::on_comboBoxCityRegion_currentTextChanged(const QString &arg1)
{

}

void MainWindow::on_comboBoxCity_currentIndexChanged(const QString &arg1)
{
    ui->comboBoxCityRegion->clear();
    ui->comboBoxCityRegion->addItem("");
    bool is_show = false;
    if(arg1 == "Винница")
    {
        is_show = true;
        fill_cmb_vinnitsa();
    }
    if(arg1 == "Днепр")
    {
        is_show = true;
        fill_cmb_dnepr();
    }

    if(arg1 == "Донецк")
    {
        is_show = true;
         fill_cmb_donetsk();
    }
    if(arg1 == "Житомир")
    {
        is_show = true;
        fill_cmb_zhitomir();
    }

    if(arg1 == "Запорожье")
    {
        is_show = true;
        fill_cmb_zaporozhe();
    }
    if(arg1 == "Киев")
    {
        is_show = true;
        fill_cmb_kiev();
    }
    if(arg1 == "Кропивницкий")
    {
        is_show = true;
        fill_cmb_kropivnitskiy();
    }

    if(arg1 == "Луганск")
    {
        is_show = true;
        fill_cmb_lugansk();
    }
    if(arg1 == "Львов")
    {
       is_show = true;
       fill_cmb_lvov();
    }
    if(arg1 == "Николаев")
    {
        is_show = true;
        fill_cmb_nikolaev_106();
    }
    if(arg1 == "Одесса")
    {
        is_show = true;
        fill_cmb_odessa();
    }
    if(arg1 == "Харьков")
    {
        is_show = true;
        fill_cmb_kharkov();
    }
    if(is_show)
        ui->comboBoxCityRegion->show();
    else
        ui->comboBoxCityRegion->hide();


}
