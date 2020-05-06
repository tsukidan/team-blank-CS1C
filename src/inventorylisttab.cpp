#include "inventorylisttab.h"
#include "ui_inventorylisttab.h"

InventoryListTab::InventoryListTab(User const &user, QWidget *parent)
    : QWidget(parent), ui(new Ui::InventoryListTab) {
  ui->setupUi(this);
  inventoryModel = new InventoryModel(parent);

  ui->itemTable->setModel(inventoryModel);
  ui->itemTable->hideColumn(0);

  if (!user.isAdmin()) {
    ui->addItemButton->hide();
  }
}

void InventoryListTab::refresh() { inventoryModel->refresh(); }

InventoryListTab::~InventoryListTab() { delete ui; }

void InventoryListTab::on_addItemButton_clicked() {
  CreateItemDialog createItemDialog;

  if (createItemDialog.exec()) {
    Item item = createItemDialog.getItem();
    item.save();
    inventoryModel->refresh();
  }
}

void InventoryListTab::on_deleteItemButton_clicked() {
  QItemSelectionModel *selection = ui->itemTable->selectionModel();

  QSqlDatabase::database().transaction();
  for (QModelIndex index : selection->selectedRows()) {
    int id = inventoryModel->data(index, Qt::EditRole).toInt();

    Item::deleteById(id);
  }
  QSqlDatabase::database().commit();
  inventoryModel->refresh();
}
