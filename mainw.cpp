#include <mainw.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include "addstuw.h"

mainw::mainw ()
   : QMainWindow (0)
{
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
    QWidget *mWidget = new QWidget;
    mWidget->setLayout(mainLayout);
    setCentralWidget(mWidget);
    setWindowTitle(tr("学生信息管理系统"));
    setMinimumSize(850,600);



    /******************main_window design ends*****************/

    /*学生信息列表显示*/
    //create the data model
    QSqlQueryModel *stu_model = new QSqlQueryModel;
    //stu_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    stu_model->setQuery("SELECT * FROM student");

    stu_model->setHeaderData(0,Qt::Horizontal, tr("学号"));
    stu_model->setHeaderData(1,Qt::Horizontal, tr("姓名"));
    stu_model->setHeaderData(2,Qt::Horizontal, tr("宿舍号"));
    //stu_model->setHeaderData(stu_model->fieldIndex("name"),Qt::Horizontal, tr("学分"));
   // stu_model->select();

    stuList->setModel(stu_model);
    stuList->setSelectionBehavior(QAbstractItemView::SelectRows);


 //*********************signals and slots************//
    connect(quitBtn, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(addStuBtn, SIGNAL(clicked()),
            new addStuW, SLOT(showWin()));
}
mainw::~mainw(){}

