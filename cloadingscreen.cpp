#include "cloadingscreen.h"
#include "ui_cloadingscreen.h"

CLoadingScreen::CLoadingScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CLoadingScreen)
{
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    QTimer* ptimer = new QTimer(this);
    connect(ptimer, SIGNAL(timeout()), SLOT(change_val()));
    ptimer->start(100);
    if(ui->progressBar->value() == 100)
    {
        ptimer->stop();
    delete ptimer;
    }

}

void CLoadingScreen::change_val()
{
//    while(ui->progressBar->value() != 100)
//    {

//        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        ui->progressBar->setValue(ui->progressBar->value() + 1);
    //}

}

int CLoadingScreen::is_hundred_per()
{
    return  ui->progressBar->value();
}
CLoadingScreen::~CLoadingScreen()
{
    delete ui;
}
