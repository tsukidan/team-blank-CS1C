#ifndef SETUPWINDOW_H
#define SETUPWINDOW_H

#include <QDialog>
#include <QMessageBox>

#include "user.h"

namespace Ui {
class SetupWindow;
}

class SetupWindow : public QDialog {
  Q_OBJECT

public:
  explicit SetupWindow(QWidget *parent = nullptr);
  ~SetupWindow();

  User getUser();

private slots:
  void on_createButton_clicked();

private:
  Ui::SetupWindow *ui;
  User user;
};

#endif // SETUPWINDOW_H
