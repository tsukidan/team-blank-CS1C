#include "membersmodel.h"
#include <QDebug>
/**
 * @brief MembersModel::MembersModel
 * @param parent
 */
MembersModel::MembersModel(QObject *parent) : QSqlTableModel(parent) {
  selectExtra();
  setTable("members");
  select();

  setHeaderData(0, Qt::Horizontal, tr("Membership number"));
  setHeaderData(1, Qt::Horizontal, tr("Name"));
  setHeaderData(2, Qt::Horizontal, tr("Type"));
  setHeaderData(3, Qt::Horizontal, tr("Expiration"));
  setHeaderData(4, Qt::Horizontal, tr("Rebate"));
  setHeaderData(5, Qt::Horizontal, tr("Revenue"));
  setHeaderData(6, Qt::Horizontal, tr("Recommended Conversions"));
}
void MembersModel::memberRefresh() {
  select();
  selectExtra();
}
void MembersModel::selectExtra() {
  QSqlQuery query;
  query.prepare("SELECT "
                "    members.id,"
                "    SUM(purchases.quantity * items.price) AS revenue "
                "FROM purchases "
                "INNER JOIN members ON members.id = purchases.member_id "
                "INNER JOIN items ON items.id = purchases.item_id "
                "GROUP BY members.id");
  if (!query.exec()) {
    qDebug() << "Failed to search for quantity sold and revenue: "
             << query.lastError().text();
    return;
  }

  while (query.next()) {
    int id = query.value(0).toInt();
    int revenueFromMember = query.value(1).toInt();
    if (revenueFromMember != 0) {
      revenue.insert(id, revenueFromMember);
    }
  }
}

/**
 * @brief MembersModel::filterByDate
 * @param date
 */
void MembersModel::filterByDate(QDate start, QDate end) {
  QString startString = start.toString("yyyy-MM-dd");
  QString endString   = end.toString("yyyy-MM-dd");
  setFilter(QString("expiration BETWEEN '%1' AND '%2'").arg(startString).arg(endString));
}

Qt::ItemFlags MembersModel::flags(const QModelIndex &index) const {
  if (index.column() >= 5 || index.column() <= 7) {
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemNeverHasChildren;
  }
  return QSqlTableModel::flags(index);
}

int MembersModel::columnCount(const QModelIndex &parent) const {
  return QSqlTableModel::columnCount(parent) + 3;
}

QVariant MembersModel::data(const QModelIndex &index, int role) const {
  if (role == Qt::DisplayRole) {
    switch (index.column()) {
    case 2:
      return QSqlTableModel::data(index).toBool() ? "Executive" : "Regular";
    case 4: {
      int id = QSqlTableModel::record(index.row()).value(0).toInt();

      return Utils::moneyDisplay(revenue[id] * 0.02);
    }
    case 5: {
      int id = QSqlTableModel::record(index.row()).value(0).toInt();

      return Utils::moneyDisplay(revenue[id]);
    }
    case 6: {
      int id = QSqlTableModel::record(index.row()).value(0).toInt();
      int isExecutive = QSqlTableModel::record(index.row()).value(2).toBool();

      int rebate = revenue[id] * 0.02;

      if (!isExecutive && rebate > 12000 - 6500) {
        return "Should Upgrade";
      } else if (isExecutive && rebate < 12000 - 6500) {
        return "Should Downgrade";
      } else {
        return "Should Stay";
      }
    }
    }
  }
  return QSqlTableModel::data(index, role);
}

void MembersModel::clearFilterByMonth() { setFilter(""); }
