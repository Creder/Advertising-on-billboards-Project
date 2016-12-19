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
          qDebug() << "Connected";
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

    sqlQuery.exec("call Select_orders()");
    std::vector<Orders> result;
    while(sqlQuery.next())
    {
        int orderID = sqlQuery.value("id").toInt();
        QString clientname = sqlQuery.value("user_id").toString();
        QString date = sqlQuery.value("filing_date").toString();
        QString status = sqlQuery.value("order_status").toString();
        QString completedate = sqlQuery.value("complete_date").toString();
        QString filename = sqlQuery.value("filename").toString();
        result.push_back(Orders(orderID, clientname, date, completedate, status, filename));
    }

    return result;
}
