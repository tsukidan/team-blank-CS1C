#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QtSql>

class Item {
public:
  static bool setupTable(QSqlQuery &query);
  static void seedDB();
  static bool findByName(Item &item, QString name);
  static bool deleteById(int id);

  Item();
  Item(QString name, int price);
  Item(QSqlQuery &query);

  bool save();
  bool remove();

  int getId() const;
  QString getName() const;
  int getPrice() const;

  void setId(int id);
  void setName(QString name);
  void setPrice(int price);

private:
  int id;
  QString name;
  int price;
};

#endif // ITEM_H
