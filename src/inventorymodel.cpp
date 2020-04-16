#include "inventorymodel.h"
#include <QDebug>

InventoryModel::InventoryModel(QObject *parent) : QSqlTableModel(parent) {
  setTable("items");
  select();
  setHeaderData(0, Qt::Horizontal, tr("ID"));
  setHeaderData(1, Qt::Horizontal, tr("Name"));
  setHeaderData(2, Qt::Horizontal, tr("Price"));
}

QVariant InventoryModel::data(const QModelIndex &index, int role) const {
  if (index.column() == 2) {
    int price = QSqlTableModel::data(index).toInt();
    switch (role) {
    case (Qt::DisplayRole):
      return QString("$") + QString::number(price / 100.0, 'f', 2);
      break;
    case Qt::EditRole:
      return price / 100.0;
      break;
    }
  }
  return QSqlTableModel::data(index, role);
}

bool InventoryModel::setData(const QModelIndex &index, const QVariant &value,
                             int role) {
  if (index.column() == 2) {
    float priceInDollars = value.toFloat();
    int priceInCents = static_cast<int>(priceInDollars * 100);

    return QSqlTableModel::setData(index, priceInCents, role);
  }
  return QSqlTableModel::setData(index, value, role);
}
