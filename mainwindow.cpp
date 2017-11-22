#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include "addstuw.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "initdb.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*****database***/
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","NEW_DB");
    db.setDatabaseName("stuinformation.bd");
    db.open();
    initdb(db);
    ui->setupUi(this);
    stuLabel = new QLabel(tr("学生列表"));
    subLabel = new QLabel(tr("课程列表"));
    stuList = new QTableView;
    subList = new QTableView;

    addStuBtn = new QPushButton(tr("添加"));
    modifyBtn = new QPushButton(tr("修改"));
    deleteBtn = new QPushButton(tr("删除"));
    quitBtn = new QPushButton(tr("退出"));

    /* search widget*/
    N_ID = new QLabel(tr("姓名/学号"));
    N_IDBox = new QLineEdit;
    N_IDBtn = new QPushButton(tr("搜索"));
    Dorm = new QLabel(tr("宿舍号  "));
    DormBox = new QLineEdit;
    DormBtn = new QPushButton(tr("搜索"));
    //left bottom btn
    QHBoxLayout *LBBtnLayout = new QHBoxLayout;
    LBBtnLayout->addWidget(addStuBtn);
    LBBtnLayout->addWidget(modifyBtn);
    LBBtnLayout->addWidget(deleteBtn);
    LBBtnLayout->setSpacing(deleteBtn->width()/10);
    //search layout
    QGridLayout *searchLayout = new QGridLayout;
    searchLayout->addWidget(N_ID,0,0,1,1,Qt::AlignCenter|Qt::AlignVCenter);
    searchLayout->addWidget(N_IDBox,0,1,1,3);
    searchLayout->addWidget(N_IDBtn,0,4,1,1);
    searchLayout->addWidget(Dorm,1,0,1,1,Qt::AlignCenter|Qt::AlignVCenter);
    searchLayout->addWidget(DormBox,1,1,1,3);
    searchLayout->addWidget(DormBtn,1,4,1,1);
    searchLayout->setRowMinimumHeight(0, 10);

    //学生信息
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(stuLabel);
    leftLayout->addWidget(stuList);
    leftLayout->addLayout(LBBtnLayout);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(subLabel);
    rightLayout->addWidget(subList);
    rightLayout->addLayout(searchLayout);
    //quit
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(quitBtn);
    QHBoxLayout *upLayout = new QHBoxLayout;
    upLayout->addLayout(leftLayout);
    upLayout->addLayout(rightLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(upLayout);
    mainLayout->addLayout(bottomLayout);
    QWidget *mainWidget = new QWidget;
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
    setWindowTitle(tr("学生信息管理系统"));
    setMinimumSize(850,600);
    /******************main_window design ends*****************/

    /*学生信息列表显示*/
    static QSqlQueryModel *stu_model = new QSqlQueryModel(stuList);
    stu_model->setQuery(QString("select * from table;"));
    stu_model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    stu_model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    stu_model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    stuList->setModel(stu_model);
    db.close();
    stuList->setShowGrid(false);
    stuList->resizeColumnsToContents();
    stuList->verticalHeader();




 //*********************signals and slots************//
    connect(quitBtn, SIGNAL(clicked()),
            this, SLOT(exit()));
    connect(addStuBtn, SIGNAL(clicked()),
            new addStuW, SLOT(showWin()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::exit(){
    this->~MainWindow();
}
