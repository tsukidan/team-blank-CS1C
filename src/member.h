#ifndef MEMBER_H
#define MEMBER_H

#include <QDate>
#include <QString>
#include <QtSql>
#include <iomanip>
#include <sstream>
#include <QSqlTableModel>

class Member {
public:
  static bool setupTable(QSqlQuery &query);
  static void seedDB();
  static bool deleteById(int id);

  Member();
  Member(int id, QString name, bool executive, QDate expiration,
         int rebate = 0);
  Member(QSqlQuery &query);

  bool save();

  int     getId()         const;
  QString getName()       const;
  bool    isExecutive()   const;
  QDate   getExpiration() const;
  int     getRebate()     const;

private:
  int id;
  QString name;
  bool executive;
  QDate expiration;
  int rebate;
};

#endif // MEMBER_H
