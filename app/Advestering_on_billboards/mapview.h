#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QWidget>
#include <QWebEngineView>
#include <QHBoxLayout>
#include <QWebChannel>
#include <QPointF>

class MapView : public QWidget
{
    Q_OBJECT
public:
    explicit MapView(QWidget *parent = 0);
    QPointF getLatLng();

private slots:
    void config_map();
    void populateJavaScriptWindowObject();
    void marker_click();
signals:

private:
    MapView * mapWidget;
    QWebEngineView *map;
    QHBoxLayout *box;
    QWebChannel *channel;
    QPointF mVar;
public slots:
    void set(float lat, float lng);

};

#endif // MAPVIEW_H
