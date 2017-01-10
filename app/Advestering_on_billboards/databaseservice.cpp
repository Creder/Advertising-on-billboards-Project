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

void DataBaseService::connect()
{
   Query = QSqlQuery(OpenDatabase());
}

std::vector<Orders> DataBaseService::Select_Orders()
{ 
    Query.exec("call Select_Orders()");
    std::vector<Orders> result;
    while(Query.next())
    {
        int orderID = Query.value("id").toInt();
        QString clientname = Query.value("user_id").toString();
        QString date = Query.value("filing_date").toString();
        QString status = Query.value("order_status").toString();
        QString completedate = Query.value("complete_date").toString();
        QString filename = Query.value("filename").toString();
        result.push_back(Orders(orderID, clientname, date, completedate, status, filename));
    }

    return result;
}

std::vector<Markers> DataBaseService::Select_Markers()
{
    Query.exec("call Select_Markers()");
    std::vector<Markers> result;
    while(Query.next())
    {
        QString name = Query.value("name").toString();
        QString status = Query.value("status").toString();
        result.push_back(Markers( name, status));
    }

    return result;
}
