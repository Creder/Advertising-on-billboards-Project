#include "mapview.h"
#include <QWebEnginePage>


MapView::MapView(QWidget *parent) : QWidget(parent)
{

    map = new QWebEngineView(this);
    box = new QHBoxLayout(this);
    box->addWidget(map);
    config_map();
    populateJavaScriptWindowObject();
}

void MapView::config_map()
{
    map->load(QUrl("file:///D:/git/Advertising-on-billboards-Project/app/Advestering_on_billboards/map.html"));
}

void MapView::populateJavaScriptWindowObject()
{
    channel = new QWebChannel(map->page());

    map->page()->setWebChannel(channel);


    channel->registerObject(QString("mapclick"), this);
}

void MapView::marker_click()
{
    QString marker = QString("markers(%1,%2,'You clicked me'); null")
                                                          .arg(this->getLatLng().rx())
                                                          .arg(this->getLatLng().ry());
    map->page()->runJavaScript(marker);
}


QPointF MapView::getLatLng()
{
    return mVar;
}

void MapView::set(float lat, float lng)
{
    mVar.setX(lat);
    mVar.setY(lng);
}


