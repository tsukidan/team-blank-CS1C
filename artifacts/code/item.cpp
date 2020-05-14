#include "item.h"

bool Item::setupTable(QSqlQuery &query) {
  query.prepare("CREATE TABLE items ("
                "  id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "  name TEXT NOT NULL UNIQUE,"
                "  price INTEGER NOT NULL"
                ")");
  if (!query.exec()) {
    qDebug() << "Failed to create users table: " << query.lastError().text();
    return false;
  }
  return true;
}

bool Item::findByName(Item &item, QString name) {
  QSqlQuery query;
  query.prepare("SELECT * FROM items WHERE name=?");
  query.addBindValue(name);

  if (!query.exec()) {
    qDebug() << "Failed to find item by name: " << query.lastError().text();
    return false;
  }

  if (!query.next()) {
    return false;
  }

  item = Item(query);

  return true;
}

bool Item::deleteById(int id) {
  QSqlQuery query;
  query.prepare("DELETE FROM items WHERE id=?");
  query.addBindValue(id);

  if (!query.exec()) {
    qDebug() << "Failed to delete item by id: " << query.lastError().text();
    return false;
  }

  return true;
}

Item::Item() {
  id = -1;
  name = "";
  price = -1;
}

Item::Item(QString name, int price) : name(name), price(price) { id = -1; }

Item::Item(QSqlQuery &query) {
  id = query.value(0).toInt();
  name = query.value(1).toString();
  price = query.value(2).toInt();
}

bool Item::save() {
  QSqlQuery query;

  if (id == -1) {
    query.prepare("INSERT INTO items (name, price)"
                  "VALUES (?, ?)");
  } else {
    query.prepare("REPLACE INTO items (id, name, price)"
                  "VALUES (?, ?, ?)");
    query.addBindValue(id);
  }
  query.addBindValue(name);
  query.addBindValue(price);

  if (!query.exec()) {
    qDebug() << "Failed to save item: " << query.lastError().text();
    return false;
  }

  id = query.lastInsertId().toInt();
  return true;
}

bool Item::remove() {
  if (id == -1) {
    qDebug() << "Error: Trying to delete item that isn't in the database";
  }
  return deleteById(id);
}

int Item::getId() const { return id; }
QString Item::getName() const { return name; }
int Item::getPrice() const { return price; }

void Item::setId(int id) { this->id = id; }
void Item::setName(QString name) { this->name = name; }
void Item::setPrice(int price) { this->price = price; }