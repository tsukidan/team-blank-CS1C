#include "dayprocessortab.h"
#include "ui_dayprocessortab.h"

DayProcessorTab::DayProcessorTab(QWidget *parent)
    : QWidget(parent), ui(new Ui::DayProcessorTab) {
  currentDay = 0;
  ui->setupUi(this);
}

DayProcessorTab::~DayProcessorTab() { delete ui; }

void DayProcessorTab::processCurrentDay() {
  for (int i = 0; i < DAY_SIZES[currentDay]; i++) {
    SeedData::Purchase seedPurchase = DAYS[currentDay][i];
    Item item;

    if (!Item::findByName(item, seedPurchase.itemName)) {
      item = Item(seedPurchase.itemName, seedPurchase.price * 100);
      item.save();
    }

    Purchase purchase(seedPurchase.memberId, item.getId(),
                      seedPurchase.quantity);
    purchase.save();
  }
}

void DayProcessorTab::on_nextDayButton_clicked() {
  if (currentDay >= DAYS_SIZE) {
    return;
  }
  currentDay++;
  ui->dayDisplay->setText(QString("Loading Day #%1...").arg(currentDay));
  ui->dayDisplay->repaint();
  processCurrentDay();
  ui->dayDisplay->setText(QString("Day #%1").arg(currentDay));
  if (currentDay >= DAYS_SIZE) {
    ui->nextDayButton->setEnabled(false);
  }
}
