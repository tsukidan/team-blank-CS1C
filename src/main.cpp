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
    if (loginWindow.exec() == QDialog::Rejected)
    {
      return 0;
    }
  }
  else
  {
    if (setupWindow.exec() == QDialog::Rejected)
    {
      return 0;
    }
  }

  mainWindow.show();
  return a.exec();
}
