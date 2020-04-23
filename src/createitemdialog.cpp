#include "createitemdialog.h"
#include "ui_createitemdialog.h"
#include <QDebug>

CreateItemDialog::CreateItemDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreateItemDialog) {
  ui->setupUi(this);
}

CreateItemDialog::~CreateItemDialog() { delete ui; }

Item CreateItemDialog::getItem() { return item; }

void CreateItemDialog::on_buttonBox_accepted() {
  QString name = ui->nameLineEdit->text();
  int price = ui->priceSpinBox->value() * 100;

  item = Item(name, price);
}
