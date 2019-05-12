#ifndef ITEMSELECTED_H
#define ITEMSELECTED_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QString>
#include <string>
#include "CParser.h"
#include <QDesktopServices>
#include "cloadingscreen.h"
#include <thread>
#include <chrono>
#include <QThread>
namespace Ui {
class ItemSelected;
}

class ItemSelected : public QWidget
{
    Q_OBJECT

public:
    explicit ItemSelected(QWidget *parent = nullptr);
    ItemSelected(QWidget* parent = nullptr,const QList<QVariant> &url = QList<QVariant>());
    ~ItemSelected();

private slots:
    void on_pushButton_clicked();
    void stop_act();

private:
    Ui::ItemSelected *ui;
    void set_pix_url(const QString &);
    void add_img_2_list(const QString&);
    void fill_table(CBigAd & ad);
    CLoadingScreen * screen;
    QTimer* ptimer;
    QString m_sUrl;

};

#endif // ITEMSELECTED_H
