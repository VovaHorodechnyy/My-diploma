#ifndef CBIGAD_H
#define CBIGAD_H

#include <QVector>
#include <QString>


class CBigAd
{
    public:
        CBigAd();
        QString& get_ttl_img();
        QString& get_ttl();
        QString& get_geo_pos();
        QString& get_numb();
        QString& get_publ();
        QString& get_hdng();
        QString& get_htng();
        QString& get_country();
        QString& get_cnt_nights();
        QString& get_s_hourly();
        QString& get_type_h();
        QString& get_type_o();
        QString& get_total_area();
        QString& get_floor();
        QString& get_floors();
        QString& get_rooms();
        QString& get_count_bed();
        QString& get_nutrition();
        QString& get_bathroom();
        QString& get_repairs();
        QString& get_appliances();
        QString& get_meadia();
        QString& get_comfort();
        QString& get_infrst();
        QString& get_landscape();
        QString& get_descr();
        QString& get_coop_real();
        QString& get_crediting();
        QString& get_lcd_name();
        QString& get_layout();
        QString& get_kitchen_area();
        QString& get_comunication();
        QString& get_year_c_d();
        QString& get_price();
        QString& get_ad_author();
        QVector<QString>& get_vec();
        void set_coop_real(const QString&);
        void set_ttl_img(const QString &);
        void set_ttl(const QString &);
        void set_geo_pos(const QString &);
        void set_num(const QString &);
        void set_publ(const QString &);
        void set_hdng(const QString &);
        void set_htng(const QString &);
        void set_country(const QString&);
        void set_cnt_nights(const QString&);
        void set_s_hourly(const QString&);
        void set_type_h(const QString&);
        void set_type_o(const QString&);
        void set_total_area(const QString&);
        void set_floor(const QString&);
        void set_floors(const QString&);
        void set_rooms(const QString&);
        void set_count_bed(const QString&);
        void set_nutrition(const QString&);
        void set_bathroom(const QString&);
        void set_repairs(const QString&);
        void set_appliances(const QString&);
        void set_media(const QString&);
        void set_comfort(const QString&);
        void set_infrst(const QString &);
        void set_landscape(const QString &);
        void set_descr(const QString&);
        void set_vec(QVector<QString>&);
        void set_crediting(const QString&);
        void set_lcd_name(const QString&);
        void set_comunication(const QString&);
        void set_layout(const QString&);
        void set_kitchen_area(const QString&);
        void set_year_c_d(const QString&);
        void set_price(const QString&);
        void set_ad_author(const QString&);

    private:
        QString m_sAdAuthor;
        QString m_sYearConstrDestr;
        QString m_sLCDName;
        QString m_sAppliances;
        QString m_sNutrition;
        QString m_sCountBed;
        QString m_sCountNights;
        QString m_sCountry;
        QString m_sNumberAd;
        QString m_sTitleImg;
        QString m_sTitle;
        QString m_sGeoPosition;
        QString m_sPublicated;
        QString m_sAdFrom;
        QString m_sTypeHouse;
        QString m_sTypeObject;
        QString m_sFloors;
        QString m_sKitchenAr;
        QString m_sLayout;
        QString m_sHeating;
        QString m_sHeading;
        QString m_sFurnishing;
        QString m_sCommunications;
        QString m_sFloor;
        QString m_sTotalArea;
        QString m_sRooms;
        QString m_sBathroom;
        QString m_sRepairs;
        QString m_sComfort;
        QString m_sInfrastructure;
        QString m_sLandscape;
        QString m_sDescription;
        QString m_sPrice;
        QString m_sCommision;
        QString m_sCoopRealtors;
        QString m_sMedia;
        QString m_sExchange;
        QString m_sSurrenderHourly;
        QString m_sCrediting;
        QVector<QString> m_vecImgs;


};

#endif // CBIGAD_H
