#ifndef USERLISTTAB_H
#define USERLISTTAB_H

#include "booleancomboboxdelegate.h"
#include "usersmodel.h"
#include <QSqlTableModel>
#include <QWidget>


namespace Ui {
class UserListTab;
}

class UserListTab : public QWidget {
  Q_OBJECT

public:
  explicit UserListTab(QWidget *parent = nullptr);
  ~UserListTab();

private:
  Ui::UserListTab *ui;
};

#endif // USERLISTTAB_H
