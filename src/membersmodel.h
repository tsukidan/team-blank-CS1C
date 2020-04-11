#ifndef MEMBERSMODEL_H
#define MEMBERSMODEL_H

#include <QLocale>
#include <QSqlTableModel>


class MembersModel : public QSqlTableModel {
public:
  MembersModel(QObject *parent = nullptr);

  virtual QVariant data(const QModelIndex &index,
                        int role = Qt::DisplayRole) const override;
};

#endif // MEMBERSMODEL_H
