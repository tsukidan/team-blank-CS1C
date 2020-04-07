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

  if (!setupDB() && existingAdmin())
  {
    loginWindow.show();
  }
  else
  {
    setupWindow.show();
  }

  return QApplication::exec();
}
