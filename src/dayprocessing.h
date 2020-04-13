#ifndef DAYPROCESSING_H
#define DAYPROCESSING_H

#include "item.h"
#include "purchase.h"
#include "seedData.h"
#include <QString>
#include <QtSql>

namespace DayProcessing {
bool setup(QSqlQuery &query);
int currentDay();
bool incrementCurrentDay();
void processDay(int day);
void processCurrentDay();
}; // namespace DayProcessing

#endif // DAYPROCESSING_H
