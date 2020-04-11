#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(User const &user, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->label->setText("Hello " + user.getUsername());
}

MainWindow::~MainWindow() { delete ui; }
