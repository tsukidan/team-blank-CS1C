#ifndef INVENTORYLISTTAB_H
#define INVENTORYLISTTAB_H

#include "createitemdialog.h"
#include "inventorymodel.h"
#include "user.h"
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class InventoryListTab;
}

class InventoryListTab : public QWidget {
  Q_OBJECT

public:
  explicit InventoryListTab(User const &user, QWidget *parent = nullptr);
  ~InventoryListTab();

  void reload();

private slots:
  void on_addItemButton_clicked();

  void on_deleteItemButton_clicked();

private:
  Ui::InventoryListTab *ui;
  InventoryModel *inventoryModel;
};

#endif // INVENTORYLISTTAB_H
