#include "memberlisttab.h"
#include "member.h"
#include "ui_memberlisttab.h"
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
    ui->memberTable->hideColumn(6);
  }
  updateTotalRevenue();
}

void MemberListTab::updateTotalRevenue() {
  QSqlQuery query;

  query.prepare("SELECT "
                "    SUM(purchases.quantity * items.price) AS revenue "
                "FROM purchases "
                "INNER JOIN items ON items.id = purchases.item_id");
  if (!query.exec()) {
    qDebug() << "Failed to compute the grand total revenue: "
             << query.lastError().text();
    return;
  }
  int totalRevenue;

  if (!query.next()) {
    qDebug() << "No purchases found";
    return;
  }
  totalRevenue = query.value(0).toInt();
  ui->totalRevenue->setText(
      QString("Grand total revenue: %1")
          .arg(Utils::moneyDisplay(totalRevenue * 0.0775)));
}

void MemberListTab::refresh() {
  updateTotalRevenue();
  membersModel->memberRefresh();
}

MemberListTab::~MemberListTab() { delete ui; }

void MemberListTab::on_filterMonthCheckbox_stateChanged(int checked) {
  if (checked == 0) {
    ui->yearSpinBox->setEnabled(false);
    ui->monthComboBox->setEnabled(false);
    membersModel->clearFilterByMonth();
  } else {
    ui->yearSpinBox->setEnabled(true);
    ui->monthComboBox->setEnabled(true);
    updateFilters();
  }
}
void MemberListTab::updateFilters() {
  int year = ui->yearSpinBox->value();
  int month = ui->monthComboBox->currentIndex();
  QDate start = QDate(year, month + 1, 1);
  QDate end = QDate(year, month + 1, 1).addMonths(1).addDays(-1);
  membersModel->filterByDate(start, end);
}
void MemberListTab::on_addUserButton_clicked() {
  createMemberdialogue memberWindow;
  if (memberWindow.exec()) {
    Member member = memberWindow.getMember();
    member.save();
    membersModel->memberRefresh();
  }
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

void MemberListTab::on_createPurchaseButton_clicked() {
  CreatePurchaseDialog createPurchaseDialog;
  if (createPurchaseDialog.exec() == QDialog::Accepted) {
    Purchase purchase = createPurchaseDialog.getPurchase();

    purchase.save();
    refresh();
  }
}

void MemberListTab::on_yearSpinBox_valueChanged(int arg1) { updateFilters(); }

void MemberListTab::on_monthComboBox_activated(int index) { updateFilters(); }
