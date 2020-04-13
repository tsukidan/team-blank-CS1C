#include "user.h"

bool User::setupTable(QSqlQuery &query) {
  query.prepare("CREATE TABLE users ("
                "  id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "  username TEXT NOT NULL,"
                "  password TEXT NOT NULL,"
                "  admin BOOLEAN"
                ")");
  if (!query.exec()) {
    qDebug() << "Failed to create users table: " << query.lastError().text();
    return false;
  }
  return true;
}

bool User::findByUsername(User &user, QString username) {
  QSqlQuery query;
  query.prepare("SELECT * FROM users WHERE username=?");
  query.addBindValue(username);

  if (!query.exec()) {
    qDebug() << "Failed to find user by username: " << query.lastError().text();
    return false;
  }

  if (!query.next()) {
    return false;
  }

  user = User(query);

  return true;
}

User::User() {
  id = -1;
  username = "";
  password = "";
  admin = false;
}

User::User(QString username, QString password, bool admin)
    : username(username), password(password), admin(admin) {
  id = -1;
}

User::User(QSqlQuery &query) {
  id = query.value(0).toInt();
  username = query.value(1).toString();
  password = query.value(2).toString();
  admin = query.value(3).toBool();
}

bool User::save()
{
  QSqlQuery query;

  if (id != -1) {
    query.prepare("UPDATE users"
                  "SET username=?, password=?, admin=?"
                  "WHERE id=?");
    query.bindValue(3, id);
  }
  else
  {
    query.prepare("INSERT INTO users (username, password, admin)"
                  "VALUES (?, ?, ?)");
  }

  query.addBindValue(username);
  query.addBindValue(password);
  query.addBindValue(admin);

  if (!query.exec())
  {
    qDebug() << "Failed to save user: " << query.lastError().text();
    return false;
  }

  id = query.lastInsertId().toInt();
  return true;
}

int User::getId() const { return id; }
QString User::getUsername() const { return username; }
QString User::getPassword() const { return password; }
bool User::isAdmin() const { return admin; }
