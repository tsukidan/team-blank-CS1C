#include "creatememberdialogue.h"
#include "ui_creatememberdialogue.h"
#include <QDebug>

createMemberdialogue::createMemberdialogue(QWidget *parent)
    : QDialog(parent), ui(new Ui::createMemberdialogue) {
  ui->setupUi(this);
}

createMemberdialogue::~createMemberdialogue() { delete ui; }

Member createMemberdialogue::getMember() { return member; }

void createMemberdialogue::on_buttonBox_accepted() {
  int memberID = ui->memberIDSpinbox->value();
  QString memberName = ui->nameLineEdit->text();
  QDate expireDate = ui->expireDate->date();
  bool execStatus;

  if (ui->typeComboBox->currentText() == "Executive") {
    execStatus = true;
  } else {
    execStatus = false;
  }
  member = Member(memberID, memberName, execStatus, expireDate);
}
