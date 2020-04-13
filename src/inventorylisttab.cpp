#include "inventorylisttab.h"
#include "ui_inventorylisttab.h"

InventoryListTab::InventoryListTab(QWidget *parent)
    : QWidget(parent), ui(new Ui::InventoryListTab) {
  ui->setupUi(this);
  inventoryModel = new InventoryModel(parent);

  ui->itemTable->setModel(inventoryModel);
  ui->itemTable->hideColumn(0);
}

void InventoryListTab::reload() { inventoryModel->select(); }

InventoryListTab::~InventoryListTab() { delete ui; }
