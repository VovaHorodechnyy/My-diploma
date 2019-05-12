#ifndef CLOADINGSCREEN_H
#define CLOADINGSCREEN_H

#include <QWidget>
#include <QTimer>


namespace Ui {
class CLoadingScreen;
}

class CLoadingScreen : public QWidget
{
    Q_OBJECT

public:
    explicit CLoadingScreen(QWidget *parent = nullptr);
    ~CLoadingScreen();
    int is_hundred_per();
private:
    Ui::CLoadingScreen *ui;

public slots:
void change_val();

};

#endif // CLOADINGSCREEN_H
