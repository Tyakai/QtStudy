#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_curWidget=NULL;
    m_curWidgetID=-1;
    initUI();
    initTreeWidget();
    setConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initUI()
{
    ui->main_treeWidget->setHeaderHidden(true);
}
void MainWindow::initTreeWidget()
{
    ui->main_treeWidget->clear();
    QTreeWidgetItem *firstLevelItem=new QTreeWidgetItem(QStringList()<<tr("QWidgetStudy"));
    firstLevelItem->setToolTip(0,tr("QWidgetStudy"));
    firstLevelItem->setData(0,Qt::UserRole,(int)emQWidgetStudy);
    ui->main_treeWidget->addTopLevelItem(firstLevelItem);
    QTreeWidgetItem *secondLevelITem=new QTreeWidgetItem(QStringList()<<tr("QLabelStudy"));
    secondLevelITem->setToolTip(0,tr("QLabelStudy"));
    secondLevelITem->setData(0,Qt::UserRole,(int)emQLabelStudy);
    firstLevelItem->addChild(secondLevelITem);
}

void MainWindow::setConnect()
{
    connect(ui->main_treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),
         this,SLOT(showClickedItem(QTreeWidgetItem*,int)));
}

void MainWindow::selectWidget(QTreeWidgetItem *curClickItem,int colum)
{
    return;
}

void MainWindow::showClickedItem(QTreeWidgetItem *curClickItem,int colum)
{
    if(!curClickItem&&colum!=0)
        return;
    bool isInt=false;
    enum_ItemsName itemName=(enum_ItemsName)curClickItem->data(0,Qt::UserRole).toInt(&isInt);
    if(!isInt)
        return;

    switch (itemName)
    {
    case emQWidgetStudy:
    {
        QTreeWidgetItem *item=getTreeItem(itemName);
        item->setExpanded(!item->isExpanded());
        return;
    }
    default:
        showItem(itemName);
    }
}
QTreeWidgetItem* MainWindow::getTreeItem(enum_ItemsName itemName)
{
    QTreeWidgetItemIterator iterator(ui->main_treeWidget);
    while (*iterator) {
        QTreeWidgetItem *item=*iterator;
        if(item)
        {
            if(item->data(0,Qt::UserRole)==itemName)
                return item;
        }
        ++iterator;
    }
    return NULL;
}
void MainWindow::showItem(enum_ItemsName itemName)
{
    if(itemName==m_curWidgetID)//如果点击的是当前显示的widget
    {
        m_curWidget->refreshData();
        m_curWidget->show();
        return;
    }
    if(m_curWidget)//如果m_curWidget存在，则要析构掉
    {
        delete m_curWidget;
        m_curWidget=NULL;
    }
    switch (itemName) {
    case emQLabelStudy:
        m_curWidget=new QLabelStudy;
        break;
    default:
        break;
    }
    ui->toAddwidgetLayout->addWidget(m_curWidget);
    m_curWidget->refreshData();
    m_curWidget->setVisible(true);
    m_curWidgetID=itemName;
}
