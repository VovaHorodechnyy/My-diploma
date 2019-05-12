#include "chistory.h"
#include "ui_chistory.h"

CHistory::CHistory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CHistory)
{
    ui->setupUi(this);
}

CHistory::CHistory(QWidget *parent , QList<CHistoryAd>* alistAds , QList<URLParametres>* alistUrls ,
                   QString* aCurrPage,QVector<CAdHome>* avecHomeAds , QListWidget* listWdgt ,
                   int* anCurrPage , QLineEdit* lineEdt) :
    QDialog(parent),
    ui(new Ui::CHistory)
{
    ui->setupUi(this);

    ui->adsListWidget->setResizeMode(QListWidget::Adjust);
    ui->adsListWidget->setIconSize(QSize(170,132));
    ui->adsListWidget->setAcceptDrops(true);
    ui->adsListWidget->setDragEnabled(false);

    ui->urlsListWidget->setResizeMode(QListWidget::Adjust);
    ui->urlsListWidget->setIconSize(QSize(170,132));
    ui->urlsListWidget->setAcceptDrops(true);
    ui->urlsListWidget->setDragEnabled(false);
    m_sCurrentURL = aCurrPage;
    m_listAd = alistAds;
    m_listUrl = alistUrls;
    m_vecHomeAds = avecHomeAds;
    listWidget = listWdgt;
    m_nCurrentPage = anCurrPage;
    lineEdit = lineEdt;
    QNetworkAccessManager manager;
    for(CHistoryAd ad :*m_listAd)
    {
        QListWidgetItem *item = new QListWidgetItem;
        QNetworkReply *response_img = manager.get(QNetworkRequest(QUrl(ad.get_url_img())));
        QEventLoop event_img;
        connect(response_img,SIGNAL(finished()),&event_img,SLOT(quit()));
        event_img.exec();
        QByteArray jpegData = response_img->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(jpegData);
        QIcon *icon = new QIcon(pixmap);
        item->setIcon(*icon);
        QList<QVariant> qlist;
        qlist.push_back(ad.get_url());
        qlist.push_back(ad.get_g_pos());
        item->setText(ad.get_title());
        QVariant fullFilePathData(qlist);
        item->setData(Qt::UserRole, fullFilePathData);

        ui->adsListWidget->addItem(item);


    }
    for(URLParametres url :*m_listUrl)
    {
        QString text = "";
        if(url.sCity != "")
            text += url.sCity;
        if(url.sRegion != "")
            text += "\n" + url.sRegion;
        if(url.sSearch != "")
            text += "\nПоиск: " + url.sSearch;
        if(url.sCurrency != "")
            text += "\nВалюта: " + url.sCurrency;
        if(url.fIsPhoto)
            text += "\nФото: +";
        if(url.fIsCheap)
            text += "\nСамые дешевые";
        if(url.fIsNew)
            text += "\nСамые новые";
        if(url.fIsExpensive)
            text += "\nСамые дорогые";
        if(url.fIsInTtlNDesc)
            text += "\nИскать в заголовке и описании: +";
        if(url.nPriceTo != -1)
            text += "\nЦена до: " + QString::number(url.nPriceTo);
        if(url.nPriceFrom != -1)
            text += "\nЦена от: " + QString::number(url.nPriceFrom);
        CUrlBuilder builder;
        QString url_s = builder.get_url_f_pararam(url);
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(text);
        QVariant var(url_s);
        item->setData(Qt::UserRole, var);

        ui->urlsListWidget->addItem(item);
    }
}

CHistory::~CHistory()
{
    delete ui;
}

void CHistory::on_pushButton_clicked()
{
    for (int i = 0; i < ui->urlsListWidget->selectedItems().size(); ++i) {
            // Get curent item on selected row
            QListWidgetItem *item = ui->urlsListWidget->item(ui->urlsListWidget->currentRow());
            load_home(item->data(Qt::UserRole).toString());
    }
}

void CHistory::fill_vector(QStringList& aList)
{
    const std::size_t size = aList.size();
    CParser parser;
    for(std::size_t ix = 1; ix < size ; ++ix)
    {

        m_vecHomeAds->push_back(parser.parse(aList.at(ix)));
    }

}

void CHistory::load_home(const QString& aUrl )
{
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(aUrl)));
    QEventLoop event;
    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    QString html = response->readAll();
    QString end_s = "</table>";
    *m_sCurrentURL = aUrl;
    size_t pos_id = html.indexOf("id=\"offers_table\"");
    size_t pos_table = html.indexOf("<table ",pos_id - 150);
    size_t bedfore_end = html.indexOf("adcontainer-tr",pos_id);
    size_t pos_end = html.indexOf(end_s,bedfore_end);
    m_vecHomeAds->clear();
    QString html_table = html.mid( pos_table , pos_end - pos_table + end_s.length()  );
    QStringList array = html_table.split("<tr class=\"wrap\"\n    rel=\"\" >");
    fill_vector(array);
    const std::size_t size = m_vecHomeAds -> size();
    listWidget->clear();
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
        if(listWidget->viewMode() == QListWidget::IconMode)
        {
            item->setTextAlignment(Qt::AlignLeft|Qt::AlignBottom);
            item->setSizeHint(QSize(200, 220));
            item->setText(tmp.getTitle());
        }
        else
        {
            item->setText(tmp.getTitle() + "\n" + tmp.getGeoPos() + "\n"+tmp.getSmalDescr() + "\n" + tmp.getPublicated() +"\n" + tmp.getPrice());
        }
        listWidget->addItem(item);
        //ui->listWidget->addItem(array.at(ix));
    }

    lineEdit->setText(QString::number(*m_nCurrentPage));
}

void CHistory::on_pushButton_2_clicked()
{
    for (int i = 0; i < ui->urlsListWidget->selectedItems().size(); ++i) {
            // Get curent item on selected row
            QListWidgetItem *item = ui->urlsListWidget->item(ui->urlsListWidget->currentRow());

            ItemSelected *w = new ItemSelected(nullptr,(item->data(Qt::UserRole).toList()));

            w->show();
    }
}
