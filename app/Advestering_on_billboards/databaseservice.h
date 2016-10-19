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
        ClientName = otherOrders.ClientName;
        Date = otherOrders.Date;
        CompleteDate = otherOrders.CompleteDate;
        Status = otherOrders.Status;
    }

    Orders(int orderID, int type, QString clientname, QString date, QString completedate, int status)
    {
        OrderID = orderID;
        Type = type;
        ClientName = clientname;
        Date = date;
        CompleteDate = completedate;
        Status = status;

    }

    int OrderID;
    int Type;
    QString ClientName;
    QString Date;
    QString CompleteDate;
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
