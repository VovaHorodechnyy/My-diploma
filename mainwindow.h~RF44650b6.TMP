#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QMap>
#include <QStyleFactory>
#include "curlbuilder.h"
#include "itemselected.h"
#include "chistory.h"
#include "CParser.h"
#include "favorites.h"
#include <QFileInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void closeEvent (QCloseEvent *event);
    void on_pushButton_clicked();
    void replyFini(QNetworkReply* reply);
    void fill_vector(QStringList&);
    void switchcall(const QString&);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void open_big_ad();

    void add_to_favorite();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_comboBoxCityRegion_currentTextChanged(const QString &arg1);

    void on_comboBoxCity_currentIndexChanged(const QString &arg1);

private:
    bool fileExists(QString path);

    void fill_cmb_regions();
    void fill_cmb_vin();
    void fill_cmb_vol();
    void fill_cmb_dnp();
    void fill_cmb_don();
    void fill_cmb_zht();
    void fill_cmb_zak();
    void fill_cmb_zap();
    void fill_cmb_if();
    void fill_cmb_ko();
    void fill_cmb_kir();
    void fill_cmb_cri();
    void fill_cmb_lug();
    void fill_cmb_lv();
    void fill_cmb_nik();
    void fill_cmb_od();
    void fill_cmb_pol();
    void fill_cmb_rov();
    void fill_cmb_sum();
    void fill_cmb_ter();
    void fill_cmb_kha();
    void fill_cmb_khe();
    void fill_cmb_khm();
    void fill_cmb_chk();
    void fill_cmb_chn();
    void fill_cmb_chv();

    void fill_cmb_vinnitsa();
    void fill_cmb_dnepr();
    void fill_cmb_donetsk();
    void fill_cmb_zhitomir();
    void fill_cmb_zaporozhe();
    void fill_cmb_kiev();
    void fill_cmb_kropivnitskiy();
    void fill_cmb_lugansk();
    void fill_cmb_lvov();
    void fill_cmb_nikolaev_106();
    void fill_cmb_odessa();
    void fill_cmb_kharkov();



    void fraud_url();
    void load_home(const QString & url = "https://www.olx.ua/nedvizhimost/");
    QVector<CAdHome> *m_vecHomeAds;
    CUrlBuilder m_objUrlBuilder;
    QString m_sCurrentURL = "https://www.olx.ua/nedvizhimost/";
    int m_nCurrentPage;
    Ui::MainWindow *ui;
    QList<CFavoriteAd> *m_listAds;
    QList<CHistoryAd>* m_listHAd;
    QList<URLParametres>*m_listUrls;

};

#endif // MAINWINDOW_H
