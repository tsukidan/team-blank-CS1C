#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(User const &user, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  MemberListTab *memberListTab = new MemberListTab;
  InventoryListTab *inventoryListTab = new InventoryListTab;

  ui->setupUi(this);
  ui->tabWidget->insertTab(0, memberListTab, "Members");
  ui->tabWidget->insertTab(1, inventoryListTab, "Inventory");
}

MainWindow::~MainWindow() { delete ui; }
