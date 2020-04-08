#include "dbutils.h"
#include "loginwindow.h"
#include "mainwindow.h"
#include "setupwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  LoginWindow loginWindow;
  SetupWindow setupWindow;
  MainWindow mainWindow;
  bool successful = false;

  if (!setupDB() && existingAdmin())
  {
    if (loginWindow.exec() == QDialog::Accepted)
    {
      successful = true;
    }
  }
  else
  {
    if (setupWindow.exec() == QDialog::Accepted)
    {
      successful = true;
    }
  }

  if (!successful)
  {
    return 0;
  }

  mainWindow.show();
  return a.exec();
}
