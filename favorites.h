#ifndef FAVORITES_H
#define FAVORITES_H

#include <QWidget>
#include "cfavoritead.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include "itemselected.h"
#include "mylistwidget.h"
namespace Ui {
class Favorites;
}

class Favorites : public QWidget
{
    Q_OBJECT

public:
    explicit Favorites(QWidget *parent = nullptr);
    explicit Favorites(QWidget *parent = nullptr , QList<CFavoriteAd> *list = nullptr);

    ~Favorites();

private slots:
    void delete_ad();
    void open_big_ad();









    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:

    Ui::Favorites *ui;
    QList<CFavoriteAd> *m_listAds;
};

#endif // FAVORITES_H
