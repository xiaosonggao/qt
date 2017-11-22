#ifndef MAINW_H
#define MAINW_H

#include <QWidget>
#include <QLabel>
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QMainWindow>

class QLabel;
class QLineEdit;

class mainw :public QMainWindow {
    Q_OBJECT
public:
    mainw();
    ~mainw();
    //QSqlTableModel *student_model;
private :
    QLabel *stuLabel;
    QLabel *subLabel;
    QTableView *stuList;
    QTableView *subList;
    QPushButton *quitBtn;
    QPushButton *addStuBtn;
    QPushButton *modifyBtn;
    QPushButton *deleteBtn;
    QLineEdit *lineEdit1;

    //查询
    QLabel *N_ID;
    QLabel *Dorm;
    QLineEdit *N_IDBox;
    QLineEdit *DormBox;
    QPushButton *N_IDBtn;
    QPushButton *DormBtn;


};

#endif // MAINW_H
