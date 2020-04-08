#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginWindow)
{
  ui->setupUi(this);
}

LoginWindow::~LoginWindow() { delete ui; }

User LoginWindow::getUser()
{
  return user;
}

void LoginWindow::on_loginButton_clicked()
{
  User user;
  QString username = ui->usernameLineEdit->text();
  QString password = ui->passwordLineEdit->text();

  if (User::findByUsername(user, username) && user.getUsername() == username)
  {
    this->user = user;
    accept();
    return;
  }

  QMessageBox::warning(this, "Login", "Username and Password are incorrect");
}
