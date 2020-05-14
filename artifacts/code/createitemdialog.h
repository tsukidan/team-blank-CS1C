#ifndef CREATEITEMDIALOG_H
#define CREATEITEMDIALOG_H

#include "item.h"
#include <QDialog>

namespace Ui {
class CreateItemDialog;
}

class CreateItemDialog : public QDialog {
  Q_OBJECT

public:
  explicit CreateItemDialog(QWidget *parent = nullptr);
  ~CreateItemDialog();
  Item getItem();

private slots:
  void on_buttonBox_accepted();

private:
  Ui::CreateItemDialog *ui;
  Item item;
};

#endif // CREATEITEMDIALOG_H
