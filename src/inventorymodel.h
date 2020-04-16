#ifndef INVENTORYMODEL_H
#define INVENTORYMODEL_H

#include <QDate>
#include <QLocale>
#include <QSqlTableModel>

class InventoryModel : public QSqlTableModel {
public:
  InventoryModel(QObject *parent = nullptr);

  virtual QVariant data(const QModelIndex &index,
                        int role = Qt::DisplayRole) const override;
  virtual bool setData(const QModelIndex &index, const QVariant &value,
                       int role = Qt::EditRole) override;
};

#endif // INVENTORYMODEL_H
