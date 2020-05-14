#ifndef CREATEMEMBERDIALOGUE_H
#define CREATEMEMBERDIALOGUE_H

#include "member.h"
#include <QDialog>

namespace Ui {
class createMemberdialogue;
}

class createMemberdialogue : public QDialog {
  Q_OBJECT

public:
  explicit createMemberdialogue(QWidget *parent = nullptr);
  ~createMemberdialogue();
  Member getMember();

private slots:

  void on_buttonBox_accepted();

private:
  Ui::createMemberdialogue *ui;
  Member member;
};

#endif // CREATEMEMBERDIALOGUE_H
