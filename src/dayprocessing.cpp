#include "dayprocessing.h"

bool DayProcessing::setup(QSqlQuery &query) {
  query.prepare("CREATE TABLE daycounter ("
                "  id INTEGER PRIMARY KEY,"
                "  current_day INTEGER NOT NULL"
                ")");
  if (!query.exec()) {
    qDebug() << "Failed to create daycounter table: "
             << query.lastError().text();
    return false;
  }
  query.prepare("INSERT INTO daycounter (id, current_day) VALUES (0, 0)");
  if (!query.exec()) {
    qDebug() << "Failed to create daycounter: " << query.lastError().text();
    return false;
  }
  return true;
}

int DayProcessing::currentDay() {
  QSqlQuery query;
  query.prepare("SELECT current_day FROM daycounter WHERE id = 0");

  if (!query.exec() || !query.next()) {
    qDebug() << "Failed to select current day: " << query.lastError().text();
    return -1;
  }

  return query.value(0).toInt();
}

bool DayProcessing::incrementCurrentDay() {
  QSqlQuery query;

  query.prepare(
      "UPDATE daycounter SET current_day = current_day + 1 WHERE id = 0");

  if (!query.exec()) {
    qDebug() << "Failed to increment current day: " << query.lastError().text();
    return false;
  }
  return true;
}

void DayProcessing::processDay(int day) {
  for (int i = 0; i < SeedData::DAY_SIZES[day]; i++) {
    SeedData::Purchase seedPurchase = SeedData::DAYS[day][i];
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
void DayProcessing::processCurrentDay() {
  int currentDay = DayProcessing::currentDay();
  processDay(currentDay);
  incrementCurrentDay();
}
