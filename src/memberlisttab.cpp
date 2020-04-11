#include "memberlisttab.h"
#include "ui_memberlisttab.h"

MemberListTab::MemberListTab(QWidget *parent)
    : QWidget(parent), ui(new Ui::MemberListTab) {
  ui->setupUi(this);
  MembersModel *model = new MembersModel(parent);

  ui->memberTable->setModel(model);
  ui->memberTable->show();
}

MemberListTab::~MemberListTab() { delete ui; }
