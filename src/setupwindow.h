#ifndef SETUPWINDOW_H
#define SETUPWINDOW_H

#include <QMessageBox>
#include <QWidget>
#include "user.h"

namespace Ui
{
class SetupWindow;
}

class SetupWindow : public QWidget
{
  Q_OBJECT

public:
  explicit SetupWindow(QWidget *parent = nullptr);
  ~SetupWindow();

private slots:
  void on_createButton_clicked();

private:
  Ui::SetupWindow *ui;
};

#endif // SETUPWINDOW_H
