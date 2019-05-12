#ifndef CURLBUILDER_H
#define CURLBUILDER_H
#include <QMap>
struct URLParametres
{
    QString sRegion = "";
    QString sCity = "";
    QString sCurrency = "";
    QString sSearch = "";
    QString sCityRegion = "";
    bool fIsInTtlNDesc = false;
    bool fIsPhoto = false;
    bool fIsCheap = false;
    bool fIsExpensive = false;
    bool fIsNew = false;
    int nKilometres = -1;
    int nPriceFrom = -1;
    int nPriceTo = -1;
};
class CUrlBuilder
{
    public:
        CUrlBuilder();
        const QString get_url_f_pararam(const URLParametres&);
    private:     
         void fill_map_regions();
         void fill_region_vin();
         void fill_region_vol();
         void fill_region_dnp();
         void fill_region_don();
         void fill_region_zht();
         void fill_region_zak();
         void fill_region_zap();
         void fill_region_if();
         void fill_region_ko();
         void fill_region_kir();
         void fill_region_cri();
         void fill_region_lug();
         void fill_region_lv();
         void fill_region_nik();
         void fill_region_od();
         void fill_region_pol();
         void fill_region_rov();
         void fill_region_sum();
         void fill_region_ter();
         void fill_region_kha();
         void fill_region_khe();
         void fill_region_khm();
         void fill_region_chk();
         void fill_region_chn();
         void fill_region_chv();
         void fill_city_regions();
         void fill_all_regs();
         void fill_all_this_shit();
         void count_ampersands(int &,const URLParametres&);
         QString & get_key_city(const QString&,const QString&);
         QString& get_key_c_reg(const QString & city,const QString & reg);

         QMap<QString,QString> m_mapRegions;
         QMap<QString,QString> m_mapRegionVin;
         QMap<QString,QString> m_mapRegionVol;
         QMap<QString,QString> m_mapRegionDnp;
         QMap<QString,QString> m_mapRegionDon;
         QMap<QString,QString> m_mapRegionZht;
         QMap<QString,QString> m_mapRegionZak;
         QMap<QString,QString> m_mapRegionZap;
         QMap<QString,QString> m_mapRegionIf;
         QMap<QString,QString> m_mapRegionKo;
         QMap<QString,QString> m_mapRegionKir;
         QMap<QString,QString> m_mapRegionCri;
         QMap<QString,QString> m_mapRegionLug;
         QMap<QString,QString> m_mapRegionLv;
         QMap<QString,QString> m_mapRegionNik;
         QMap<QString,QString> m_mapRegionOd;
         QMap<QString,QString> m_mapRegionPol;
         QMap<QString,QString> m_mapRegionRov;
         QMap<QString,QString> m_mapRegionSum;
         QMap<QString,QString> m_mapRegionTer;
         QMap<QString,QString> m_mapRegionKha;
         QMap<QString,QString> m_mapRegionKhe;
         QMap<QString,QString> m_mapRegionKhm;
         QMap<QString,QString> m_mapRegionChk;
         QMap<QString,QString> m_mapRegionChn;
         QMap<QString,QString> m_mapRegionChv;
         QMap<QString,QString> m_mapCityRegions;
         QList<QString> m_lisCurrencies;
         QString sNoFound = "NotF";
         const QString FILTER_NEW = "search%5Border%5D=created_at%3Adesc";
         const QString FILTER_CHEAP = "search%5Border%5D=filter_float_price%3Aasc";
         const QString FILTER_EXPENSIVE = "search%5Border%5D=filter_float_price%3Adesc";
         const QString DIST = "search%5Bdist%5D=";
         const QString WITH_PHOTO = "search%5Bphotos%5D=1";
         const QString WITH_TITLE = "search%5Bdescription%5D=1";
         const QString HOME_URL = "https://www.olx.ua/nedvizhimost/";
         const QString PRICE_FROM = "search%5Bfilter_float_price%3Afrom%5D=";
         const QString PRICE_TO = "search%5Bfilter_float_price%3Ato%5D=";
         const QString SEARCH = "search%5Bfilter_float_price%3Ato%5D=";
         const QString CURRENCY = "currency=";

};

#endif // CURLBUILDER_H
