#include "qlabelstudy.h"
#include "ui_qlabelstudy.h"

QLabelStudy::QLabelStudy(QWidget *parent) :
    CustomWidget(parent),
    ui(new Ui::QLabelStudy)
{
    ui->setupUi(this);
}

QLabelStudy::~QLabelStudy()
{
    delete ui;
}
void QLabelStudy::initUI()
{
    ui->alignLeft->setAlignment(Qt::AlignLeft);
    ui->alignRight->setAlignment(Qt::AlignRight);
    ui->alignHCenter->setAlignment(Qt::AlignHCenter);
    ui->alignTop->setAlignment(Qt::AlignTop);
    ui->alignButtom->setAlignment(Qt::AlignVCenter);
    ui->alignButtom->setAlignment(Qt::AlignJustify);
}
void QLabelStudy::refreshData()
{

}
