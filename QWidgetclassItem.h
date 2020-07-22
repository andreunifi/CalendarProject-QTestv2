#ifndef QWIDGETCLASSITEM_H
#define QWIDGETCLASSITEM_H
#include <QListWidgetItem>
#include <QDate>
class QWidgetv3: public QListWidgetItem{
     Q_OBJECT
private:
    QDate starttime;
    QDate endtime;

public:
    QWidgetv3();


};
#endif // QWIDGETCLASSITEM_H
