#include "purchase.h"

bool Purchase::setupTable(QSqlQuery &query) {
  query.prepare("CREATE TABLE purchases ("
                "  id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "  member_id INTEGER NOT NULL REFERENCES members(id),"
                "  item_id INTEGER NOT NULL REFERENCES items(id),"
                "  date DATE NOT NULL,"
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
  date = QDate();
  quantity = -1;
}

Purchase::Purchase(int memberId, int itemId, QDate date, int quantity)
    : memberId(memberId), itemId(itemId), date(date), quantity(quantity) {
  id = -1;
}

bool Purchase::save() {
  QSqlQuery query;

  if (id == -1) {
    query.prepare("INSERT INTO purchases (member_id, item_id, date, quantity)"
                  "VALUES (?, ?, ?, ?)");
  } else {
    query.prepare(
        "REPLACE INTO purchases (id, member_id, item_id, date, quantity)"
        "VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(id);
  }
  query.addBindValue(memberId);
  query.addBindValue(itemId);
  query.addBindValue(date);
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
QDate Purchase::getDate() const { return date; }
int Purchase::getQuantity() const { return quantity; }