#ifndef CADHOME
#define CADHOME
#include <QString>
class CAdHome
{
private:

    QString m_sImg;
    QString m_sTitle;
	QString m_sSmalDescr;
	QString m_sGeoPos;
	QString m_sPublicated;
	QString m_sUrl;
	QString m_sPrice;

public:

	void setImg(const QString& aImg) { m_sImg = aImg; }
	void setTitle(const QString& aTitle) { m_sTitle = aTitle; }
	void setSmalDescr(const QString & aSDecor) { m_sSmalDescr = aSDecor; }
	void setGeoPos(const QString & aGPos) { m_sGeoPos = aGPos; }
	void setPublicated(const QString &aPublicated) { m_sPublicated = aPublicated; }
	void setUrl(const QString &aUrl) { m_sUrl = aUrl; }
	void setPrice(const QString &aPrice) { m_sPrice = aPrice; }

	QString& getImg() { return m_sImg; }
	QString& getTitle() { return m_sTitle; }
	QString& getSmalDescr() { return m_sSmalDescr; }
	QString& getGeoPos() { return m_sGeoPos; }
	QString& getPublicated() { return m_sPublicated; }
	QString& getUrl() { return m_sUrl; }
	QString& getPrice() { return m_sPrice;  }
    QString to_string(){return m_sTitle + " " + m_sPrice +  " " + m_sSmalDescr + " " + m_sGeoPos + " " + m_sPublicated;}
	CAdHome(const QString& aImg, const QString& aTitle, const QString &aPrice,
						const QString & aSDecor, const QString & aGPos, 
						const QString &aPublicated, const QString &aUrl) 
						{
							m_sImg = aImg;
							m_sTitle = aTitle;
							m_sSmalDescr = aSDecor;
							m_sGeoPos = aGPos;
							m_sPublicated = aPublicated;
							m_sUrl = aUrl;
							m_sPrice = aPrice;

						}
	CAdHome() {}


};
#endif
