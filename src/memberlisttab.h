#ifndef MEMBERLISTTAB_H
#define MEMBERLISTTAB_H

#include "membersmodel.h"
#include <QWidget>

namespace Ui {
class MemberListTab;
}

class MemberListTab : public QWidget {
  Q_OBJECT

public:
  explicit MemberListTab(QWidget *parent = nullptr);
  ~MemberListTab();

private:
  Ui::MemberListTab *ui;
};

#endif // MEMBERLISTTAB_H
