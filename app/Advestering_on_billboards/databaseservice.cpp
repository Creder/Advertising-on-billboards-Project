#include "databaseservice.h"
#include <QSqlError>
#include <QDebug>

QSqlDatabase DataBaseService::OpenDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("agadver");
    db.setUserName("juno");
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
        int clientID = sqlQuery.value("user_id").toInt();
        QString date = sqlQuery.value("filing_date").toString();
        int status = sqlQuery.value("order_status").toInt();
        result.push_back(Orders(orderID, type, clientID, date, status));
        qDebug() << orderID;
    }

    return result;
}
