#ifndef MEMBERSMODEL_H
#define MEMBERSMODEL_H

#include "utils.h"
#include <QDate>
#include <QLocale>
#include <QSqlTableModel>
#include <QtSql>

class MembersModel : public QSqlTableModel {
public:
  MembersModel(QObject *parent = nullptr);

  virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
  virtual QVariant data(const QModelIndex &index,
                        int role = Qt::DisplayRole) const override;
  virtual int columnCount(const QModelIndex &index) const override;

  void filterByMonth(QDate date);

  void clearFilterByMonth();

  void memberRefresh();
  void selectExtra();
private:
  QHash<int, int> revenue;
};

#endif // MEMBERSMODEL_H
