#include "inventorymodel.h"

InventoryModel::InventoryModel(QObject *parent) : QSqlTableModel(parent) {
  selectExtra();
  setTable("items");
  select();

  setHeaderData(0, Qt::Horizontal, tr("ID"));
  setHeaderData(1, Qt::Horizontal, tr("Name"));
  setHeaderData(2, Qt::Horizontal, tr("Price"));
  setHeaderData(3, Qt::Horizontal, tr("Sold"));
  setHeaderData(4, Qt::Horizontal, tr("Total revenue"));
}

void InventoryModel::refresh() {
  select();
  selectExtra();
}

void InventoryModel::selectExtra() {
  QSqlQuery query;
  query.prepare("SELECT "
                "    items.id,"
                "    SUM(purchases.quantity),"
                "    SUM(purchases.quantity) * items.price AS revenue "
                "FROM items "
                "LEFT JOIN purchases ON purchases.item_id = items.id "
                "GROUP BY items.id");
  if (!query.exec()) {
    qDebug() << "Failed to search for quantity sold and revenue: "
             << query.lastError().text();
    return;
  }

  while (query.next()) {
    int id = query.value(0).toInt();
    sold.insert(id, query.value(1).toInt());
    revenue.insert(id, query.value(2).toInt());
  }
}

Qt::ItemFlags InventoryModel::flags(const QModelIndex &index) const {
  if (index.column() == 3 || index.column() == 4) {
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemNeverHasChildren;
  }
  return QSqlTableModel::flags(index);
}

int InventoryModel::columnCount(const QModelIndex &parent) const {
  return QSqlTableModel::columnCount(parent) + 2;
}

QVariant InventoryModel::data(const QModelIndex &index, int role) const {
  switch (index.column()) {
  case 2: {
    int price = QSqlTableModel::data(index).toInt();

    switch (role) {
    case (Qt::DisplayRole):
      return Utils::moneyDisplay(price);
    case Qt::EditRole:
      return price / 100.0;
    }

    break;
  }
  case 3:
  case 4: {
    int id = QSqlTableModel::record(index.row()).value(0).toInt();

    if (role == Qt::DisplayRole) {
      if (index.column() == 3) {
        return sold[id];
      } else {
        return Utils::moneyDisplay(revenue[id] * 0.0075);
      }
    }
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
