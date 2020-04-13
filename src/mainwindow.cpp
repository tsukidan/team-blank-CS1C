#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(User const &user, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  MemberListTab *memberListTab = new MemberListTab;

  ui->setupUi(this);
  ui->tabWidget->insertTab(0, memberListTab, "Members");

  if (user.isAdmin()) {
    DayProcessorTab *dayProcessorTab = new DayProcessorTab;
    ui->tabWidget->insertTab(1, dayProcessorTab, "Day Processor");
  }
}

MainWindow::~MainWindow() { delete ui; }
