#include "setupwindow.h"
#include "ui_setupwindow.h"

SetupWindow::SetupWindow(QWidget *parent) : QWidget(parent),
                                            ui(new Ui::SetupWindow)
{
  ui->setupUi(this);
}

SetupWindow::~SetupWindow()
{
  delete ui;
}

void SetupWindow::on_createButton_clicked()
{
  QString username = ui->usernameLineEdit->text();
  QString password = ui->passwordLineEdit->text();
  QString confirmPassword = ui->confirmPasswordLineEdit->text();

  if (username.isEmpty() || password.isEmpty())
  {
    QMessageBox::warning(this, "Setup", "No fields should be empty");
    return;
  }
  if (password != confirmPassword)
  {
    QMessageBox::warning(this, "Setup", "Passwords don't match");
    return;
  }

  User admin(username, password, true);
  if (!admin.save()) {
    QMessageBox::warning(this, "Setup", "Couldn't save admin");
    return;
  }

  close();
}
