#ifndef CFAVORITEAD_H
#define CFAVORITEAD_H
#include <QString>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDebug>

#define PATH_FILE  "ads.xml"
class CFavoriteAd
{
   public:
    CFavoriteAd(const QString& aTitle , const QString& aUrl , const QString& aUrl_img , const QString& aGPos)
    {
        m_sTitle = aTitle;
        m_sUrl = aUrl;
        m_sUrlImg = aUrl_img;
        m_sGeoPos = aGPos;
    }
    CFavoriteAd(){}
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
    static bool is_exist(QList<CFavoriteAd>* aptrList, const QString&asText)
    {
        for(auto it = aptrList->begin() , end = aptrList->end();it != end; ++it)
        {
            if(it->get_title() == asText)
                return  true;
        }
        return false;
    }
   private:
    QString m_sTitle,m_sUrl,m_sUrlImg,m_sGeoPos;
};

static QList<CFavoriteAd>* read_xml()
{
    QFile file(PATH_FILE);
    QList<CFavoriteAd> *list = new QList<CFavoriteAd>;
    if(file.open(QIODevice::ReadOnly))
    {
        int count = 0;
        QXmlStreamReader xmlReader(&file);
        xmlReader.readNext();
        while (!(xmlReader.atEnd() ))
        {
            xmlReader.readNext();
            count = 0;
            CFavoriteAd ad;
            qDebug()<<"before";
            while(!xmlReader.atEnd())
            {

                if(count == 4)
                    break;
                qDebug()<<"after";

                if (xmlReader.name() == "title")
                {
                    xmlReader.readNext();
                    ad.set_title(xmlReader.text().toString());
                    ++count;
                    xmlReader.readNext();
                }
                if (xmlReader.name() == "url")
                {
                    xmlReader.readNext();
                    ad.set_url(xmlReader.text().toString());
                    ++count;
                    xmlReader.readNext();
                }
                if (xmlReader.name() == "url_img")
                {
                    xmlReader.readNext();
                    ad.set_url_img(xmlReader.text().toString());
                    ++count;
                    xmlReader.readNext();
                }
                if (xmlReader.name() == "g_pos")
                {
                    xmlReader.readNext();
                    ad.set_g_pos(xmlReader.text().toString());
                    ++count;
                    xmlReader.readNext();
                }
                 xmlReader.readNext();
            }
            list->push_back(ad);
            xmlReader.readNext();
        }
    }
    list->pop_back();
    if(list->size())
        return list;
    return nullptr;

}
static void write_xml(QList<CFavoriteAd>&ads)
{
    QFile file(PATH_FILE);
    if(file.open(QIODevice::WriteOnly))
    {
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.writeStartElement("CFavoriteAds");
        for(CFavoriteAd ad : ads)
        {
            xmlWriter.writeStartElement("CFavoriteAd");

            xmlWriter.writeStartElement("title");
            xmlWriter.writeCharacters(ad.get_title());
            xmlWriter.writeEndElement();

            xmlWriter.writeStartElement("url");
            xmlWriter.writeCharacters(ad.get_url());
            xmlWriter.writeEndElement();

            xmlWriter.writeStartElement("url_img");
            xmlWriter.writeCharacters(ad.get_url_img());
            xmlWriter.writeEndElement();

            xmlWriter.writeStartElement("g_pos");
            xmlWriter.writeCharacters(ad.get_g_pos());
            xmlWriter.writeEndElement();

            xmlWriter.writeEndElement();

        }
        xmlWriter.writeEndElement();
        file.close();

    }

}
#endif // CFAVORITEAD_H
