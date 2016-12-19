#include "image_view.h"
#include "ui_image_view.h"


Image_View::Image_View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Image_View)
{

    ui->setupUi(this);
}

Image_View::~Image_View()
{
    delete ui;
}


void Image_View::recieveData(QString name)
{
    QString path = "D:/xampp/htdocs/test.site/images";
    currdir = QDir(path);
    name = currdir.filePath(name);

    QImage image;
    image.load(name);

    ui->label->setScaledContents( true );
    QSizePolicy qsp(QSizePolicy::Ignored,QSizePolicy::Ignored);
    //qsp.setHeightForWidth(true);
    ui->label->setSizePolicy(qsp);

    ui->label->setPixmap(QPixmap::fromImage(image));

}
