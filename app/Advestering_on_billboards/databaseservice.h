#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

struct Orders
{
    Orders(const Orders& otherOrders)
    {
        OrderID = otherOrders.OrderID;
        Type = otherOrders.Type;
        ClientID = otherOrders.ClientID;
        Date = otherOrders.Date;
        Status = otherOrders.Status;
    }

    Orders(int orderID, int type, int clientID, QString date, int status)
    {
        OrderID = orderID;
        Type = type;
        ClientID = clientID;
        Date = date;
        Status = status;

    }

    int OrderID;
    int Type;
    int ClientID;
    QString Date;
    int Status;
};

class DataBaseService
{
private:
    QSqlDatabase OpenDatabase();
public:
    std::vector<Orders> Select_Orders();


};

#endif // DATABASESERVICE_H
