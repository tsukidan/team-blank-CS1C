#ifndef DAYPROCESSOR_H
#define DAYPROCESSOR_H

#include "item.h"
#include "purchase.h"
#include "seedData.h"
#include <QWidget>

namespace Ui {
class DayProcessorTab;
}

class DayProcessorTab : public QWidget {
  Q_OBJECT

public:
  explicit DayProcessorTab(QWidget *parent = nullptr);
  ~DayProcessorTab();

  void processCurrentDay();

private slots:
  void on_nextDayButton_clicked();

private:
  static const int DAYS_SIZE = 7;
  const int DAY_SIZES[DAYS_SIZE] = {
      SeedData::DAY1_SIZE, SeedData::DAY2_SIZE, SeedData::DAY3_SIZE,
      SeedData::DAY4_SIZE, SeedData::DAY5_SIZE, SeedData::DAY6_SIZE,
      SeedData::DAY7_SIZE,
  };
  const SeedData::Purchase *DAYS[DAYS_SIZE] = {
      SeedData::DAY1, SeedData::DAY2, SeedData::DAY3, SeedData::DAY4,
      SeedData::DAY5, SeedData::DAY6, SeedData::DAY7};

  Ui::DayProcessorTab *ui;
  int currentDay;
};

#endif // DAYPROCESSOR_H
