#ifndef SALESREPORT_H
#define SALESREPORT_H

#include "utils.h"
#include <QDate>
#include <QLocale>
#include <QWidget>
#include <QSqlQueryModel>
#include <QSql>
#include <QtSql>

namespace Ui {
class Salesreport;
}

class Salesreport : public QWidget
{
    Q_OBJECT

public:
    explicit Salesreport(QWidget *parent = nullptr);
    ~Salesreport();

private slots:
    void on_filterType_stateChanged(int arg1);

    void on_dateEdit_dateChanged(const QDate &date);

    void on_memberType_currentIndexChanged(int index);

private:
    void updateMembers();
    Ui::Salesreport *ui;
};

#endif // SALESREPORT_H
