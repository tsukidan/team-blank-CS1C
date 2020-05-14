#ifndef MEMBER_H
#define MEMBER_H

#include <QDate>
#include <QSqlTableModel>
#include <QString>
#include <QtSql>
#include <iomanip>
#include <sstream>

class Member {
public:
  static bool setupTable(QSqlQuery &query);
  static void seedDB();
  static bool deleteById(int id);

  Member();
  Member(int id, QString name, bool executive, QDate expiration);
  Member(QSqlQuery &query);

  bool save();

  int getId() const;
  QString getName() const;
  bool isExecutive() const;
  QDate getExpiration() const;

private:
  int id;
  QString name;
  bool executive;
  QDate expiration;
};

#endif // MEMBER_H
