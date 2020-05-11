#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(User const &user, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  memberListTab = new MemberListTab(user);
  inventoryListTab = new InventoryListTab(user);
  Salesreport *a = new Salesreport;

  ui->setupUi(this);
  ui->tabWidget->insertTab(0, memberListTab, "Members");
  ui->tabWidget->insertTab(1, inventoryListTab, "Inventory");
  ui->tabWidget->insertTab(2, a, "Sales Report");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_tabWidget_currentChanged(int index) {
  switch (index) {
  case 0: {
    memberListTab->refresh();
  }
  case 1: {
    inventoryListTab->refresh();
  }
  }
}
