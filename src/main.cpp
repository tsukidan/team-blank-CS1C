#include <QApplication>

#include "dbutils.h"
#include "loginwindow.h"
#include "mainwindow.h"
#include "setupwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  LoginWindow loginWindow;
  SetupWindow setupWindow;
  bool successful = false;
  User user;

  if (!setupDB() && existingAdmin()) {
    if (loginWindow.exec() == QDialog::Rejected) {
      return 0;
    }
    user = loginWindow.getUser();
  } else {
    if (setupWindow.exec() == QDialog::Rejected) {
      return 0;
    }
    user = setupWindow.getUser();
  }
  MainWindow mainWindow(user);

  mainWindow.show();
  return a.exec();
}
