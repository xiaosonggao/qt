#include "addstuw.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>
#include <QDialog>

addStuW::addStuW()
    :QDialog(0)
{



    name = new QLabel(tr("姓名"));
    nameBox = new QLineEdit;
    nameBox->clear();
    ID = new QLabel(tr("学号"));
    IDBox = new QLineEdit;
    IDBox->clear();
    Dormitory = new QLabel(tr("宿舍"));
    DormitoryBox = new QLineEdit;
    DormitoryBox->clear();
    sureBtn = new QPushButton(tr("确认"));
    sureBtn->setDefault(true);
    sureBtn->setEnabled(false);
    quitBtn = new QPushButton(tr("取消"));


    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addWidget(name);
    nameLayout->addWidget(nameBox);
    QHBoxLayout *IDLayout = new QHBoxLayout;
    IDLayout->addWidget(ID);
    IDLayout->addWidget(IDBox);
    QHBoxLayout *DormLayout = new QHBoxLayout;
    DormLayout->addWidget(Dormitory);
    DormLayout->addWidget(DormitoryBox);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addSpacing(10);
    btnLayout->addWidget(sureBtn);
    btnLayout->addWidget(quitBtn);
    btnLayout->addSpacing(10);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(50);
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(IDLayout);
    mainLayout->addLayout(DormLayout);
    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);
    setFixedSize(sizeHint().width(), sizeHint().height());
//*************layout set ends**************//

    connect(quitBtn,SIGNAL(clicked()),
            this, SLOT(close()));
    connect(sureBtn,SIGNAL(clicked()),
            this,SLOT(addClicked()));
    connect(this, SIGNAL(info_conf()),
            this, SLOT(enableSureBtn()));
    connect(this, SIGNAL(info_conf_no()),
            this, SLOT(disableSureBtn()));

//* box changed and  check box   *//
    connect(nameBox,SIGNAL(textChanged(QString)),
            this,SLOT(checkInfo()));
    connect(IDBox,SIGNAL(textChanged(QString)),
            this,SLOT(checkInfo()));
    connect(DormitoryBox ,SIGNAL(textChanged(QString)),
            this,SLOT(checkInfo()));


}
addStuW:: ~addStuW(){}

void addStuW:: addClicked(){
    QString name = nameBox->text();
    int id = IDBox->text().toInt();
    QString dorm = DormitoryBox->text();


    //确认添加之后怎么处理数据!!!!!!!!!!!!!!

    this->close();
}

void addStuW::enableSureBtn(){
    sureBtn->setEnabled(true);
}
void addStuW::disableSureBtn(){
    sureBtn->setDisabled(true);
}

void addStuW::checkInfo(){
    QString s1 = nameBox->text();
    QString s2 = IDBox->text();
    QString s3 = DormitoryBox->text();

    if((!s1.isEmpty())&&(!s2.isEmpty())&&(!s3.isEmpty()))  emit info_conf();
    else emit info_conf_no();
}
void addStuW::showWin(){
    nameBox->clear();
    IDBox->clear();
    DormitoryBox->clear();
    sureBtn->setDisabled(true);
    show();
}
