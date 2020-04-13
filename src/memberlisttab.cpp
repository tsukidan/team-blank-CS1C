#include "memberlisttab.h"
#include "ui_memberlisttab.h"

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
