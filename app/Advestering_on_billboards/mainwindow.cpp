#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QListWidget>
#include <QImageReader>
void  MainWindow::SetupTables()
{

    Orders_table = new QStandardItemModel;

    QStringList horizontalHeader_orders;
    horizontalHeader_orders.append("№ Заказа");
    horizontalHeader_orders.append("Клиент");
    horizontalHeader_orders.append("Дата подачи");
    horizontalHeader_orders.append("Статус");
    horizontalHeader_orders.append("Дата выполнения");
    horizontalHeader_orders.append("Файл");

    Orders_table->setHorizontalHeaderLabels(horizontalHeader_orders);

    ui->OrdersTable->addAction(ui->actionRefresh);
    ui->OrdersTable->addAction(ui->actionCompleted);
    ui->OrdersTable->addAction(ui->actionCanseled);
    ui->OrdersTable->addAction(ui->actionInProcess);
    ui->OrdersTable->addAction(ui->actionOpen_File);

    ui->OrdersTable->setModel(Orders_table);
    ui->OrdersTable->setColumnHidden(5, true);

}


void MainWindow::RefreshOrders()
{
    //Orders_table->clear();
    DataBaseService service;
    auto orders = service.Select_Orders();
    for (int rowIndex = 0; rowIndex < orders.size(); rowIndex++)
    {
        Orders_table->setItem(rowIndex, 0, new QStandardItem(QString::number(orders[rowIndex].OrderID)));
        Orders_table->setItem(rowIndex, 1, new QStandardItem(orders[rowIndex].ClientName));
        Orders_table->setItem(rowIndex, 2, new QStandardItem(orders[rowIndex].Date));
        Orders_table->setItem(rowIndex, 3, new QStandardItem(orders[rowIndex].Status));
        Orders_table->setItem(rowIndex, 4, new QStandardItem(orders[rowIndex].CompleteDate));
        Orders_table->setItem(rowIndex, 5, new QStandardItem(orders[rowIndex].Filename));
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageform = new Image_View();
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(ui->actionOpen_File, SIGNAL(triggered()), this, SLOT(on_actionOpen_File_triggered()));
    connect(ui->actionOpen_File, SIGNAL(triggered()), this, SLOT(onButtonSend()));
    connect(this, SIGNAL(sendData(QString)), imageform, SLOT(recieveData(QString)));
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

void MainWindow::on_actionOpen_File_triggered()
{
   imageform->show();
}

void MainWindow::onButtonSend()
{
    int row = ui->OrdersTable->selectionModel()->currentIndex().row();
    QString name = ui->OrdersTable->model()->data(ui->OrdersTable->model()->index(row,5)).toString();
    emit sendData(name);
}
