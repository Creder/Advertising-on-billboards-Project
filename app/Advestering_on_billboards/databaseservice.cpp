#include "databaseservice.h"
#include <QSqlError>
#include <QDebug>

QSqlDatabase DataBaseService::OpenDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("agadver");
    db.setUserName("root");
    db.setPassword("Dz4hVaop5");
    //db.setConnectOptions();
    bool connected =  db.open();
    if (connected == true)
        {
          qDebug() << "Ok1";
        }
    else
        {
          qDebug() << "Error for database " << db.databaseName() << " :" << db.lastError().text() << endl;
        }

    return db;
}

std::vector<Orders> DataBaseService::Select_Orders()
{


    QSqlQuery sqlQuery = QSqlQuery(OpenDatabase());

    sqlQuery.exec("call Select_Orders()");
    std::vector<Orders> result;
    while(sqlQuery.next())
    {
        int orderID = sqlQuery.value("id").toInt();
        int type = sqlQuery.value("type_id").toInt();
        QString clientname = sqlQuery.value("user_id").toString();
        QString date = sqlQuery.value("filing_date").toString();
        QString completedate = sqlQuery.value("complete_date").toString();
        int status = sqlQuery.value("order_status").toInt();
        result.push_back(Orders(orderID, type, clientname, date, completedate, status));
        qDebug() << orderID;
    }

    return result;
}
