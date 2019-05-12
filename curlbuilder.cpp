#include "curlbuilder.h"

CUrlBuilder::CUrlBuilder()
{
    fill_map_regions();
    fill_all_regs();
    fill_all_this_shit();
    m_lisCurrencies << "USD" << "EUR";

}
 QString & CUrlBuilder::get_key_city(const QString & aReg, const QString& aCity)
{

    if(aCity == "Искать по всей области »")
    {
        auto it = m_mapRegions.begin();
        auto end = m_mapRegions.end();
        for(;it != end;++it)
        {
            if(it.key() == aReg)
                return  it.value();
        }
    }
    if(aReg == "Винницкая область")
    {
        auto it = m_mapRegionVin.begin();
        auto end = m_mapRegionVin.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Волынская область")
    {
        auto it = m_mapRegionVol.begin();
        auto end = m_mapRegionVol.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Днепропетровская область")
    {
        auto it = m_mapRegionDnp.begin();
        auto end = m_mapRegionDnp.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Донецкая область")
    {
        auto it = m_mapRegionDon.begin();
        auto end = m_mapRegionDon.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Житомирская область")
    {
        auto it = m_mapRegionZht.begin();
        auto end = m_mapRegionZht.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Закарпатская область")
    {
        auto it = m_mapRegionZak.begin();
        auto end = m_mapRegionZak.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Запорожская область")
    {
        auto it = m_mapRegionZap.begin();
        auto end = m_mapRegionZap.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Ивано-Франковская область")
    {
        auto it = m_mapRegionIf.begin();
        auto end = m_mapRegionIf.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Киевская область")
    {
        auto it = m_mapRegionKo.begin();
        auto end = m_mapRegionKo.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Кировоградская область")
    {
        auto it = m_mapRegionKir.begin();
        auto end = m_mapRegionKir.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Крым (АРК)")
    {
        auto it = m_mapRegionCri.begin();
        auto end = m_mapRegionCri.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Луганская область")
    {
        auto it = m_mapRegionLug.begin();
        auto end = m_mapRegionLug.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Львовская область")
    {
        auto it = m_mapRegionLv.begin();
        auto end = m_mapRegionLv.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Николаевская область")
    {
        auto it = m_mapRegionNik.begin();
        auto end = m_mapRegionNik.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Одесская область")
    {
        auto it = m_mapRegionOd.begin();
        auto end = m_mapRegionOd.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Полтавская область")
    {
        auto it = m_mapRegionPol.begin();
        auto end = m_mapRegionPol.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Ровенская область")
    {
        auto it = m_mapRegionRov.begin();
        auto end = m_mapRegionRov.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Сумская область")
    {
        auto it = m_mapRegionSum.begin();
        auto end = m_mapRegionSum.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Тернопольская область")
    {
        auto it = m_mapRegionTer.begin();
        auto end = m_mapRegionTer.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Харьковская область")
    {
        auto it = m_mapRegionKha.begin();
        auto end = m_mapRegionKha.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Херсонская область")
    {
        auto it = m_mapRegionKhe.begin();
        auto end = m_mapRegionKhe.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Хмельницкая область")
    {
        auto it = m_mapRegionKhm.begin();
        auto end = m_mapRegionKhm.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Черкасская область")
    {
        auto it = m_mapRegionChk.begin();
        auto end = m_mapRegionChk.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Черниговская область")
    {
        auto it = m_mapRegionChn.begin();
        auto end = m_mapRegionChn.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    if(aReg == "Черновицкая область")
    {
        auto it = m_mapRegionChv.begin();
        auto end = m_mapRegionChv.end();
        for(;it != end;++it)
        {
            if(it.key() == aCity)
                return  it.value();
        }
    }
    return  sNoFound;


}
const QString CUrlBuilder::get_url_f_pararam(const URLParametres & aParam)
{
    bool isBeginQuery = false;
    QString sFinalURL = HOME_URL;
    const QString sKeyCity = get_key_city(aParam.sRegion,aParam.sCity);
    int count = 0;
    //count_ampersands(count,aParam);
    if(sKeyCity != "NotF")
    {
          sFinalURL+=sKeyCity;
    }
    if(aParam.sSearch != "")
    {
        sFinalURL+= "q-" + aParam.sSearch + "/";
    }

    if(aParam.fIsNew)
    {
        ++count;
        if(!isBeginQuery)
        {
            sFinalURL+="?";
        }
        sFinalURL += FILTER_NEW;
    }
    if(aParam.fIsInTtlNDesc)
    {
        if(!isBeginQuery)
        {
            sFinalURL+="?";
        }
        if(count)
            sFinalURL += "&";
        sFinalURL += WITH_TITLE;
        ++count;
    }
    if(aParam.fIsCheap)
    {

        if(!isBeginQuery)
        {
            sFinalURL+="?";
        }
        if(count)
            sFinalURL += "&";
        sFinalURL += FILTER_CHEAP;
        ++count;
    }

    if(aParam.nPriceFrom != -1)
    {

        if(!isBeginQuery)
        {
            sFinalURL+="?";
        }
        if(count)
            sFinalURL += "&";
        sFinalURL += PRICE_FROM + QString::number(aParam.nPriceFrom) ;
         ++count;
    }
    if(aParam.nPriceTo != -1)
    {

        if(!isBeginQuery)
        {
            sFinalURL+="?";
        }
        if(count)
            sFinalURL += "&";
        sFinalURL += PRICE_TO + QString::number(aParam.nPriceTo) ;
        ++count;
    }

    if(aParam.fIsPhoto)
    {

        if(!isBeginQuery)
        {
            sFinalURL+="?";
        }
        if(count)
            sFinalURL += "&";
        sFinalURL += WITH_PHOTO;
        ++count;
    }
    if(aParam.nKilometres != -1)
    {

        if(!isBeginQuery)
        {
            sFinalURL+="?";
        }
        if(count)
            sFinalURL += "&";
        sFinalURL += DIST + QString::number(aParam.nKilometres)  ;
        ++count;
    }
    if(aParam.fIsExpensive)
    {

        if(!isBeginQuery)
        {
            sFinalURL+="?";
        }
        if(count)
            sFinalURL += "&";
        sFinalURL += FILTER_EXPENSIVE ;
        ++count;
    }
    if(aParam.sCurrency != "")
    {

        if(!isBeginQuery)
        {
            sFinalURL+="?";
        }
        if(count)
            sFinalURL += "&";
        sFinalURL += CURRENCY + aParam.sCurrency ;
        ++count;
    }
    if(aParam.sCityRegion != "")
    {

        if(!isBeginQuery)
        {
            sFinalURL+="?";
        }
        if(count)
            sFinalURL += "&";
        sFinalURL += get_key_c_reg(aParam.sCity,aParam.sCityRegion);
        ++count;
    }

    return sFinalURL;

}
QString& CUrlBuilder::get_key_c_reg(const QString & city, const QString & region)
{
    auto begin = m_mapCityRegions.begin() , end = m_mapCityRegions.end();
    for (;begin != end ; ++begin)
    {
         auto key = begin.key().split("||");
         if(key[0] == city)
         {
             if(key[1] == region)
                 return begin.value();
         }
    }
}
void CUrlBuilder::count_ampersands(int &aCount, const URLParametres & aParams)
{
    aCount = 0;
    if(aParams.fIsPhoto)
        ++aCount;
    if(aParams.fIsInTtlNDesc)
        ++aCount;
    if(aParams.fIsCheap)
        ++aCount;
    if(aParams.fIsExpensive)
        ++aCount;
    if(aParams.fIsPhoto)
        ++aCount;
    if(aParams.fIsNew)
        ++aCount;
    if(aParams.nPriceFrom != -1)
        ++aCount;
    if(aParams.nPriceTo != -1)
        ++aCount;
    if(aParams.nKilometres != -1)
        ++aCount;
}
void CUrlBuilder::fill_all_regs()
{
    fill_region_vin();
    fill_region_vol();
    fill_region_dnp();
    fill_region_don();
    fill_region_zht();
    fill_region_zak();
    fill_region_zap();
    fill_region_if();
    fill_region_ko();
    fill_region_kir();
    fill_region_cri();
    fill_region_lug();
    fill_region_lv();
    fill_region_nik();
    fill_region_od();
    fill_region_pol();
    fill_region_rov();
    fill_region_sum();
    fill_region_ter();
    fill_region_kha();
    fill_region_khe();
    fill_region_khm();
    fill_region_chk();
    fill_region_chn();
    fill_region_chv();
}
void CUrlBuilder::fill_map_regions()
{

    m_mapRegions["Винницкая область"] = "vin/";
    m_mapRegions["Волынская область"] = "vol/";
    m_mapRegions["Днепропетровская область"] = "dnp/";
    m_mapRegions["Донецкая область"] = "don/";
    m_mapRegions["Житомирская область"] = "zht/";
    m_mapRegions["Закарпатская область"] = "zak/";
    m_mapRegions["Запорожская область"] = "zap/";
    m_mapRegions["Ивано-Франковская область"] = "if/";
    m_mapRegions["Киевская область"] = "ko/";
    m_mapRegions["Кировоградская область"] = "kir/";
    m_mapRegions["Крым (АРК)"] = "kri/";
    m_mapRegions["Луганская область"] = "lug/";
    m_mapRegions["Львовская область"] = "lv/";
    m_mapRegions["Николаевская область"] = "nik/";
    m_mapRegions["Одесская область"] = "od/";
    m_mapRegions["Полтавская область"] = "pol/";
    m_mapRegions["Ровенская область"] = "rov/";
    m_mapRegions["Сумская область"] = "sum/";
    m_mapRegions["Тернопольская область"] = "ter/";
    m_mapRegions["Харьковская область"] = "kha/";
    m_mapRegions["Хмельницкая область"] = "khm/";
    m_mapRegions["Херсонская область"] = "khe/";
    m_mapRegions["Черкасская область"] = "chk/";
    m_mapRegions["Черниговская область"] = "chn/";
    m_mapRegions["Черновицкая область"] = "chv/";

}
void CUrlBuilder::fill_region_vin()
{
    m_mapRegionVin["Бар"] = "bar/";
    m_mapRegionVin["Бершадь"] = "bershad/";
    m_mapRegionVin["Винница"] = "vinnitsa/";
    m_mapRegionVin["Гайсин"] = "gaysin/";
    m_mapRegionVin["Гнивань"] = "gnivan/";
    m_mapRegionVin["Жмеринка"] = "zhmerinka/";
    m_mapRegionVin["Ильинцы"] = "ilintsy/";
    m_mapRegionVin["Казатин"] = "kazatin/";
    m_mapRegionVin["Калиновка"] = "kalinovka/";
    m_mapRegionVin["Крыжополь"] = "kryzhopol/";
    m_mapRegionVin["Ладыжин"] = "ladyzhin/";
    m_mapRegionVin["Липовец"] = "lipovets/";
    m_mapRegionVin["Могилев-Подольский"] = "mogilyev-podolskiy/";
    m_mapRegionVin["Немиров"] = "nemirov/";
    m_mapRegionVin["Песочин"] = "pesochin/";
    m_mapRegionVin["Погребище"] = "pogrebishche/";
    m_mapRegionVin["Стрижавка"] = "strizhavka/";
    m_mapRegionVin["Тульчин"] = "tulchin/";
    m_mapRegionVin["Хмельник"] = "khmelnik/";
    m_mapRegionVin["Чечельник"] = "chechelnik/";
    m_mapRegionVin["Шаргород"] = "shargorod/";
    m_mapRegionVin["Ямполь"] = "yampol/";

}
void CUrlBuilder::fill_region_vol()
{
    m_mapRegionVol["Берестечко"] = "berestechko/";
    m_mapRegionVol["Владимир-Волынский"] = "vladimir-volynskiy/";
    m_mapRegionVol["Горохов"] = "gorokhov/";
    m_mapRegionVol["Иваничи"] = "ivanichi/";
    m_mapRegionVol["Камень-Каширский"] = "kamen-kashirskiy/";
    m_mapRegionVol["Киверцы"] = "kivertsy/";
    m_mapRegionVol["Ковель"] = "kovel/";
    m_mapRegionVol["Луцк"] = "lutsk/";
    m_mapRegionVol["Любешов"] = "lyubeshov/";
    m_mapRegionVol["Любомль"] = "lyuboml/";
    m_mapRegionVol["Маневичи"] = "manevichi/";
    m_mapRegionVol["Нововолынск"] = "novovolynsk/";
    m_mapRegionVol["Ратно"] = "ratno/";
    m_mapRegionVol["Рожище"] = "rozhishche/";
    m_mapRegionVol["Старая Выжевка"] = "staraya-vyzhevka/";
    m_mapRegionVol["Турийск"] = "turiysk/";
    m_mapRegionVol["Устилуг"] = "ustilug/";
    m_mapRegionVol["Цумань"] = "tsuman/";
    m_mapRegionVol["Шацк"] = "shatsk/";

}
void CUrlBuilder::fill_region_dnp()
{
    m_mapRegionDnp["Апостолово"] = "apostolovo/";
    m_mapRegionDnp["Верхнеднепровск"] = "verkhnedneprovsk/";
    m_mapRegionDnp["Вольногорск"] = "volnogorsk/";
    m_mapRegionDnp["Днепр"] = "dnepr/";
    m_mapRegionDnp["Желтые Воды"] = "zhyeltye-vody/";
    m_mapRegionDnp["Каменское"] = "kamenskoe/";
    m_mapRegionDnp["Кривой Рог"] = "krivoyrog/";
    m_mapRegionDnp["Марганец"] = "marganets/";
    m_mapRegionDnp["Никополь"] = "nikopol/";
    m_mapRegionDnp["Новомосковск"] = "novomoskovsk/";
    m_mapRegionDnp["Орджоникидзе"] = "ordzhonikidze/";
    m_mapRegionDnp["Павлоград"] = "pavlograd/";
    m_mapRegionDnp["Перещепино"] = "pereshchepino/";
    m_mapRegionDnp["Першотравенск"] = "pershotravensk/";
    m_mapRegionDnp["Подгородное"] = "podgorodnoe/";
    m_mapRegionDnp["Пятихатки"] = "pyatikhatki/";
    m_mapRegionDnp["Синельниково"] = "sinelnikovo/";
    m_mapRegionDnp["Терновка"] = "ternovka/";
    m_mapRegionDnp["Чаплинка"] = "chaplinka/";

}
void CUrlBuilder::fill_region_don()
{
    m_mapRegionDon["Авдеевка"] = "avdeevka/";
    m_mapRegionDon["Александровка"] = "aleksandrovka/";
    m_mapRegionDon["Амвросиевка"] = "amvrosievka/";
    m_mapRegionDon["Артемовск"] = "artemovsk/";
    m_mapRegionDon["Волноваха"] = "volnovakha/";
    m_mapRegionDon["Горловка"] = "gorlovka/";
    m_mapRegionDon["Дебальцево"] = "debaltsevo/";
    m_mapRegionDon["Дзержинск"] = "dzerzhinsk/";
    m_mapRegionDon["Димитров"] = "dimitrov/";
    m_mapRegionDon["Доброполье"] = "dobropole/";
    m_mapRegionDon["Докучаевск"] = "dokuchaevsk/";
    m_mapRegionDon["Донецк"] = "donetsk/";
    m_mapRegionDon["Дружковка"] = "druzhkovka/";
    m_mapRegionDon["Енакиево"] = "enakievo/";
    m_mapRegionDon["Ждановка"] = "zhdanovka/";
    m_mapRegionDon["Зугрэс"] = "zugres/";
    m_mapRegionDon["Кировское"] = "kirovskoe/";
    m_mapRegionDon["Константиновка"] = "konstantinovka/";
    m_mapRegionDon["Краматорск"] = "kramatorsk/";
    m_mapRegionDon["Красноармейск"] = "krasnoarmeysk/";
    m_mapRegionDon["Красный Лиман"] = "krasnyyliman/";
    m_mapRegionDon["Майорск"] = "mayorsk/";
    m_mapRegionDon["Макеевка"] = "makeevka/";
    m_mapRegionDon["Мариуполь"] = "mariupol/";
    m_mapRegionDon["Марьинка"] = "marinka/";
    m_mapRegionDon["Новоазовск"] = "novoazovsk/";
    m_mapRegionDon["Новогродовка"] = "novogrodovka/";
    m_mapRegionDon["Селидово"] = "selidovo/";
    m_mapRegionDon["Славянск"] = "slavyansk/";
    m_mapRegionDon["Снежное"] = "snezhnoe/";
    m_mapRegionDon["Соледар"] = "soledar/";
    m_mapRegionDon["Старобешево"] = "starobeshevo/";
    m_mapRegionDon["Торез"] = "torez/";
    m_mapRegionDon["Угледар"] = "ugledar/";
    m_mapRegionDon["Харцызск"] = "khartsyzsk/";
    m_mapRegionDon["Шахтерск"] = "shakhtyersk/";
    m_mapRegionDon["Ясиноватая"] = "yasinovataya/";

}
void CUrlBuilder::fill_region_zht()
{
    m_mapRegionZht["Андрушевка"] = "andrushevka/";
    m_mapRegionZht["Барановка"] = "baranovka_20143/";
    m_mapRegionZht["Бердичев"] = "berdichev/";
    m_mapRegionZht["Володарск-Волынский"] = "volodarsk-volynskiy/";
    m_mapRegionZht["Емильчино"] = "yemilchino/";
    m_mapRegionZht["Житомир/"] = "zhitomir/";
    m_mapRegionZht["Иршанск"] = "irshansk/";
    m_mapRegionZht["Коростень"] = "korosten/";
    m_mapRegionZht["Коростышев"] = "korostyshev/";
    m_mapRegionZht["Малин"] = "malin/";
    m_mapRegionZht["Новоград-Волынский"] = "novograd-volynskiy/";
    m_mapRegionZht["Овруч"] = "ovruch/";
    m_mapRegionZht["Олевск"] = "olevsk/";
    m_mapRegionZht["Попельня"] = "popelnya/";
    m_mapRegionZht["Радомышль"] = "radomyshl/";
    m_mapRegionZht["Романов"] = "romanov/";
    m_mapRegionZht["Черняхов"] = "chernyahov/";

}
void CUrlBuilder::fill_region_zak()
{
    m_mapRegionZak["Берегово"] = "beregovo/";
    m_mapRegionZak["Буштына"] = "bushtyna/";
    m_mapRegionZak["Великий Бычков"] = "velikiy-bychkov/";
    m_mapRegionZak["Виноградов"] = "vinogradov/";
    m_mapRegionZak["Вышково"] = "vyshkovo/";
    m_mapRegionZak["Дубовое"] = "dubovoye/";
    m_mapRegionZak["Иршава"] = "irshava/";
    m_mapRegionZak["Королево"] = "korolevo/";
    m_mapRegionZak["Межгорье"] = "mezhgorye/";
    m_mapRegionZak["Мукачево"] = "mukachevo/";
    m_mapRegionZak["Перечин"] = "perechin/";
    m_mapRegionZak["Рахов"] = "rakhov/";
    m_mapRegionZak["Свалява"] = "svalyava/";
    m_mapRegionZak["Солотвина"] = "solotvina/";
    m_mapRegionZak["Тячев"] = "tyachev/";
    m_mapRegionZak["Ужгород"] = "uzhgorod/";
    m_mapRegionZak["Хуст"] = "khust/";
    m_mapRegionZak["Чоп"] = "chop/";


}
void CUrlBuilder::fill_region_zap()
{
    m_mapRegionZap["Акимовка"] = "akimovka/";
    m_mapRegionZap["Беляевка"] = "belyaevka_475/";
    m_mapRegionZap["Бердянск"] = "berdyansk/";
    m_mapRegionZap["Васильевка"] = "vasilevka/";
    m_mapRegionZap["Веселое"] = "veseloe/";
    m_mapRegionZap["Вольнянск"] = "volnyansk/";
    m_mapRegionZap["Гуляйполе"] = "gulyaypole/";
    m_mapRegionZap["Днепрорудное"] = "dneprorudnoe/";
    m_mapRegionZap["Запорожье"] = "zaporozhe/";
    m_mapRegionZap["Каменка-Днепровская"] = "kamenka-dneprovskaya/";
    m_mapRegionZap["Куйбышево"] = "kuybyshevo/";
    m_mapRegionZap["Кушугум"] = "kushugum/";
    m_mapRegionZap["Мелитополь"] = "melitopol/";
    m_mapRegionZap["Михайловка"] = "mihaylovka/";
    m_mapRegionZap["Молочанск"] = "molochansk/";
    m_mapRegionZap["Орехов"] = "orekhov/";
    m_mapRegionZap["Пологи"] = "pologi/";
    m_mapRegionZap["Приморск"] = "primorsk/";
    m_mapRegionZap["Розовка"] = "rozovka/";
    m_mapRegionZap["Токмак"] = "tokmak/";
    m_mapRegionZap["Энергодар"] = "energodar/";

}
void CUrlBuilder::fill_region_if()
{
    m_mapRegionIf["Богородчаны"] = "bogorodchany/";
    m_mapRegionIf["Болехов"] = "bolekhov/";
    m_mapRegionIf["Бурштын"] = "burshtyn/";
    m_mapRegionIf["Галич"] = "galich/";
    m_mapRegionIf["Городенка"] = "gorodenka/";
    m_mapRegionIf["Делятин"] = "delyatin/";
    m_mapRegionIf["Долина"] = "dolina/";
    m_mapRegionIf["Ивано-Франковск"] = "ivano-frankovsk/";
    m_mapRegionIf["Калуш"] = "kalush/";
    m_mapRegionIf["Коломыя"] = "kolomyya/";
    m_mapRegionIf["Косов"] = "kosov/";
    m_mapRegionIf["Ланчин"] = "lanchin/";
    m_mapRegionIf["Надворная"] = "nadvornaya/";
    m_mapRegionIf["Перегинское"] = "pereginskoye/";
    m_mapRegionIf["Рогатин"] = "rogatin/";
    m_mapRegionIf["Снятын"] = "snyatyn/";
    m_mapRegionIf["Тлумач"] = "tlumach/";
    m_mapRegionIf["Тысменица"] = "tysmenitsa/";
    m_mapRegionIf["Яремче"] = "yaremche/";

}
void CUrlBuilder::fill_region_ko()
{
    m_mapRegionKo["Барышевка"] = "baryshevka/";
    m_mapRegionKo["Белая Церковь"] = "belayatserkov/";
    m_mapRegionKo["Березань"] = "berezan/";
    m_mapRegionKo["Богуслав"] = "boguslav/";
    m_mapRegionKo["Борисполь"] = "borispol/";
    m_mapRegionKo["Бородянка"] = "borodyanka/";
    m_mapRegionKo["Боярка"] = "boyarka/";
    m_mapRegionKo["Бровары"] = "brovary/";
    m_mapRegionKo["Буча"] = "bucha/";
    m_mapRegionKo["Васильков"] = "vasilkov/";
    m_mapRegionKo["Вишневое"] = "vishnevoe/";
    m_mapRegionKo["Володарка"] = "volodarka/";
    m_mapRegionKo["Вышгород"] = "vyshgorod/";
    m_mapRegionKo["Глеваха"] = "glevaxa/";
    m_mapRegionKo["Гостомель"] = "gostomel/";
    m_mapRegionKo["Иванков"] = "ivankov/";
    m_mapRegionKo["Ирпень"] = "irpen/";
    m_mapRegionKo["Кагарлык"] = "kagarlyk/";
    m_mapRegionKo["Киев"] = "kiev/";
    m_mapRegionKo["Коцюбинское"] = "kotsyubinskoe/";
    m_mapRegionKo["Макаров"] = "makarov/";
    m_mapRegionKo["Мироновка"] = "mironovka/";
    m_mapRegionKo["Обухов"] = "obukhov/";
    m_mapRegionKo["Переяслав-Хмельницкий"] = "pereyaslav-khmelnitskiy/";
    m_mapRegionKo["Припять"] = "pripyat/";
    m_mapRegionKo["Ржищев"] = "rzhishchev/";
    m_mapRegionKo["Рокитное"] = "rokitnoe/";
    m_mapRegionKo["Сквира"] = "skvira/";
    m_mapRegionKo["Славутич"] = "slavutich/";
    m_mapRegionKo["Тараща"] = "tarashcha/";
    m_mapRegionKo["Тетиев"] = "tetiev/";
    m_mapRegionKo["Узин"] = "uzin/";
    m_mapRegionKo["Украинка"] = "ukrainka/";
    m_mapRegionKo["Фастов"] = "fastov/";
    m_mapRegionKo["Чернобыль"] = "chernobyl/";
    m_mapRegionKo["Яготин"] = "yagotin/";

}
void CUrlBuilder::fill_region_kir()
{
    m_mapRegionKir["Александрия"] = "aleksandriya/";
    m_mapRegionKir["Бобринец"] = "bobrinets/";
    m_mapRegionKir["Власовка"] = "vlasovka/";
    m_mapRegionKir["Гайворон"] = "gayvoron/";
    m_mapRegionKir["Долинская"] = "dolinskaya/";
    m_mapRegionKir["Знаменка"] = "znamenka/";
    m_mapRegionKir["Кропивницкий"] = "kropivnitskiy/";
    m_mapRegionKir["Малая Виска"] = "malayaviska/";
    m_mapRegionKir["Новая Прага"] = "novaya-praga/";
    m_mapRegionKir["Новоархангельск"] = "novoarkhangelsk/";
    m_mapRegionKir["Новое"] = "novoye/";
    m_mapRegionKir["Новомиргород"] = "novomirgorod/";
    m_mapRegionKir["Новоукраинка"] = "novoukrainka/";
    m_mapRegionKir["Первомайск"] = "pervomaysk_56/";
    m_mapRegionKir["Петрово"] = "petrovo/";
    m_mapRegionKir["Помошная"] = "pomoshnaya/";
    m_mapRegionKir["Светловодск"] = "svetlovodsk/";
    m_mapRegionKir["Смолино"] = "smolino/";

}
void CUrlBuilder::fill_region_cri()
{
    m_mapRegionCri["Алупка"] = "alupka/";
    m_mapRegionCri["Алушта"] = "alushta/";
    m_mapRegionCri["Армянск"] = "armyansk/";
    m_mapRegionCri["Бахчисарай"] = "bakhchisaray/";
    m_mapRegionCri["Белогорск"] = "belogorsk/";
    m_mapRegionCri["Береговое"] = "beregovo_345/";
    m_mapRegionCri["Джанкой"] = "dzhankoy/";
    m_mapRegionCri["Евпатория"] = "evpatoriya/";
    m_mapRegionCri["Знаменка"] = "znamenka_372/";
    m_mapRegionCri["Инкерман"] = "inkerman/";
    m_mapRegionCri["Керчь"] = "kerch/";
    m_mapRegionCri["Красногвардейское"] = "krasnogvardeiskoe/";
    m_mapRegionCri["Красноперекопск"] = "krasnoperekopsk/";
    m_mapRegionCri["Раздольное"] = "razdolnoye/";
    m_mapRegionCri["Саки"] = "saki/";
    m_mapRegionCri["Севастополь"] = "sevastopol/";
    m_mapRegionCri["Симферополь"] = "simferopol/";
    m_mapRegionCri["Старый Крым"] = "staryy-krym/";
    m_mapRegionCri["Судак"] = "sudak/";
    m_mapRegionCri["Феодосия"] = "feodosiya/";
    m_mapRegionCri["Черноморское"] = "chernomorskoye/";
    m_mapRegionCri["Щёлкино"] = "shchyelkino/";
    m_mapRegionCri["Ялта"] = "yalta/";

}
void CUrlBuilder::fill_region_lug()
{
    m_mapRegionLug["Александровск"] = "aleksandrovsk/";
    m_mapRegionLug["Алмазная"] = "almaznaya/";
    m_mapRegionLug["Алчевск"] = "alchevsk/";
    m_mapRegionLug["Антрацит"] = "antratsit/";
    m_mapRegionLug["Артемовск"] = "artyemovsk/";
    m_mapRegionLug["Брянка"] = "bryanka/";
    m_mapRegionLug["Вахрушево"] = "vakhrushevo/";
    m_mapRegionLug["Горное"] = "gornoe/";
    m_mapRegionLug["Горское"] = "gorskoe/";
    m_mapRegionLug["Зимогорье"] = "zimogore/";
    m_mapRegionLug["Золотое"] = "zolotoe/";
    m_mapRegionLug["Зоринск"] = "zorinsk/";
    m_mapRegionLug["Ирмино"] = "teplogorsk/";
    m_mapRegionLug["Кировск"] = "kirovsk/";
    m_mapRegionLug["Краснодон"] = "krasnodon/";
    m_mapRegionLug["Краснопартизанск"] = "krasnopartizansk/";
    m_mapRegionLug["Красный Луч"] = "krasnyyluch/";
    m_mapRegionLug["Кременная"] = "kremennaya/";
    m_mapRegionLug["Лисичанск"] = "lisichansk/";
    m_mapRegionLug["Луганск"] = "lugansk/";
    m_mapRegionLug["Лутугино"] = "lutugino/";
    m_mapRegionLug["Миусинск"] = "miusinsk/";
    m_mapRegionLug["Молодогвардейск"] = "molodogvardeysk/";
    m_mapRegionLug["Новодружеск"] = "novodruzhesk/";
    m_mapRegionLug["Новопсков"] = "novopskov/";
    m_mapRegionLug["Первомайск"] = "pervomaysk_326/";
    m_mapRegionLug["Перевальск"] = "perevalsk/";
    m_mapRegionLug["Петровское"] = "petrovskoe/";
    m_mapRegionLug["Попасная"] = "popasnaya/";
    m_mapRegionLug["Приволье"] = "privole/";
    m_mapRegionLug["Ровеньки"] = "rovenki/";
    m_mapRegionLug["Рубежное"] = "rubezhnoe/";
    m_mapRegionLug["Сватово"] = "svatovo/";
    m_mapRegionLug["Свердловск"] = "sverdlovsk/";
    m_mapRegionLug["Северодонецк"] = "severodonetsk/";
    m_mapRegionLug["Станица Луганская"] = "stanica-luganskaya/";
    m_mapRegionLug["Старобельск"] = "starobelsk/";
    m_mapRegionLug["Стаханов"] = "stakhanov/";
    m_mapRegionLug["Суходольск"] = "sukhodolsk/";
    m_mapRegionLug["Счастье"] = "schaste/";
    m_mapRegionLug["Червонопартизанск"] = "chervonopartizansk_433/";

}
void CUrlBuilder::fill_region_lv()
{
    m_mapRegionLv["Белз"] = "belz/";
    m_mapRegionLv["Бобрка"] = "bobrka/";
    m_mapRegionLv["Борислав"] = "borislav/";
    m_mapRegionLv["Броды"] = "brody/";
    m_mapRegionLv["Буск"] = "busk/";
    m_mapRegionLv["Великие Мосты"] = "velikie-mosty/";
    m_mapRegionLv["Винники"] = "vinniki/";
    m_mapRegionLv["Глиняны"] = "glinyany/";
    m_mapRegionLv["Городок"] = "gorodok_262/";
    m_mapRegionLv["Добромиль"] = "dobromil/";
    m_mapRegionLv["Дрогобыч"] = "drogobych/";
    m_mapRegionLv["Дубляны"] = "dublyany/";
    m_mapRegionLv["Жидачев"] = "zhidachev/";
    m_mapRegionLv["Жолква"] = "zholkva/";
    m_mapRegionLv["Золочев"] = "zolochev/";
    m_mapRegionLv["Каменка-Бугская"] = "kamenka-bugskaya/";
    m_mapRegionLv["Львов"] = "lvov/";
    m_mapRegionLv["Мостиска"] = "mostiska/";
    m_mapRegionLv["Николаев"] = "nikolaev/";
    m_mapRegionLv["Новояворовск"] = "novoyavorovsk/";
    m_mapRegionLv["Новый Роздол"] = "novyy-rozdol/";
    m_mapRegionLv["Перемышляны"] = "peremyshlyane/";
    m_mapRegionLv["Пустомыты"] = "pustomyty/";
    m_mapRegionLv["Рава-Русская"] = "rava-russkaya/";
    m_mapRegionLv["Радехов"] = "radekhov/";
    m_mapRegionLv["Рудки"] = "rudki/";
    m_mapRegionLv["Самбор"] = "sambor/";
    m_mapRegionLv["Сколе"] = "skole/";
    m_mapRegionLv["Сокаль"] = "sokal/";
    m_mapRegionLv["Сосновка"] = "sosnovka/";
    m_mapRegionLv["Старый Самбор"] = "staryy-sambor/";
    m_mapRegionLv["Стебник"] = "stebnik/";
    m_mapRegionLv["Стрый"] = "stryy/";
    m_mapRegionLv["Трускавец"] = "truskavets/";
    m_mapRegionLv["Угнев"] = "ugnev/";
    m_mapRegionLv["Хыров"] = "khyrov/";
    m_mapRegionLv["Червоноград"] = "chervonograd/";
    m_mapRegionLv["Яворов"] = "yavorov/";

}
void CUrlBuilder::fill_region_nik()
{
    m_mapRegionNik["Александровка"] = "aleksandrovka_665/";
    m_mapRegionNik["Арбузинка"] = "arbuzinka/";
    m_mapRegionNik["Баштанка"] = "bashtanka/";
    m_mapRegionNik["Березнеговатое"] = "bereznegovatoye/";
    m_mapRegionNik["Братское"] = "bratskoye/";
    m_mapRegionNik["Веселиново"] = "veselinovo/";
    m_mapRegionNik["Вознесенск"] = "voznesensk/";
    m_mapRegionNik["Врадиевка"] = "vradievka/";
    m_mapRegionNik["Доманевка"] = "domanevka/";
    m_mapRegionNik["Еланец"] = "yelanets/";
    m_mapRegionNik["Казанка"] = "kazanka/";
    m_mapRegionNik["Кривое Озеро"] = "krivoe-ozero/";
    m_mapRegionNik["Николаев"] = "nikolaev_106/";
    m_mapRegionNik["Новая Одесса"] = "novaya-odessa/";
    m_mapRegionNik["Новый Буг"] = "novyybug/";
    m_mapRegionNik["Очаков"] = "ochakov/";
    m_mapRegionNik["Первомайск"] = "pervomaysk/";
    m_mapRegionNik["Снигиревка"] = "snigirevka/";
    m_mapRegionNik["Южноукраинск"] = "yuzhnoukrainsk/";

}
void CUrlBuilder::fill_region_od()
{
    m_mapRegionOd["Ананьев"] = "ananev/";
    m_mapRegionOd["Арциз"] = "artsiz/";
    m_mapRegionOd["Балта"] = "balta/";
    m_mapRegionOd["Белгород-Днестровский"] = "belgorod-dnestrovskiy/";
    m_mapRegionOd["Беляевка"] = "belyaevka_43045/";
    m_mapRegionOd["Березовка"] = "berezovka/";
    m_mapRegionOd["Болград"] = "bolgrad/";
    m_mapRegionOd["Великодолинское"] = "velikodolinskoe/";
    m_mapRegionOd["Измаил"] = "izmail/";
    m_mapRegionOd["Ильичевск"] = "ilichyevsk/";
    m_mapRegionOd["Килия"] = "kiliya/";
    m_mapRegionOd["Кодыма"] = "kodyma/";
    m_mapRegionOd["Котовск"] = "kotovsk/";
    m_mapRegionOd["Любашевка"] = "lyubashevka/";
    m_mapRegionOd["Овидиополь"] = "ovidiopol/";
    m_mapRegionOd["Одесса"] = "odessa/";
    m_mapRegionOd["Раздельная"] = "razdelnaya/";
    m_mapRegionOd["Рени"] = "reni/";
    m_mapRegionOd["Татарбунары"] = "tatarbunary/";
    m_mapRegionOd["Теплодар"] = "teplodar/";
    m_mapRegionOd["Ширяево"] = "shiryaevo/";
    m_mapRegionOd["Южное"] = "yuzhnoe/";

}
void CUrlBuilder::fill_region_pol()
{
    m_mapRegionPol["Гадяч"] = "gadyach/";
    m_mapRegionPol["Глобино"] = "globino/";
    m_mapRegionPol["Горишные Плавни"] = "gorishnyye%20plavni/";
    m_mapRegionPol["Градижск"] = "gradizhsk/";
    m_mapRegionPol["Гребенка"] = "grebyenka/";
    m_mapRegionPol["Дергачи"] = "dergachi_277/";
    m_mapRegionPol["Диканька"] = "dikanka/";
    m_mapRegionPol["Зеньков"] = "zenkov/";
    m_mapRegionPol["Карловка"] = "karlovka/";
    m_mapRegionPol["Кобеляки"] = "kobelyaki/";
    m_mapRegionPol["Котельва"] = "kotelva/";
    m_mapRegionPol["Кременчуг"] = "kremenchug/";
    m_mapRegionPol["Лохвица"] = "lokhvitsa/";
    m_mapRegionPol["Лубны"] = "lubny/";
    m_mapRegionPol["Миргород"] = "mirgorod/";
    m_mapRegionPol["Новые Санжары"] = "novyye-sanzhary/";
    m_mapRegionPol["Пирятин"] = "piryatin/";
    m_mapRegionPol["Полтава"] = "poltava/";
    m_mapRegionPol["Решетиловка"] = "reshetilovka/";
    m_mapRegionPol["Хорол"] = "khorol/";
    m_mapRegionPol["Червонозаводское"] = "chervonozavodskoe/";
    m_mapRegionPol["Чутово"] = "chutovo/";

}
void CUrlBuilder::fill_region_rov()
{
    m_mapRegionRov["Березне"] = "berezne/";
    m_mapRegionRov["Вараш"] = "varash/";
    m_mapRegionRov["Владимирец"] = "vladimirets/";
    m_mapRegionRov["Дубно"] = "dubno/";
    m_mapRegionRov["Дубровица"] = "dubrovitsa/";
    m_mapRegionRov["Заречное"] = "zarechnoye/";
    m_mapRegionRov["Здолбунов"] = "zdolbunov/";
    m_mapRegionRov["Квасилов"] = "kvasilov/";
    m_mapRegionRov["Клевань"] = "klevan/";
    m_mapRegionRov["Корец"] = "korets/";
    m_mapRegionRov["Костополь"] = "kostopol/";
    m_mapRegionRov["Млинов"] = "mlinov/";
    m_mapRegionRov["Острог"] = "ostrog/";
    m_mapRegionRov["Радивилов"] = "radivilov/";
    m_mapRegionRov["Ровно"] = "rovno/";
    m_mapRegionRov["Рокитное"] = "rokitnoe_699/";
    m_mapRegionRov["Сарны"] = "sarny/";
}
void CUrlBuilder::fill_region_sum()
{
    m_mapRegionSum["Ахтырка"] = "akhtyrka/";
    m_mapRegionSum["Белополье"] = "belopole/";
    m_mapRegionSum["Бурынь"] = "buryn/";
    m_mapRegionSum["Ворожба"] = "vorozhba/";
    m_mapRegionSum["Воронеж"] = "voronezh/";
    m_mapRegionSum["Глухов"] = "glukhov/";
    m_mapRegionSum["Дружба"] = "druzhba/";
    m_mapRegionSum["Конотоп"] = "konotop/";
    m_mapRegionSum["Краснополье"] = "krasnopolye/";
    m_mapRegionSum["Кролевец"] = "krolevets/";
    m_mapRegionSum["Лебедин"] = "lebedin/";
    m_mapRegionSum["Путивль"] = "putivl/";
    m_mapRegionSum["Ромны"] = "romny/";
    m_mapRegionSum["Свесса"] = "svessa/";
    m_mapRegionSum["Середина-Буда"] = "seredina-buda/";
    m_mapRegionSum["Сумы"] = "sumy/";
    m_mapRegionSum["Тростянец"] = "trostyanets/";
    m_mapRegionSum["Шостка"] = "shostka/";

}
void CUrlBuilder::fill_region_ter()
{
    m_mapRegionTer["Бережаны"] = "berezhany/";
    m_mapRegionTer["Борщев"] = "borshchyev/";
    m_mapRegionTer["Бучач"] = "buchach/";
    m_mapRegionTer["Великая Березовица"] = "velikaya-berezovitsa/";
    m_mapRegionTer["Гусятин"] = "gusyatin/";
    m_mapRegionTer["Залещики"] = "zaleshchiki/";
    m_mapRegionTer["Збараж"] = "zbarazh/";
    m_mapRegionTer["Зборов"] = "zborov/";
    m_mapRegionTer["Козова"] = "kozova/";
    m_mapRegionTer["Копычинцы"] = "kopychintsy/";
    m_mapRegionTer["Кременец"] = "kremenets/";
    m_mapRegionTer["Лановцы"] = "lanovtsy/";
    m_mapRegionTer["Монастыриска"] = "monastyriska/";
    m_mapRegionTer["Подволочиск"] = "podvolochisk/";
    m_mapRegionTer["Подгайцы"] = "podgaytsy/";
    m_mapRegionTer["Почаев"] = "pochaev/";
    m_mapRegionTer["Скалат"] = "skalat/";
    m_mapRegionTer["Теребовля"] = "terebovlya/";
    m_mapRegionTer["Тернополь"] = "ternopol/";
    m_mapRegionTer["Хоростков"] = "khorostkov/";
    m_mapRegionTer["Чертков"] = "chertkov/";
    m_mapRegionTer["Шумск"] = "shumsk/";

}
void CUrlBuilder::fill_region_kha()
{
    m_mapRegionKha["Балаклея"] = "balakleya/";
    m_mapRegionKha["Барвенково"] = "barvenkovo/";
    m_mapRegionKha["Богодухов"] = "bogodukhov/";
    m_mapRegionKha["Валки"] = "valki/";
    m_mapRegionKha["Великий Бурлук"] = "velikiy-burluk/";
    m_mapRegionKha["Волчанск"] = "volchansk/";
    m_mapRegionKha["Высокий"] = "vysokiy/";
    m_mapRegionKha["Дергачи"] = "dergachi/";
    m_mapRegionKha["Змиев"] = "zmiev/";
    m_mapRegionKha["Изюм"] = "izyum/";
    m_mapRegionKha["Комсомольское"] = "komsomolskoye/";
    m_mapRegionKha["Красноград"] = "krasnograd/";
    m_mapRegionKha["Купянск"] = "kupyansk/";
    m_mapRegionKha["Лозовая"] = "lozovaya/";
    m_mapRegionKha["Люботин"] = "lyubotin/";
    m_mapRegionKha["Мерефа"] = "merefa/";
    m_mapRegionKha["Новая Водолага"] = "novaya-vodolaga/";
    m_mapRegionKha["Первомайский"] = "pervomayskiy/";
    m_mapRegionKha["Солоницевка"] = "solonitsevka/";
    m_mapRegionKha["Харьков"] = "kharkov/";
    m_mapRegionKha["Чугуев"] = "chuguev/";
}
void CUrlBuilder::fill_region_khe()
{
    m_mapRegionKhe["Антоновка"] = "antonovka/";
    m_mapRegionKhe["Белозерка"] = "belozerka/";
    m_mapRegionKhe["Берислав"] = "berislav/";
    m_mapRegionKhe["Великая Александровка"] = "velikaya-aleksandrovka/";
    m_mapRegionKhe["Великая Лепетиха"] = "velikaya-lepetikha/";
    m_mapRegionKhe["Геническ"] = "genichesk/";
    m_mapRegionKhe["Голая Пристань"] = "golaya-pristan/";
    m_mapRegionKhe["Каланчак"] = "kalanchak/";
    m_mapRegionKhe["Камышаны"] = "kamyshany/";
    m_mapRegionKhe["Каховка"] = "kakhovka/";
    m_mapRegionKhe["Новая Каховка"] = "novaya-kakhovka/";
    m_mapRegionKhe["Новая Маячка"] = "novaya-mayachka/";
    m_mapRegionKhe["Новоалексеевка"] = "novoalekseyevka/";
    m_mapRegionKhe["Новотроицкое"] = "novotroitskoye/";
    m_mapRegionKhe["Пойма"] = "poyma/";
    m_mapRegionKhe["Скадовск"] = "skadovsk/";
    m_mapRegionKhe["Таврийск"] = "tavriysk/";
    m_mapRegionKhe["Херсон"] = "kherson/";

}
void CUrlBuilder::fill_region_khm()
{
    m_mapRegionKhm["Виньковцы"] = "vinkovtsy/";
    m_mapRegionKhm["Волочиск"] = "volochisk/";
    m_mapRegionKhm["Городок"] = "gorodok/";
    m_mapRegionKhm["Деражня"] = "derazhnya/";
    m_mapRegionKhm["Дунаевцы"] = "dunaevtsy/";
    m_mapRegionKhm["Изяслав"] = "izyaslav/";
    m_mapRegionKhm["Каменец-Подольский"] = "kamenets-podolskiy/";
    m_mapRegionKhm["Красилов"] = "krasilov/";
    m_mapRegionKhm["Летичев"] = "letichev/";
    m_mapRegionKhm["Нетешин"] = "neteshin/";
    m_mapRegionKhm["Полонное"] = "polonnoe/";
    m_mapRegionKhm["Понинка"] = "poninka/";
    m_mapRegionKhm["Славута"] = "slavuta/";
    m_mapRegionKhm["Староконстантинов"] = "starokonstantinov/";
    m_mapRegionKhm["Теофиполь"] = "teofipol/";
    m_mapRegionKhm["Хмельницкий"] = "khmelnitskiy/";
    m_mapRegionKhm["Шепетовка"] = "shepetovka/";

}
void CUrlBuilder::fill_region_chk()
{
    m_mapRegionChk["Ватутино"] = "vatutino/";
    m_mapRegionChk["Городище"] = "gorodishche/";
    m_mapRegionChk["Драбов"] = "drabov/";
    m_mapRegionChk["Жашков"] = "zhashkov/";
    m_mapRegionChk["Звенигородка"] = "zvenigorodka/";
    m_mapRegionChk["Золотоноша"] = "zolotonosha/";
    m_mapRegionChk["Каменка"] = "kamenka/";
    m_mapRegionChk["Канев"] = "kanev/";
    m_mapRegionChk["Корсунь-Шевченковский"] = "korsun-shevchenkovskiy/";
    m_mapRegionChk["Лысянка"] = "lysyanka/";
    m_mapRegionChk["Маньковка"] = "mankovka/";
    m_mapRegionChk["Монастырище"] = "monastyrishche/";
    m_mapRegionChk["Смела"] = "smela/";
    m_mapRegionChk["Тальное"] = "talnoe/";
    m_mapRegionChk["Умань"] = "uman/";
    m_mapRegionChk["Христиновка"] = "khristinovka/";
    m_mapRegionChk["Черкассы"] = "cherkassy/";
    m_mapRegionChk["Чернобай"] = "chernobay/";
    m_mapRegionChk["Чигирин"] = "chigirin/";
    m_mapRegionChk["Шпола"] = "shpola/";
}
void CUrlBuilder::fill_region_chn()
{
    m_mapRegionChn["Бахмач"] = "bakhmach/";
    m_mapRegionChn["Бобровица"] = "bobrovitsa/";
    m_mapRegionChn["Борзна"] = "borzna/";
    m_mapRegionChn["Городня"] = "gorodnya/";
    m_mapRegionChn["Десна"] = "desna/";
    m_mapRegionChn["Ичня"] = "ichnya/";
    m_mapRegionChn["Козелец"] = "kozelets/";
    m_mapRegionChn["Корюковка"] = "koryukovka/";
    m_mapRegionChn["Мена"] = "mena/";
    m_mapRegionChn["Нежин"] = "nezhin/";
    m_mapRegionChn["Новгород-Северский"] = "novgorod-severskiy/";
    m_mapRegionChn["Носовка"] = "nosovka/";
    m_mapRegionChn["Прилуки"] = "priluki/";
    m_mapRegionChn["Седнев"] = "sednev/";
    m_mapRegionChn["Семеновка"] = "semyenovka/";
    m_mapRegionChn["Чернигов"] = "chernigov/";
    m_mapRegionChn["Щорс"] = "schors/";

}
void CUrlBuilder::fill_region_chv()
{
    m_mapRegionChv["Берегомет"] = "beregomet/";
    m_mapRegionChv["Вашковцы"] = "vashkovtsy/";
    m_mapRegionChv["Вижница"] = "vizhnitsa/";
    m_mapRegionChv["Герца"] = "gertsa/";
    m_mapRegionChv["Глыбокая"] = "glybokaya/";
    m_mapRegionChv["Заставна"] = "zastavna/";
    m_mapRegionChv["Кельменцы"] = "kelmentsy/";
    m_mapRegionChv["Кицмань"] = "kitsman/";
    m_mapRegionChv["Красноильск"] = "krasnoilsk/";
    m_mapRegionChv["Новоднестровск"] = "novodnestrovsk/";
    m_mapRegionChv["Новоселица"] = "novoselitsa/";
    m_mapRegionChv["Путила"] = "putila/";
    m_mapRegionChv["Сокиряны"] = "sokiryany/";
    m_mapRegionChv["Сторожинец"] = "storozhinets/";
    m_mapRegionChv["Хотин"] = "khotin/";
    m_mapRegionChv["Черновцы"] = "chernovtsy/";
}
void CUrlBuilder::fill_all_this_shit()
{
    m_mapCityRegions["Львов||Галицкий"] = "search%5Bdistrict_id%5D=127";
    m_mapCityRegions["Львов||Железнодорожный"] = "search%5Bdistrict_id%5D=129";
    m_mapCityRegions["Львов||Лычаковский"] = "search%5Bdistrict_id%5D=131";
    m_mapCityRegions["Львов||Сиховский"] = "search%5Bdistrict_id%5D=133";
    m_mapCityRegions["Львов||Франковский"] = "search%5Bdistrict_id%5D=135";
    m_mapCityRegions["Львов||Шевченковский"] = "search%5Bdistrict_id%5D=137";
    m_mapCityRegions["Винница||Замостянский"] = "search%5Bdistrict_id%5D=147";
    m_mapCityRegions["Винница||Ленинский"] = "search%5Bdistrict_id%5D=149";
    m_mapCityRegions["Винница||Старогородской"] = "search%5Bdistrict_id%5D=151";
    m_mapCityRegions["Днепр||Амур-Нижнеднепровский"] = "search%5Bdistrict_id%5D=111";
    m_mapCityRegions["Днепр||Бабушкинский"] = "search%5Bdistrict_id%5D=113";
    m_mapCityRegions["Днепр||Жовтневый"] = "search%5Bdistrict_id%5D=115";
    m_mapCityRegions["Днепр||Индустриальный"] = "search%5Bdistrict_id%5D=117";
    m_mapCityRegions["Днепр||Кировский"] = "search%5Bdistrict_id%5D=119";
    m_mapCityRegions["Днепр||Красногвардейский"] = "search%5Bdistrict_id%5D=121";
    m_mapCityRegions["Днепр||Ленинский"] = "search%5Bdistrict_id%5D=123";
    m_mapCityRegions["Днепр||Самарский"] = "search%5Bdistrict_id%5D=125";
    m_mapCityRegions["Донецк||Будённовский"] = "search%5Bdistrict_id%5D=21";
    m_mapCityRegions["Донецк||Ворошиловский"] = "search%5Bdistrict_id%5D=23";
    m_mapCityRegions["Донецк||Калининский"] = "search%5Bdistrict_id%5D=25";
    m_mapCityRegions["Донецк||Киевский"] = "search%5Bdistrict_id%5D=27";
    m_mapCityRegions["Донецк||Кировский"] = "search%5Bdistrict_id%5D=29";
    m_mapCityRegions["Донецк||Куйбышевский"] = "search%5Bdistrict_id%5D=31";
    m_mapCityRegions["Донецк||Ленинский"] = "search%5Bdistrict_id%5D=33";
    m_mapCityRegions["Донецк||Петровский"] = "search%5Bdistrict_id%5D=35";
    m_mapCityRegions["Донецк||Пролетарский"] = "search%5Bdistrict_id%5D=37";
    m_mapCityRegions["Житомир||Аэропорт"] = "search%5Bdistrict_id%5D=153";
    m_mapCityRegions["Житомир||Богуния"] = "search%5Bdistrict_id%5D=61";
    m_mapCityRegions["Житомир||Бумажная фабрика"] = "search%5Bdistrict_id%5D=154";
    m_mapCityRegions["Житомир||Вокзал"] = "search%5Bdistrict_id%5D=156";
    m_mapCityRegions["Житомир||Гормолзавод"] = "search%5Bdistrict_id%5D=158";
    m_mapCityRegions["Житомир||Житний рынок"] = "search%5Bdistrict_id%5D=160";
    m_mapCityRegions["Житомир||Корбутовка"] = "search%5Bdistrict_id%5D=166";
    m_mapCityRegions["Житомир||Крошня"] = "search%5Bdistrict_id%5D=63";
    m_mapCityRegions["Житомир||Максютова"] = "search%5Bdistrict_id%5D=168";
    m_mapCityRegions["Житомир||Малеванка"] = "search%5Bdistrict_id%5D=65";
    m_mapCityRegions["Житомир||Маликова"] = "search%5Bdistrict_id%5D=170";
    m_mapCityRegions["Житомир||Марьяновка"] = "search%5Bdistrict_id%5D=172";
    m_mapCityRegions["Житомир||Музыкальная фабрика"] = "search%5Bdistrict_id%5D=174";
    m_mapCityRegions["Житомир||Подол"] = "search%5Bdistrict_id%5D=176";
    m_mapCityRegions["Житомир||Полевая"] = "search%5Bdistrict_id%5D=178";
    m_mapCityRegions["Житомир||Промавтоматика"] = "search%5Bdistrict_id%5D=180";
    m_mapCityRegions["Житомир||Путятинка"] = "search%5Bdistrict_id%5D=182";
    m_mapCityRegions["Житомир||Сенный рынок"] = "search%5Bdistrict_id%5D=184";
    m_mapCityRegions["Житомир||Смаковка"] = "search%5Bdistrict_id%5D=186";
    m_mapCityRegions["Житомир||Смолянка"] = "search%5Bdistrict_id%5D=188";
    m_mapCityRegions["Житомир||Химволокно"] = "search%5Bdistrict_id%5D=190";
    m_mapCityRegions["Житомир||Центр"] = "search%5Bdistrict_id%5D=194";
    m_mapCityRegions["Житомир||Чудновский"] = "search%5Bdistrict_id%5D=197";
    m_mapCityRegions["Житомир||Чулочная фабрика"] = "search%5Bdistrict_id%5D=196";
    m_mapCityRegions["Запорожье||Александровский"] = "search%5Bdistrict_id%5D=39";
    m_mapCityRegions["Запорожье||Вознесеновский"] = "search%5Bdistrict_id%5D=47";
    m_mapCityRegions["Запорожье||Днепровский"] = "search%5Bdistrict_id%5D=45";
    m_mapCityRegions["Запорожье||Заводский"] = "search%5Bdistrict_id%5D=41";
    m_mapCityRegions["Запорожье||Коммунарский"] = "search%5Bdistrict_id%5D=43";
    m_mapCityRegions["Запорожье||Хортицкий"] = "search%5Bdistrict_id%5D=49";
    m_mapCityRegions["Запорожье||Шевченковский"] = "search%5Bdistrict_id%5D=51";
    m_mapCityRegions["Киев||Голосеевский"] = "search%5Bdistrict_id%5D=1";
    m_mapCityRegions["Киев||Дарницкий"] = "search%5Bdistrict_id%5D=3";
    m_mapCityRegions["Киев||Деснянский"] = "search%5Bdistrict_id%5D=5";
    m_mapCityRegions["Киев||Днепровский"] = "search%5Bdistrict_id%5D=7";
    m_mapCityRegions["Киев||Оболонский"] = "search%5Bdistrict_id%5D=9";
    m_mapCityRegions["Киев||Печерский"] = "search%5Bdistrict_id%5D=11";
    m_mapCityRegions["Киев||Подольский"] = "search%5Bdistrict_id%5D=13";
    m_mapCityRegions["Киев||Святошинский"] = "search%5Bdistrict_id%5D=15";
    m_mapCityRegions["Киев||Соломенский"] = "search%5Bdistrict_id%5D=17";
    m_mapCityRegions["Киев||Шевченковский"] = "search%5Bdistrict_id%5D=19";
    m_mapCityRegions["Кропивницкий||Кировский район"] = "search%5Bdistrict_id%5D=107";
    m_mapCityRegions["Кропивницкий||Ленинский район"] = "search%5Bdistrict_id%5D=109";
    m_mapCityRegions["Кропивницкий||Ярмолинецкий"] = "search%5Bdistrict_id%5D=200";
    m_mapCityRegions["Луганск||Артёмовский"] = "search%5Bdistrict_id%5D=55";
    m_mapCityRegions["Луганск||Жовтневый"] = "search%5Bdistrict_id%5D=53";
    m_mapCityRegions["Луганск||Каменнобродский"] = "search%5Bdistrict_id%5D=59";
    m_mapCityRegions["Луганск||Ленинский"] = "search%5Bdistrict_id%5D=57";
    m_mapCityRegions["Николаев||Ингульский"] = "search%5Bdistrict_id%5D=143";
    m_mapCityRegions["Николаев||Заводский"] = "search%5Bdistrict_id%5D=139";
    m_mapCityRegions["Николаев||Корабельный"] = "search%5Bdistrict_id%5D=141";
    m_mapCityRegions["Николаев||Центральный"] = "search%5Bdistrict_id%5D=145";
    m_mapCityRegions["Одесса||Киевский"] = "search%5Bdistrict_id%5D=85";
    m_mapCityRegions["Одесса||Коминтерновский"] = "search%5Bdistrict_id%5D=199";
    m_mapCityRegions["Одесса||Малиновский"] = "search%5Bdistrict_id%5D=87";
    m_mapCityRegions["Одесса||Приморский"] = "search%5Bdistrict_id%5D=89";
    m_mapCityRegions["Одесса||Суворовский"] = "search%5Bdistrict_id%5D=91";
    m_mapCityRegions["Харьков||Индустриальный "] = "search%5Bdistrict_id%5D=79";
    m_mapCityRegions["Харьков||Киевский"] = "search%5Bdistrict_id%5D=69";
    m_mapCityRegions["Харьков||Коминтерновский"] = "search%5Bdistrict_id%5D=71";
    m_mapCityRegions["Харьков||Московский"] = "search%5Bdistrict_id%5D=75";
    m_mapCityRegions["Харьков||Октябрьский"] = "search%5Bdistrict_id%5D=77";
    m_mapCityRegions["Харьков||Фрунзенский"] = "search%5Bdistrict_id%5D=81";
    m_mapCityRegions["Харьков||Холодногорский"] = "search%5Bdistrict_id%5D=73";
    m_mapCityRegions["Харьков||Червонозаводской"] = "search%5Bdistrict_id%5D=83";
    m_mapCityRegions["Харьков||search%5Bdistrict_id%5D=83"] = "search%5Bdistrict_id%5D=67";

}
