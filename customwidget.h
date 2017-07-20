#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

namespace Ui {
class CustomWidget;
}

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomWidget(QWidget *parent = 0);
    ~CustomWidget();

public:
    virtual void refreshData()=0;
    virtual void initUI()=0;
};
#endif // CUSTOMWIDGET_H
