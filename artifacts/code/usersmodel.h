#ifndef USERSMODEL_H
#define USERSMODEL_H

#include <QLocale>
#include <QSqlTableModel>

class UsersModel : public QSqlTableModel {
public:
  UsersModel(QObject *parent = nullptr);

  // virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
  // virtual QVariant data(const QModelIndex &index,
  //                       int role = Qt::DisplayRole) const override;
  // virtual bool setData(const QModelIndex &index, const QVariant &value,
  //                      int role = Qt::DisplayRole) override;
};

#endif // USERSMODEL_H
