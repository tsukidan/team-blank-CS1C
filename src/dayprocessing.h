#ifndef DAYPROCESSING_H
#define DAYPROCESSING_H

#include "item.h"
#include "purchase.h"
#include "seedData.h"
#include <QString>
#include <QtSql>

namespace DayProcessing {
void setup(QSqlQuery &query);
}; // namespace DayProcessing

#endif // DAYPROCESSING_H
