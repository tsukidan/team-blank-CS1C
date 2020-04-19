#ifndef MEMBERSMODEL_H
#define MEMBERSMODEL_H

#include "utils.h"
#include <QDate>
#include <QLocale>
#include <QSqlTableModel>

class MembersModel : public QSqlTableModel {
public:
  MembersModel(QObject *parent = nullptr);

  virtual QVariant data(const QModelIndex &index,
                        int role = Qt::DisplayRole) const override;

  void filterByMonth(QDate date);

  void clearFilterByMonth();
};

#endif // MEMBERSMODEL_H
