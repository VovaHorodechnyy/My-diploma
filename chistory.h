#ifndef CHISTORY_H
#define CHISTORY_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QListWidget>
#include <QLineEdit>
#include <QString>
#include "curlbuilder.h"
#include "itemselected.h"
namespace Ui {
class CHistory;
}
class CHistoryAd;
class CHistoryUrl;
class CHistory : public QDialog
{
    Q_OBJECT

public:
    explicit CHistory(QWidget *parent = nullptr);
    CHistory(QWidget *parent = nullptr, QList<CHistoryAd>* alistAds = nullptr, QList<URLParametres>* alistUrls = nullptr,
             QString* aCurrPage = nullptr,QVector<CAdHome>* avecHomeAds = nullptr, QListWidget* listWdgt = nullptr,
             int* anCurrPage = nullptr, QLineEdit* lineEdt = nullptr);
    ~CHistory();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void fill_vector(QStringList& aList);
    void load_home(const QString& aUrl );
    int * m_nCurrentPage;
    QString* m_sCurrentURL;
    QVector<CAdHome>* m_vecHomeAds;
    QList<CHistoryAd>* m_listAd;
    QList<URLParametres>* m_listUrl;
    QListWidget* listWidget;
    QLineEdit* lineEdit;
    Ui::CHistory *ui;
};

class CHistoryAd
{
    public:
        CHistoryAd(const QString& aTitle , const QString& aUrl , const QString& aUrl_img , const QString& aGPos)
        {
         m_sTitle = aTitle;
         m_sUrl = aUrl;
         m_sUrlImg = aUrl_img;
         m_sGeoPos = aGPos;
        }
        CHistoryAd(){}
        QString& get_g_pos(){   return m_sGeoPos;    }
        QString& get_title(){   return m_sTitle;    }
        QString& get_url(){ return m_sUrl;  }
        QString& get_url_img(){ return m_sUrlImg;   }
        void set_title(const QString& aTitle)
        {
          m_sTitle = aTitle;;
        }
        void set_url(const QString& aUrl)
        {
          m_sUrl = aUrl;
        }
        void set_url_img(const QString& aUrl_img)
        {
          m_sUrlImg = aUrl_img;
        }
        void set_g_pos(const QString& aGPos)
        {
          m_sGeoPos = aGPos;
        }

    private:
        QString m_sTitle,m_sUrl,m_sUrlImg,m_sGeoPos;
};

class CHistoryUrl
{

};

#endif // CHISTORY_H
