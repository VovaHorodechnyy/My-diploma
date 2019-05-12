#ifndef CPARSER_H
#define CPARSER_H
#include "my_trim.h"
#include <string>
#include <QString>
#include <algorithm>
#include <vector>
#include "kp_tree.h"
#include "parse.h"
#include "cadhome.h"
#include "cbigad.h"



namespace htmlcxx = htmlcxx2;
class CParser
{


    public:
        static  CAdHome parse(const QString & html)
        {
            htmlcxx::HTML::ParserDom m_objParser;
            kp::tree<htmlcxx::HTML::Node> dom = m_objParser.parseTree(html.toStdString());
            CAdHome res;

            // a href == class  thumb vtop inlblk rel tdnone linkWithHash scale4 detailsLink
            kp::tree<htmlcxx::HTML::Node>::iterator it = dom.begin();
            kp::tree<htmlcxx::HTML::Node>::iterator end = dom.end();

            for (; it != end; ++it)
            {

                if (it->tagName() == "img")
                {
                    it->parseAttributes();

                    auto vec_values = it->attributeValues();
                    if (vec_values.size() >= 2)
                        res.setImg(vec_values[1].c_str());

                }
                if (it->tagName() == "h3")
                {
                    it+=5;
                    it->parseAttributes();
                    //parse it->text
                    std::string tmp = it->text();
                    my_trim(tmp);
                    res.setTitle(tmp.c_str());
                    it -= 3;
                    it->parseAttributes();
                    auto vec_values = it->attributeValues();
                    if (vec_values.size() >= 1)
                        res.setUrl(vec_values[0].c_str());
                    it += 2;
                }
                if (it->tagName() == "i")
                {
                    it->parseAttributes();
                    auto vec_values = it->attributeValues();

                    if (std::find(vec_values.begin(), vec_values.end(), "clock") != vec_values.end())
                    {
                        ++it;
                        //parse it->text
                        std::string tmp = it->text();
                        my_trim(tmp);
                        res.setPublicated(tmp.c_str());
                    }
                    if (std::find(vec_values.begin(), vec_values.end(), "location-filled") != vec_values.end())
                    {
                        ++it;
                        //parse it->text
                        std::string tmp = it->text();
                        my_trim(tmp);
                        res.setGeoPos(tmp.c_str());
                    }
                }
                if (it->tagName() == "p")
                {
                    //color-9 lheight16 margintop5
                    it->parseAttributes();
                    auto vec_values = it->attributeValues();
                    if (std::find(vec_values.begin(), vec_values.end(), "color-9 lheight16 margintop5") != vec_values.end())
                    {
                        ++++++it;
                        //parse it
                        std::string tmp = it->text();
                        my_trim(tmp);
                        res.setSmalDescr(tmp.c_str());
                    }


                }
                if(it->tagName() == "p")
                {
                    it->parseAttributes();
                    auto vec_values = it->attributeValues();
                    if (std::find(vec_values.begin(), vec_values.end(), "price") != vec_values.end())
                    {
                        ++++++it;
                        //parse it
                        std::string tmp = it->text();
                        my_trim(tmp);
                        res.setPrice(tmp.c_str());
                    }
                }

                if (it->tagName() == "a")
                {
                    it->parseAttributes();
                    auto vec_values = it->attributeValues();
                    if (std::find(vec_values.begin(), vec_values.end(), "thumb vtop inlblk rel tdnone linkWithHash scale4 detailsLink") != vec_values.end())
                    {

                        if (vec_values.size() >= 2)
                            res.setUrl(vec_values[1].c_str());
                    }
                }
            }
            return res;
        }
        static CBigAd parse_bigad(QString & html)
        {
            CBigAd a ;
            std::size_t pos_tbl = html.indexOf("<table class=\"details fixed marginbott20 margintop5 full\" cellpadding=\"0\" cellspacing=\"0\">");
            std::size_t pos_end_tbl = html.indexOf("</div",pos_tbl);
            QString table = html.mid(pos_tbl , pos_end_tbl - pos_tbl);

            htmlcxx::HTML::ParserDom m_objParser;
            kp::tree<htmlcxx::HTML::Node> dom = m_objParser.parseTree(html.toStdString());


            // a href == class  thumb vtop inlblk rel tdnone linkWithHash scale4 detailsLink
            kp::tree<htmlcxx::HTML::Node>::iterator it = dom.begin();
            kp::tree<htmlcxx::HTML::Node>::iterator end = dom.end();

            for (; it != end; ++it)
            {
                it -> parseAttributes();
                auto vec_values = it -> attributeValues();
                if(std::find(vec_values.begin(),vec_values.end(),"tcenter img-item") != vec_values.end())
                {
                    it += 4;
                    it -> parseAttributes();
                    auto vec_img = it -> attributeValues();
                    if(vec_img.size())
                        a.get_vec().push_back(vec_img[0].c_str());

                }

                if(it -> tagName() == "div")
                {
                    it -> parseAttributes();

                    auto vec_values = it -> attributeValues();

                    if(std::find(vec_values.begin(),vec_values.end(),"tcenter img-item") != vec_values.end())
                    {
                        it += 4;
                        it -> parseAttributes();
                        auto vec_img = it -> attributeValues();
                        if(vec_img.size())
                            a.get_vec().push_back(vec_img[0].c_str());

                    }

                    if(std::find(vec_values.begin(),vec_values.end(),"textContent") != vec_values.end())
                    {
                        std::string trim = "";
                        ++it;
                        while(it -> tagName() != "div" &&  it -> tagName() != "span")
                        {
                            if(it -> text() == "<br />")
                            {
                                 ++it;
                                continue;
                            }

                            trim += it->text();
                            ++it;

                        }
                        my_trim(trim);
                        a.set_descr(trim.c_str());

                    }



                    if(std::find(vec_values.begin(),vec_values.end(),"offer-user__details") != vec_values.end())
                    {
                        it += 5;
                        std::string trim =it->text();
                        my_trim(trim);
                        a.set_ad_author(trim.c_str());
                    }
                    if(std::find(vec_values.begin(),vec_values.end(),"offer-sidebar__box--business-info-header") != vec_values.end())
                    {
                        it += 10;

                        std::string trim = it->text();
                        my_trim(trim);
                        a.set_ad_author(trim.c_str());
                    }
                    if(std::find(vec_values.begin(),vec_values.end(),"price-label") != vec_values.end())
                    {
                        it += 3;
                        std::string trim =it->text();
                        my_trim(trim);
                        a.set_price(trim.c_str());
                    }

                }
                if (it -> tagName() == "img")
                {
                    it -> parseAttributes();

                    auto vec_values = it -> attributeValues();
                    if(std::find(vec_values.begin(),vec_values.end(),"vtop bigImage {nr:1}") != vec_values.end())
                    {
                        a.set_ttl_img(vec_values.at(0).c_str());
                    }
                }
                if(it -> tagName() == "h1")
                {
                    ++it;
                    std::string trim =it->text();
                    my_trim(trim);
                    a.set_ttl(trim.c_str());
                }
                if(it -> tagName() == "em")
                {
                    ++it;
                    std::string trim =it->text();
                    my_trim(trim);
                    //problems
                    QString mtrim (trim.c_str()) ;
                    if(mtrim.contains("в"))
                        a.set_publ(trim.c_str());
                    else
                        a.set_publ("");
                    it += 2;
                    trim = it->text();
                    my_trim(trim);
                    mtrim = trim.c_str();
                    if(mtrim.contains("Номер объявления:"))
                        a.set_num(trim.c_str());
                    else
                        a.set_num("");

                }
                if(it -> tagName() == "a")
                {
                    it -> parseAttributes();
                    auto vec_values = it -> attributeValues();
                    if( std::find(vec_values.begin(),vec_values.end(),"showMap") != vec_values.end())
                    {
                        it -= 2;
                        std::string trim =it->text();
                        my_trim(trim);
                        a.set_geo_pos(trim.c_str());
                        it += 2;
                    }
                }
//                if(it -> tagName() == "strong")
//                {
//                    it -> parseAttributes();
//                    auto vec_values = it -> attributeValues();
//                    if( std::find(vec_values.begin(),vec_values.end(),"xxxx-large arranged") != vec_values.end())
//                    {
//                        ++it;
//                        std::string trim =it->text();
//                        my_trim(trim);
//                        a.set_price(trim.c_str());

//                    }

//                }
            }

            // table
            dom = m_objParser.parseTree(table.toStdString());
            it = dom.begin();
            end = dom.end();
            for (; it != end; ++it)
            {
                if(it.node == nullptr || it.node == NULL)
                    break;
                if (it -> text() == "Выберите рубрику")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;

                            tmp = tmp + " " + it->text() + " ";
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_hdng(trim.c_str());

                }
                if (it -> text() == "Страна")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_country(trim.c_str());

                }
                if (it -> text() == "Минимальное количество ночей")
                {
                    it += 5;

                    //trim

                    std::string trim = it->text();
                    my_trim(trim);
                    a.set_cnt_nights(trim.c_str());
                }

