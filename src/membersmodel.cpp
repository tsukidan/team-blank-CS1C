#include "membersmodel.h"

/**
 * @brief MembersModel::MembersModel
 * @param parent
 */
MembersModel::MembersModel(QObject *parent) : QSqlTableModel(parent) {
  setTable("members");
  select();
  setHeaderData(0, Qt::Horizontal, tr("Membership number"));
  setHeaderData(1, Qt::Horizontal, tr("Name"));
  setHeaderData(2, Qt::Horizontal, tr("Type"));
  setHeaderData(3, Qt::Horizontal, tr("Expiration"));
  setHeaderData(4, Qt::Horizontal, tr("Rebate"));
}

/**
 * @brief MembersModel::filterByMonth
 * @param date
 */
void MembersModel::filterByMonth(QDate date) {
  QString dateString = date.toString("yyyy-MM-dd");
  setFilter(QString("expiration = '%1'").arg(dateString));
}

QVariant MembersModel::data(const QModelIndex &index, int role) const {
  if (role == Qt::DisplayRole) {
    switch (index.column()) {
    case 2:
      return QSqlTableModel::data(index).toBool() ? "Executive" : "Regular";
    case 4:
      return Utils::moneyDisplay(QSqlTableModel::data(index).toInt());
    }
  }
  return QSqlTableModel::data(index, role);
}

void MembersModel::clearFilterByMonth() { setFilter(""); }
