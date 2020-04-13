#include "purchase.h"

bool Purchase::setupTable(QSqlQuery &query) {
  query.prepare("CREATE TABLE purchases ("
                "  id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "  member_id INTEGER NOT NULL REFERENCES members(id),"
                "  item_id INTEGER NOT NULL REFERENCES items(id),"
                "  quantity INTEGER NOT NULL"
                ")");
  if (!query.exec()) {
    qDebug() << "Failed to create purchases table: "
             << query.lastError().text();
    return false;
  }
  return true;
}

Purchase::Purchase() {
  id = -1;
  memberId = -1;
  itemId = -1;
  quantity = -1;
}

Purchase::Purchase(int memberId, int itemId, int quantity)
    : memberId(memberId), itemId(itemId), quantity(quantity) {
  id = -1;
}

bool Purchase::save() {
  QSqlQuery query;

  query.prepare("REPLACE INTO purchases (id, member_id, item_id, quantity)"
                "VALUES (?, ?, ?, ?)");
  query.addBindValue(id);
  query.addBindValue(memberId);
  query.addBindValue(itemId);
  query.addBindValue(quantity);

  if (!query.exec()) {
    qDebug() << "Failed to save purchase: " << query.lastError().text();
    return false;
  }

  id = query.lastInsertId().toInt();
  return true;
}

int Purchase::getId() const { return id; }
int Purchase::getMemberId() const { return memberId; }
int Purchase::getItemId() const { return itemId; }
int Purchase::getQuantity() const { return quantity; }