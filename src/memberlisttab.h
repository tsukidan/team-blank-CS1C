#ifndef MEMBERLISTTAB_H
#define MEMBERLISTTAB_H

#include "createpurchasedialog.h"
#include "membersmodel.h"
#include "creatememberdialogue.h"
#include "user.h"
#include <QWidget>

namespace Ui {
class MemberListTab;
}

class MemberListTab : public QWidget {
  Q_OBJECT

public:
  explicit MemberListTab(const User &user, QWidget *parent = nullptr);
  ~MemberListTab();

  void refresh();

private slots:

  // void on_filterMonth_userDateChanged(const QDate &date);

  void on_filterMonthCheckbox_stateChanged(int arg1);

  void on_addUserButton_clicked();

  void on_deleteUserButton_clicked();

  void updateTotalRevenue();

  void on_monthComboBox_activated(int index);

  void on_createPurchaseButton_clicked();

private:
  Ui::MemberListTab *ui;
  MembersModel *membersModel;
};

#endif // MEMBERLISTTAB_H
