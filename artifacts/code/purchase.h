#ifndef PURCHASE_H
#define PURCHASE_H

#include <QString>
#include <QtSql>

class Purchase {
public:
  static bool setupTable(QSqlQuery &query);
  static void seedDB();

  Purchase();
  Purchase(int memberId, int itemId, QDate date, int quantity);
  Purchase(QSqlQuery &query);

  bool save();

  int getId() const;
  int getMemberId() const;
  int getItemId() const;
  QDate getDate() const;
  int getQuantity() const;

private:
  int id;
  int memberId;
  int itemId;
  QDate date;
  int quantity;
};

#endif // PURCHASE_H
