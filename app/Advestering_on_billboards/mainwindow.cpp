#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

void  MainWindow::SetupTables()
{

    Orders_table = new QStandardItemModel;


    QStringList horizontalHeader_orders;
    horizontalHeader_orders.append("№ Заказа");
    horizontalHeader_orders.append("Тип");
    horizontalHeader_orders.append("Клиент");
    horizontalHeader_orders.append("Дата подачи");
    horizontalHeader_orders.append("Статус");
    horizontalHeader_orders.append("Дата выполнения");

    Orders_table->setHorizontalHeaderLabels(horizontalHeader_orders);

    ui->OrdersTable->setModel(Orders_table);

}

void MainWindow::RefreshOrders()
{
    DataBaseService service;
    auto orders = service.Select_Orders();
    for (int rowIndex = 0; rowIndex < orders.size(); rowIndex++)
    {
        Orders_table->setItem(rowIndex, 0, new QStandardItem(QString::number(orders[rowIndex].OrderID)));
        Orders_table->setItem(rowIndex, 1, new QStandardItem(QString::number(orders[rowIndex].Type)));
        Orders_table->setItem(rowIndex, 2, new QStandardItem(orders[rowIndex].ClientName));
        Orders_table->setItem(rowIndex, 3, new QStandardItem(orders[rowIndex].Date));
        Orders_table->setItem(rowIndex, 3, new QStandardItem(orders[rowIndex].CompleteDate));
        Orders_table->setItem(rowIndex, 4, new QStandardItem(QString::number(orders[rowIndex].Status)));
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));
    SetupTables();
    RefreshOrders();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}
