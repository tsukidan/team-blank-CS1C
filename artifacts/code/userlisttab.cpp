#include "userlisttab.h"
#include "ui_userlisttab.h"

UserListTab::UserListTab(QWidget *parent)
    : QWidget(parent), ui(new Ui::UserListTab) {
  ui->setupUi(this);

  UsersModel *model = new UsersModel();
  BooleanComboBoxDelegate *comboBox =
      new BooleanComboBoxDelegate("Admin", "Store member");

  ui->userTable->setModel(model);
  ui->userTable->setItemDelegateForColumn(3, comboBox);

  ui->userTable->openPersistentEditor();
  ui->userTable->hideColumn(0);
}

UserListTab::~UserListTab() { delete ui; }
