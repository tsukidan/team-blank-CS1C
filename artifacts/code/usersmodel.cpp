#include "usersmodel.h"
#include <QDebug>

UsersModel::UsersModel(QObject *parent) : QSqlTableModel(parent) {
  setTable("users");
  select();
  setHeaderData(0, Qt::Horizontal, tr("ID"));
  setHeaderData(1, Qt::Horizontal, tr("Username"));
  setHeaderData(2, Qt::Horizontal, tr("Password"));
  setHeaderData(3, Qt::Horizontal, tr("Admin"));
}

// Qt::ItemFlags UsersModel::flags(const QModelIndex &index) const {
//   if (index.column() == 3) {
//     return QSqlTableModel::flags(index) | Qt::ItemIsUserCheckable;
//   }
//   return QSqlTableModel::flags(index);
// }

// QVariant UsersModel::data(const QModelIndex &index, int role) const {
//   if (index.column() == 3) {
//     if (role == Qt::CheckStateRole) {
//       return QSqlTableModel::data(index).toBool() ? Qt::Checked :
//       Qt::Unchecked;
//     }
//     return QVariant();
//   }
//   return QSqlTableModel::data(index, role);
// }

// bool UsersModel::setData(const QModelIndex &index, const QVariant &value,
//                          int role) {
//   if (index.column() == 3 && role == Qt::CheckStateRole) {
//     if (QSqlTableModel::data(index).toBool()) {
//       return setData(index, 0, Qt::EditRole);
//     } else {
//       return setData(index, 1, Qt::EditRole);
//     }
//   }
//   return QSqlTableModel::setData(index, value, role);
// }
// Qt::ItemFlags UsersModel::flags(const QModelIndex &index) const {
//   if (index.column() == 3) {
//     // Make sure that this item is checkable.
//     return QSqlTableModel::flags(index) | Qt::ItemIsUserCheckable;
//   }
//   // Default behaviour in all other cases.
//   return QSqlTableModel::flags(index);
// }

// QVariant UsersModel::data(const QModelIndex &index, int role) const {
//   if (index.column() == 3) {
//     return QSqlTableModel::data(index).toBool() ? Qt::Checked :
//     Qt::Unchecked;
//   }

//   return QSqlTableModel::data(index, role);
// }

// bool UsersModel::setData(const QModelIndex &index, const QVariant &value,
//                          int role) {
//   qDebug() << role;
//   if (index.column() == 3 && role == Qt::CheckStateRole) {
//     if (value == Qt::Checked) {
//       return setData(index, 0);
//     } else if (value == Qt::Unchecked) {
//       return setData(index, 1);
//     }
//   }

//   return QSqlTableModel::setData(index, value, role);
// }