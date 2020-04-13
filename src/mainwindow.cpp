#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(User const &user, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  MemberListTab *memberListTab = new MemberListTab;
  inventoryListTab = new InventoryListTab;

  ui->setupUi(this);
  ui->tabWidget->insertTab(0, memberListTab, "Members");
  ui->tabWidget->insertTab(1, inventoryListTab, "Inventory");

  if (user.isAdmin()) {
    DayProcessorTab *dayProcessorTab = new DayProcessorTab;
    ui->tabWidget->insertTab(2, dayProcessorTab, "Day Processor");
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_tabWidget_currentChanged(int index) {
  if (previouslySelectedTab == 2) {
    inventoryListTab->reload();
  }
  previouslySelectedTab = index;
}
