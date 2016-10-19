#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStringList>
#include <QSqlError>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QStandardItem>
#include "databaseservice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void SetupTables();
    void RefreshOrders();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *Orders_table;
};

#endif // MAINWINDOW_H
