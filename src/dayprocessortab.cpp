#include "dayprocessortab.h"
#include "ui_dayprocessortab.h"

DayProcessorTab::DayProcessorTab(QWidget *parent)
    : QWidget(parent), ui(new Ui::DayProcessorTab) {
  ui->setupUi(this);
  int currentDay = DayProcessing::currentDay();

  updateDisplay(currentDay);
  if (currentDay >= SeedData::DAYS_SIZE) {
    ui->nextDayButton->setEnabled(false);
  }
}

DayProcessorTab::~DayProcessorTab() { delete ui; }

void DayProcessorTab::updateDisplay(int day) {
  int currentDay = DayProcessing::currentDay();
  ui->dayDisplay->setText(QString("Day #%1").arg(currentDay));
}

void DayProcessorTab::on_nextDayButton_clicked() {
  int currentDay = DayProcessing::currentDay() + 1;

  ui->dayDisplay->setText(QString("Loading Day #%1...").arg(currentDay));
  ui->dayDisplay->repaint();
  DayProcessing::processCurrentDay();

  updateDisplay(currentDay);

  if (currentDay >= SeedData::DAYS_SIZE) {
    ui->nextDayButton->setEnabled(false);
  }
}
