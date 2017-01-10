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
#include "image_view.h"
#include "mapview.h"
#include <QListWidget>
#include <QLabel>


class MapView;

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
    void RefreshMarkers();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionRefresh_triggered()
    {
      RefreshOrders();
    }

    void onButtonSend();

    void on_actionOpen_File_triggered();

signals:
    void sendData(QString name);
private:
    Ui::MainWindow *ui;
    QStandardItemModel *Orders_model;
    QStandardItemModel *Markers_model;
    QTableView *OrdersTable;
    QTableView *MarkersTable;
    Image_View *imageform;
    QLabel *filename;
    DataBaseService service;

};

#endif // MAINWINDOW_H
