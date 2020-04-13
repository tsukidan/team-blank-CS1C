#ifndef DAYPROCESSOR_H
#define DAYPROCESSOR_H

#include "dayprocessing.h"
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

  void updateDisplay(int currentDay);

private slots:
  void on_nextDayButton_clicked();

private:
  Ui::DayProcessorTab *ui;
};

#endif // DAYPROCESSOR_H
