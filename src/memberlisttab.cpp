#include "memberlisttab.h"
#include "ui_memberlisttab.h"
#include "member.h"
#include <QMessageBox>

MemberListTab::MemberListTab(const User &user, QWidget *parent)
    : QWidget(parent), ui(new Ui::MemberListTab) {
  ui->setupUi(this);

  membersModel = new MembersModel(parent);

  ui->memberTable->setModel(membersModel);
  ui->memberTable->show();

  if (!user.isAdmin()) {
    ui->addUserButton->hide();
    ui->deleteUserButton->hide();
  }
}

MemberListTab::~MemberListTab() { delete ui; }

// void MemberListTab::on_filterMonth_userDateChanged(const QDate &date) {
//   membersModel->filterByMonth(date);
// }

void MemberListTab::on_filterMonthCheckbox_stateChanged(int checked) {
  if (checked == 0) {
    ui->yearSpinBox->setEnabled(false);
    ui->monthComboBox->setEnabled(false);
    membersModel->clearFilterByMonth();
  } else {
    ui->yearSpinBox->setEnabled(true);
    ui->monthComboBox->setEnabled(true);
  }
}

void MemberListTab::on_addUserButton_clicked() {
  QMessageBox addMsgBox;
  addMsgBox.setText("TODO: Add user functionality");
  addMsgBox.exec();
}

void MemberListTab::on_deleteUserButton_clicked() {
  QItemSelectionModel *selection = ui->memberTable->selectionModel();

  QSqlDatabase::database().transaction();
  for (QModelIndex index : selection->selectedRows()) {
    int id = membersModel->data(index, Qt::EditRole).toInt();

    Member::deleteById(id);
  }
  QSqlDatabase::database().commit();
  membersModel->memberRefresh();
}
