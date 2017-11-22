#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QSqlTableModel>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //
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

public slots:
    void exit();
};

#endif // MAINWINDOW_H
