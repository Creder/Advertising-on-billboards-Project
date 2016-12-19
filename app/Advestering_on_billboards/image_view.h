#ifndef IMAGE_VIEW_H
#define IMAGE_VIEW_H

#include <QWidget>
#include <QLabel>
#include <QDir>

namespace Ui {
class Image_View;
}

class Image_View : public QWidget
{
    Q_OBJECT

public:
    explicit Image_View(QWidget *parent = 0);
    ~Image_View();

private:
    Ui::Image_View *ui;
    QDir currdir;

private slots:
    void recieveData(QString name);
};

#endif // IMAGE_VIEW_H
