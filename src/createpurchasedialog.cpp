#include "createpurchasedialog.h"
#include "ui_createpurchasedialog.h"

CreatePurchaseDialog::CreatePurchaseDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreatePurchaseDialog) {
  QSqlQuery query;
  int i;

  ui->setupUi(this);

  if (!query.exec("SELECT id, name FROM members")) {
    qDebug() << "Failed to select all members for the dropbox: "
             << query.lastError().text();
  }

  i = 0;
  while (query.next()) {
    int id = query.value(0).toInt();
    QString name = query.value(1).toString();
    ui->memberComboBox->insertItem(i, QString("%1 - %2").arg(id).arg(name), id);
    i++;
  }

  if (!query.exec("SELECT id, name, price FROM items")) {
    qDebug() << "Failed to select all items for the dropbox: "
             << query.lastError().text();
  }
  i = 0;
  while (query.next()) {
    int id = query.value(0).toInt();
    QString name = query.value(1).toString();
    QString price = Utils::moneyDisplay(query.value(2).toInt());
    ui->itemComboBox->insertItem(i, QString("%1 - %2").arg(name).arg(price),
                                 id);
    i++;
  }
}

CreatePurchaseDialog::~CreatePurchaseDialog() { delete ui; }

Purchase CreatePurchaseDialog::getPurchase() const { return purchase; }

void CreatePurchaseDialog::on_CreatePurchaseDialog_accepted() {
  int memberId;
  int itemId;
  int quantity;

  memberId = ui->memberComboBox->currentData().toInt();
  itemId = ui->itemComboBox->currentData().toInt();
  quantity = ui->quantitySpinBox->value();

  purchase = Purchase(memberId, itemId, QDate::currentDate(), quantity);
}
