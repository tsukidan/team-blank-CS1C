#ifndef CREATEPURCHASEDIALOG_H
#define CREATEPURCHASEDIALOG_H

#include "purchase.h"
#include "utils.h"
#include <QDialog>

namespace Ui {
class CreatePurchaseDialog;
}

class CreatePurchaseDialog : public QDialog {
  Q_OBJECT

public:
  explicit CreatePurchaseDialog(QWidget *parent = nullptr);
  ~CreatePurchaseDialog();

  Purchase getPurchase() const;

private slots:
  void on_CreatePurchaseDialog_accepted();

private:
  Ui::CreatePurchaseDialog *ui;
  Purchase purchase;
};

#endif // CREATEPURCHASEDIALOG_H
