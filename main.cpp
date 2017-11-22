#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include "mainw.h"
#include "addstuw.h"

#include <QtPlugin>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *mywin = new MainWindow(0);
    mywin->show();
    return app.exec();
}
