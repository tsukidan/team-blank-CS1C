#ifndef INVENTORYLISTTAB_H
#define INVENTORYLISTTAB_H

#include "inventorymodel.h"
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class InventoryListTab;
}

class InventoryListTab : public QWidget {
  Q_OBJECT

public:
  explicit InventoryListTab(QWidget *parent = nullptr);
  ~InventoryListTab();

  void reload();

private:
  Ui::InventoryListTab *ui;
  InventoryModel *inventoryModel;
};

#endif // INVENTORYLISTTAB_H
