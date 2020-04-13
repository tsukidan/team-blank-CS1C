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
};

#endif // INVENTORYMODEL_H
