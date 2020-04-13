#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dayprocessortab.h"
#include "inventorylisttab.h"
#include "memberlisttab.h"
#include "user.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(User const &user, QWidget *parent = nullptr);
  ~MainWindow();

private slots:

  void on_tabWidget_currentChanged(int index);

private:
  Ui::MainWindow *ui;
  InventoryListTab *inventoryListTab;
  int previouslySelectedTab;
};
#endif // MAINWINDOW_H
