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
        ClientName = otherOrders.ClientName;
        Date = otherOrders.Date;
        CompleteDate = otherOrders.CompleteDate;
        Status = otherOrders.Status;
        Filename = otherOrders.Filename;
    }

    Orders(int orderID, QString clientname, QString date, QString completedate, QString status, QString filename)
    {
        OrderID = orderID;
        ClientName = clientname;
        Date = date;
        CompleteDate = completedate;
        Status = status;
        Filename = filename;

    }

    int OrderID;
    QString ClientName;
    QString Date;
    QString CompleteDate;
    QString Status;
    QString Filename;
};

struct Markers
{
    Markers(const Markers& otherMarkers)
    {
        Markername = otherMarkers.Markername;
        Status = otherMarkers.Status;
    }

    Markers(QString markername,QString status)
    {
        Markername = markername;
        Status = status;

    }

    QString Markername;
    QString Status;
    QString Filename;

};
class DataBaseService
{
private:
    QSqlDatabase OpenDatabase();

    QSqlQuery Query;
public:
    std::vector<Orders> Select_Orders();
    std::vector<Markers> Select_Markers();
    void connect();


};

#endif // DATABASESERVICE_H
