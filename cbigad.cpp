#include "cbigad.h"

CBigAd::CBigAd()
{

}
QString &CBigAd::get_ttl_img()
{
    return m_sTitleImg;
}
void CBigAd::set_ttl_img(const QString &aImg)
{
    m_sTitleImg = aImg;
}
void CBigAd::set_ttl(const QString &aTtl)
{
    m_sTitle = aTtl;
}
QString& CBigAd::get_ttl()
{
  return m_sTitle;
}
QString& CBigAd::get_numb()
{
    return m_sNumberAd;
}
QString& CBigAd::get_geo_pos()
{
    return m_sGeoPosition;
}
QString& CBigAd::get_publ()
{
    return m_sPublicated;
}
void CBigAd::set_num(const QString &aNum)
{
    m_sNumberAd = aNum;
}
void CBigAd::set_geo_pos(const QString &aGeo)
{
    m_sGeoPosition = aGeo;
}
void CBigAd::set_publ(const QString &aPubl)
{
    m_sPublicated = aPubl;
}
void CBigAd::set_hdng(const QString &aHdng)
{
    m_sHeading = aHdng;
}
QString& CBigAd::get_hdng()
{
    return m_sHeading;
}
QString& CBigAd::get_country()
{
    return m_sCountry;
}
void CBigAd::set_country(const QString & aCountry)
{
    m_sCountry = aCountry;
}
QString& CBigAd::get_cnt_nights()
{
    return m_sCountNights;
}
void CBigAd::set_cnt_nights(const QString & aCnt)
{
    m_sCountNights = aCnt;
}
QString& CBigAd::get_s_hourly()
{
    return m_sSurrenderHourly;
}
void CBigAd::set_s_hourly(const QString &aH)
{
    m_sSurrenderHourly = aH;
}
void CBigAd::set_type_h(const QString &aHouse)
{
    m_sTypeHouse = aHouse;
}
void CBigAd::set_type_o(const QString &aObject)
{
    m_sTypeObject = aObject;
}
QString& CBigAd::get_type_h()
{
    return m_sTypeHouse;
}
QString& CBigAd::get_type_o()
{
    return  m_sTypeObject;
}
QString& CBigAd::get_total_area()
{
    return  m_sTotalArea;
}
void CBigAd::set_total_area(const QString &aTotal)
{
    m_sTotalArea = aTotal;
}
void CBigAd::set_floor(const QString &aFloor)
{
    m_sFloor = aFloor;
}
void CBigAd::set_floors(const QString &aFloors)
{
    m_sFloors = aFloors;
}
QString& CBigAd::get_floor()
{
    return m_sFloor;
}
QString& CBigAd::get_floors()
{
    return m_sFloors;
}
void CBigAd::set_rooms(const QString &aRooms)
{
    m_sRooms = aRooms;
}
QString& CBigAd::get_rooms()
{
    return m_sRooms;
}
void CBigAd::set_count_bed(const QString &aBed)
{
    m_sCountBed = aBed;
}
QString& CBigAd::get_count_bed()
{
    return m_sCountBed;
}
void CBigAd::set_nutrition(const QString &aN)
{
    m_sNutrition = aN;
}
QString& CBigAd::get_nutrition()
{
    return m_sNutrition;
}
void CBigAd::set_bathroom(const QString &aB)
{
    m_sBathroom = aB;
}
QString& CBigAd::get_bathroom()
{
    return m_sBathroom;
}
void CBigAd::set_repairs(const QString &aR)
{
    m_sRepairs = aR;
}
QString& CBigAd::get_repairs()
{
    return m_sRepairs;
}
void CBigAd::set_appliances(const QString &aA)
{
    m_sAppliances = aA;
}
QString& CBigAd::get_appliances()
{
    return m_sAppliances;
}
void CBigAd::set_media(const QString &aM)
{
    m_sMedia = aM;
}
QString& CBigAd::get_meadia()
{
    return m_sMedia;
}
void CBigAd::set_comfort(const QString &aC)
{
    m_sComfort = aC;
}
QString& CBigAd::get_comfort()
{
    return m_sComfort;
}
void CBigAd::set_infrst(const QString &aI)
{
    m_sInfrastructure = aI;
}
QString& CBigAd::get_infrst()
{
    return m_sInfrastructure;
}
void CBigAd::set_landscape(const QString &aL)
{
    m_sLandscape = aL;
}
QString& CBigAd::get_landscape()
{
    return m_sLandscape;
}
void CBigAd::set_descr(const QString &aD)
{
    m_sDescription = aD;
}
QString& CBigAd::get_descr()
{
    return m_sDescription;
}
QVector<QString> &CBigAd::get_vec()
{
    return m_vecImgs;
}
void CBigAd::set_vec(QVector<QString> &aVec)
{
    m_vecImgs = aVec;
}
QString& CBigAd::get_coop_real()
{
    return m_sCoopRealtors;
}
void CBigAd::set_coop_real(const QString &aCR)
{
    m_sCoopRealtors = aCR;
}
QString& CBigAd::get_crediting()
{
    return m_sCrediting;
}
void CBigAd::set_crediting(const QString &aC)
{
    m_sCrediting = aC;
}
QString& CBigAd::get_lcd_name()
{
    return m_sLCDName;
}
void CBigAd::set_lcd_name(const QString &aL)
{
    m_sLCDName = aL;
}
QString& CBigAd::get_comunication()
{
    return m_sCommunications;
}
void CBigAd::set_comunication(const QString &aC)
{
    m_sCommunications = aC;
}
QString& CBigAd::get_htng()
{
    return m_sHeating;
}
void CBigAd::set_htng(const QString &aH)
{
    m_sHeating = aH;
}
QString& CBigAd::get_layout()
{
    return m_sLayout;
}
void CBigAd::set_layout(const QString &aL)
{
    m_sLayout = aL;
}
QString& CBigAd::get_kitchen_area()
{
    return m_sKitchenAr;
}
void CBigAd::set_kitchen_area(const QString &aK)
{
    m_sKitchenAr = aK;
}
QString& CBigAd::get_year_c_d()
{
    return m_sYearConstrDestr;
}
void CBigAd::set_year_c_d(const QString &aY)
{
    m_sYearConstrDestr = aY;
}
QString& CBigAd::get_price()
{
    return m_sPrice;
}
void CBigAd::set_price(const QString &aP)
{
    m_sPrice = aP;
}
void CBigAd::set_ad_author(const QString &aAdAuth)
{
    m_sAdAuthor = aAdAuth;
}
QString& CBigAd::get_ad_author()
{
    return m_sAdAuthor;
}

