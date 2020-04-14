#include "inventorymodel.h"

InventoryModel::InventoryModel(QObject *parent) : QSqlTableModel(parent) {
  setTable("items");
  select();
  setHeaderData(0, Qt::Horizontal, tr("ID"));
  setHeaderData(1, Qt::Horizontal, tr("Name"));
  setHeaderData(2, Qt::Horizontal, tr("Price"));
}

QVariant InventoryModel::data(const QModelIndex &index, int role) const {
  if (role == Qt::DisplayRole && index.column() == 2) {
    int price = QSqlTableModel::data(index).toInt();

    return QString("$") + QString::number(price / 100.0, 'f', 2);
  }
  return QSqlTableModel::data(index, role);
}
