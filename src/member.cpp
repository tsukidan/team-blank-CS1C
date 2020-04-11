#include "member.h"
#include "seedData.h"

bool Member::setupTable(QSqlQuery &query) {
  query.prepare("CREATE TABLE members ("
                "  id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "  name TEXT NOT NULL,"
                "  executive BOOLEAN NOT NULL,"
                "  expiration DATE NOT NULL,"
                "  rebate INTEGER NOT NULL"
                ")");
  if (!query.exec()) {
    qDebug() << "Failed to create members table: " << query.lastError().text();
    return false;
  }
  return true;
}

void Member::seedDB() {
  for (int i = 0; i < SeedData::MEMERS_SIZE; i++) {
    Member member(SeedData::MEMBERS[i]);

    member.save();
  }
}

Member::Member() {
  id = -1;
  name = "";
  executive = false;
  expiration = QDate();
  rebate = 0;
}

Member::Member(int id, QString name, bool executive, QDate expiration,
               int rebate)
    : id(id), name(name), executive(executive), expiration(expiration),
      rebate(rebate) {}

Member::Member(QSqlQuery &query) {
  id = query.value(0).toInt();
  name = query.value(1).toString();
  executive = query.value(2).toBool();
  expiration = query.value(3).toDate();
  rebate = query.value(4).toInt();
}

bool Member::save() {
  QSqlQuery query;

  query.prepare("REPLACE INTO members (id, name, "
                " executive, expiration, rebate)"
                "VALUES (?, ?, ?, ?, ?)");
  query.addBindValue(id);
  query.addBindValue(name);
  query.addBindValue(executive);
  query.addBindValue(expiration);
  query.addBindValue(rebate);

  if (!query.exec()) {
    qDebug() << "Failed to save member: " << query.lastError().text();
    return false;
  }

  id = query.lastInsertId().toInt();
  return true;
}

int Member::getId() const { return id; }
QString Member::getName() const { return name; }
bool Member::isExecutive() const { return executive; }
QDate Member::getExpiration() const { return expiration; }
int Member::getRebate() const { return rebate; }