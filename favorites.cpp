#include "favorites.h"
#include "ui_favorites.h"

Favorites::Favorites(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Favorites)
{
    ui->setupUi(this);
    ui->listWidget1->setResizeMode(QListWidget::Adjust);
    ui->listWidget1->setIconSize(QSize(170,132));
    ui->listWidget1->setAcceptDrops(true);
    ui->listWidget1->setDragEnabled(false);


}
Favorites::Favorites(QWidget *parent,QList<CFavoriteAd>*list) :
    QWidget(parent),
    ui(new Ui::Favorites)
{
    ui->setupUi(this);
    ui->listWidget1->setResizeMode(QListWidget::Adjust);
    ui->listWidget1->setIconSize(QSize(170,132));
    ui->listWidget1->setAcceptDrops(true);
    ui->listWidget1->setDragEnabled(false);
    m_listAds = list;
    QNetworkAccessManager manager;
    for(CFavoriteAd ad :*m_listAds)
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

        ui->listWidget1->addItem(item);


    }
}

Favorites::~Favorites()
{
    delete ui;
}

void Favorites::open_big_ad()
{
    for (int i = 0; i < ui->listWidget1->selectedItems().size(); ++i) {
            // Get curent item on selected row
            QListWidgetItem *item = ui->listWidget1->item(ui->listWidget1->currentRow());

            ItemSelected *w = new ItemSelected(nullptr,(item->data(Qt::UserRole).toList()));

            w->show();

    }
}

void Favorites::delete_ad()
{
    for (int i = 0; i < ui->listWidget1->selectedItems().size(); ++i) {
            // Get curent item on selected row
            QListWidgetItem *item = ui->listWidget1->takeItem(ui->listWidget1->currentRow());
            QString text = item->text();
            int count = 0;
            for ( auto it = m_listAds->begin()  , end = m_listAds->end() ; it!= end ; ++it , ++count )
            {
                if(it->get_title() == text)
                    m_listAds->removeAt(count);
            }


    }
}


//void Favorites::showContextMenu(const QPoint &pos)
//{
//    QPoint globalPos = ui->listWidget1->mapToGlobal(pos);
//    qDebug()<<"s";
//    // Create menu and insert some actions
//    QMenu *myMenu = new QMenu;
//    myMenu->addAction("Удалить", this, SLOT(delete_ad()));
//    myMenu->addAction("Открыть",  this, SLOT(open_big_ad()));
//    // Show context menu at handling position
//    myMenu->exec(globalPos);
//}

void Favorites::on_pushButton_2_clicked()
{
    emit open_big_ad();
}

void Favorites::on_pushButton_clicked()
{
    emit delete_ad();
}
