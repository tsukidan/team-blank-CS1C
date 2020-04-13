#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QtSql>

class Item {
public:
  static bool setupTable(QSqlQuery &query);
  static void seedDB();
  static bool findByName(Item &item, QString name);

  Item();
  Item(QString name, int price);
  Item(QSqlQuery &query);

  bool save();

  int getId() const;
  QString getName() const;
  int getPrice() const;

private:
  int id;
  QString name;
  int price;
};

#endif // ITEM_H
