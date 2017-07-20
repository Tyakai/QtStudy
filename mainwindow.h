#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "enumdefine.h"
#include "customwidget.h"
#include "QLabelStudy.h"

class QWidget;
class CustomWidget;
class QLabelStudy;
class QTreeWidget;
class QTreeWidgetItem;
enum enum_ItemsName;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:

public slots:
    void showClickedItem(QTreeWidgetItem *curClickItem,int colum);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CustomWidget *m_curWidget;
    int m_curWidgetID;
private:
    void initUI();
    void initTreeWidget();
    void selectWidget(QTreeWidgetItem *curClickItem,int colum);
    QTreeWidgetItem* getTreeItem(enum_ItemsName itemName);
    void showItem(enum_ItemsName);
    void setConnect();
};

#endif // MAINWINDOW_H
