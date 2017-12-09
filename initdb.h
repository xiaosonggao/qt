#ifndef INITDB_H
#define INITDB_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <qdebug.h>
#include <QtSql>

void addStu(QSqlQuery &q){


}

QSqlError initdb(QSqlDatabase db){
    if(!db.open()){
        return db.lastError();
    }
    qDebug()<<QSqlDatabase::isDriverAvailable("QSQLITE");
    QSqlQuery q;
    if(!q.exec(QLatin1String("CREATE TABLE student(ID INT PRIMARY KEY, "
                             "name VARCHAR, "
                             "dorm VARCHAR)")))
        return q.lastError();
    if(!q.exec(QLatin1String("CREATE TABLE grade(subject_id INT PRIMARY KEY,"
                             "subject_name VARCHAR,"
                             "ID INT,"
                             "xuefen INT"
                             "ps_s, double,"
                             "sy_s, double,"
                             "jm_s, double,"
                             "total_s,double,"
                             "yd_xuefen, double)")));
        return q.lastError();

	QsqlQuery q;
	q.exec();
}


#endif // INITDB_H
