#include "dbutils.h"

bool setupDB() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("storage.db");

  if (!db.open()) {
    qDebug() << "Can't Connect to DB!";
    return false;
  }

  QSqlQuery query;

  // Check to see if the customers table already exists
  query.prepare(
      "SELECT name FROM sqlite_master WHERE type='table' AND name='users'");

  if (!query.exec()) {
    qDebug() << "Failed to check if customers table exists: "
             << query.lastError().text();
    return false;
  }

  // If we get a result then we know the customers table exists
  if (query.next()) {
    qDebug() << "Database already setup";
    return false;
  }

  if (!User::setupTable(query)) {
    return false;
  }
  User::seedDB();
  if (!Member::setupTable(query)) {
    return false;
  }
  Member::seedDB();
  if (!Item::setupTable(query)) {
    return false;
  }
  if (!Purchase::setupTable(query)) {
    return false;
  }
  DayProcessing::setup(query);

  qDebug() << "Set up database";
  return true;
}

bool existingAdmin() {
  QSqlQuery query;

  // Check to see if the customers table already exists
  query.prepare("SELECT id FROM users WHERE admin=1");

  if (!query.exec()) {
    qDebug() << "Failed to search for existing admin: "
             << query.lastError().text();
    return false;
  }

  return query.next();
}
