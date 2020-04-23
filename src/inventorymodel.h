#ifndef INVENTORYMODEL_H
#define INVENTORYMODEL_H

#include "utils.h"
#include <QDate>
#include <QDebug>
#include <QHash>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>

class InventoryModel : public QSqlTableModel {
public:
  InventoryModel(QObject *parent = nullptr);

  void InventoryModel::refresh();

  virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
  virtual QVariant data(const QModelIndex &index,
                        int role = Qt::DisplayRole) const override;
  virtual int columnCount(const QModelIndex &index) const override;
  virtual bool setData(const QModelIndex &index, const QVariant &value,
                       int role = Qt::EditRole) override;

private:
  void InventoryModel::selectExtra();

  QHash<int, int> sold;
  QHash<int, int> revenue;
};

#endif // INVENTORYMODEL_H