                if (it -> text() == "Возможна сдача почасовой")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_s_hourly(trim.c_str());
                }
                if (it -> text() == "Тип дома")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_type_h(trim.c_str());
                }if (it -> text() == "Тип объекта")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_type_o(trim.c_str());
                }
                if (it -> text() == "Общая площадь")
                {
                    it += 5;

                    //trim

                    std::string trim = it->text();
                    my_trim(trim);
                    a.set_total_area(trim.c_str());
                }
                if (it -> text() == "Название ЖК")
                {
                    it += 5;

                    //trim

                    std::string trim = it->text();
                    my_trim(trim);
                    a.set_lcd_name(trim.c_str());
                }
                if (it -> text() == "Этаж")
                {
                    it += 5;

                    std::string trim = it->text();
                    my_trim(trim);
                    a.set_floor(trim.c_str());
                }
                if (it -> text() == "Этажность")
                {
                    it += 5;
                    std::string trim = it->text();
                    my_trim(trim);


                    a.set_floors(trim.c_str());
                }if (it -> text() == "Количество комнат")
                {
                    it += 5;

                    //trim
                    std::string trim = it->text();
                    my_trim(trim);

                    a.set_rooms(trim.c_str());
                }if (it -> text() == "Количество спальных мест")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_count_bed(trim.c_str());
                }if (it -> text() == "Питание")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_nutrition(trim.c_str());
                }if (it -> text() == "Санузел")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_bathroom(trim.c_str());
                }if (it -> text() == "Ремонт")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_repairs(trim.c_str());
                }if (it -> text() == "Бытовая техника")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_appliances(trim.c_str());
                }if (it -> text() == "Мультимедиа")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_media(trim.c_str());
                }if (it -> text() == "Комфорт")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_comfort(trim.c_str());
                }if (it -> text() == "Инфраструктура (до 500 метров)")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_infrst(trim.c_str());
                }if (it -> text() == "Ландшафт (до 1 км.)")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_landscape(trim.c_str());
                }if (it -> text() == "Готов сотрудничать с риэлторами")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_coop_real(trim.c_str());
                }if (it -> text() == "Кредитование")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);

                    a.set_crediting(trim.c_str());
                }if (it -> text() == "Коммуникации")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_comunication(trim.c_str());
                }if (it -> text() == "Отопление")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);

                    a.set_htng(trim.c_str());
                }if (it -> text() == "Планировка")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_layout(trim.c_str());
                }if (it -> text() == "Площадь кухни")
                {
                    it += 5;
                    std::string trim = it->text();
                    my_trim(trim);
                    a.set_kitchen_area(trim.c_str());
                }if (it -> text() == "Год постройки / сдачи")
                {
                    it += 4;

                    //trim

                    std::string tmp = " ";
                    while(it -> tagName() != "td" && it != end)
                    {
                        if(it -> tagName() == "a")
                        {
                            it += 1;
                            tmp = tmp + "|" + it->text();
                        }

                        ++it;
                    }
                    std::string trim = tmp;
                    my_trim(trim);
                    a.set_year_c_d(trim.c_str());
                }




        //        if (it -> text() == "Ремонт")
        //        {
        //            it += 7;
        //            //trim

        //            a.set_repairs(it->text().c_str());
        //        }





            }
            std::size_t pos_em = html.indexOf("<em>");
            if(a.get_publ() == "")
            {

                std::size_t pos_publ = html.indexOf("в ",pos_em);
                std::size_t pos_publ_end = html.indexOf("<small>",pos_em);
                QString publ = html.mid(pos_publ,pos_publ_end - pos_publ);
                std::string trim = publ.toStdString();
                my_trim(trim);
                a.set_publ(trim.c_str());
            }
            if(a.get_numb() == "")
            {

                std::size_t pos_num = html.indexOf("Номер объявления:",pos_em);
                std::size_t pos_num_end = html.indexOf("</small>",pos_em);
                QString publ = html.mid(pos_num,pos_num_end - pos_num);
                std::string trim = publ.toStdString();
                my_trim(trim);
                a.set_num(trim.c_str());
            }


            return a;
        }
};



#endif // CPARSER_H
