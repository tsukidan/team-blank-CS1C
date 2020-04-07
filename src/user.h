#ifndef USER_H
#define USER_H

#include <QString>
#include <QtSql>

class User
{
public:
  class ExistingUsername
  {
  };

  static bool setupTable(QSqlQuery &query);

  User();
  User(QString username, QString password, bool admin);

  bool save();

private:
  int id;
  QString username;
  QString password;
  bool admin;
};

#endif // USER_H
