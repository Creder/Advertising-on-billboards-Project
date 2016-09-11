#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

void  MainWindow::SetupTables()
{

    Orders_table = new QStandardItemModel;


    QStringList horizontalHeader_orders;
    horizontalHeader_orders.append("ID Заказа");
    horizontalHeader_orders.append("Тип");
    horizontalHeader_orders.append("ID Клиента");
    horizontalHeader_orders.append("Дата");
    horizontalHeader_orders.append("Статус");

    Orders_table->setHorizontalHeaderLabels(horizontalHeader_orders);

    ui->OrdersTable->setModel(Orders_table);

}

void MainWindow::RefreshOrders()
{
    DataBaseService service;
    auto orders = service.Select_Orders();
    for (int rowIndex = 0; rowIndex < orders.size(); rowIndex++)
    {
       // qDebug() << "1";
        Orders_table->setItem(rowIndex, 0, new QStandardItem(QString::number(orders[rowIndex].OrderID)));
        Orders_table->setItem(rowIndex, 1, new QStandardItem(QString::number(orders[rowIndex].Type)));
        Orders_table->setItem(rowIndex, 2, new QStandardItem(QString::number(orders[rowIndex].ClientID)));
        Orders_table->setItem(rowIndex, 3, new QStandardItem(orders[rowIndex].Date));
        Orders_table->setItem(rowIndex, 4, new QStandardItem(QString::number(orders[rowIndex].Status)));
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SetupTables();
    RefreshOrders();
}

MainWindow::~MainWindow()
{
    delete ui;
}
