#ifndef QLABELSTUDY_H
#define QLABELSTUDY_H

#include <QWidget>
#include "customwidget.h"

namespace Ui {
class QLabelStudy;
}

class QLabelStudy : public CustomWidget
{
    Q_OBJECT

public:
    explicit QLabelStudy(QWidget *parent = 0);
    ~QLabelStudy();

private:
    Ui::QLabelStudy *ui;
public:
    void initUI();
    void refreshData();
};

#endif // QLABELSTUDY_H
