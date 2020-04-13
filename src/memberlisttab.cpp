#include "memberlisttab.h"
#include "ui_memberlisttab.h"
#include <QMessageBox>

MemberListTab::MemberListTab(QWidget *parent)
    : QWidget(parent), ui(new Ui::MemberListTab) {
  ui->setupUi(this);

  membersModel = new MembersModel(parent);

  ui->memberTable->setModel(membersModel);
  ui->memberTable->show();
}

MemberListTab::~MemberListTab() { delete ui; }

void MemberListTab::on_filterMonth_userDateChanged(const QDate &date)
{
    membersModel->filterByMonth(date);
}

void MemberListTab::on_filterMonthCheckbox_stateChanged(int checked)
{
    if(checked == 0)
    {
        ui->filterMonth->setEnabled(false);
        membersModel->clearFilterByMonth();
    }
    else
    {
        ui->filterMonth->setEnabled(true);
    }
}

void MemberListTab::on_addUserButton_clicked()
{
    QMessageBox addMsgBox;
    addMsgBox.setText("TODO: Add user functionality");
    addMsgBox.exec();
}

void MemberListTab::on_deleteUserButton_clicked()
{
    QMessageBox deleteMsgBox;
    deleteMsgBox.setText("TODO: Delte user functionality\n"
                         "Add in a way to delete highlighted items?");
    deleteMsgBox.exec();
}
