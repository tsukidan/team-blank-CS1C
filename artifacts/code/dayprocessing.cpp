#include "dayprocessing.h"

void DayProcessing::setup(QSqlQuery &query) {
  QSqlDatabase::database().transaction();

  for (int i = 0; i < SeedData::DAYS_SIZE; i++) {
    for (int j = 0; j < SeedData::DAY_SIZES[i]; j++) {
      SeedData::Purchase seedPurchase = SeedData::DAYS[i][j];
      Item item;

      if (!Item::findByName(item, seedPurchase.itemName)) {
        item = Item(seedPurchase.itemName, seedPurchase.price * 100);
        item.save();
      }

      Purchase purchase(seedPurchase.memberId, item.getId(), seedPurchase.date,
                        seedPurchase.quantity);
      purchase.save();
    }
  }
  QSqlDatabase::database().commit();
}