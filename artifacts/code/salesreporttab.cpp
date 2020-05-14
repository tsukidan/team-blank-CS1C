#include "salesreporttab.h"
#include "ui_salesreporttab.h"

SalesReportTab::SalesReportTab(QWidget *parent)
    : QWidget(parent), ui(new Ui::SalesReportTab) {
  sortById = false;
  date = QDate();
  ui->setupUi(this);
}

SalesReportTab::~SalesReportTab() { delete ui; }

void SalesReportTab::selectMembers() {
  ui->memberList->clear();
  QSqlQuery query;

  QString queryText = "SELECT DISTINCT members.id, name FROM members "
                      "INNER JOIN "
                      "  purchases ON members.id = purchases.member_id "
                      "WHERE "
                      "  purchases.date = ? ";
  if (sortById) {
    queryText += "ORDER BY members.id ASC";
  } else {
    queryText += "ORDER BY name ASC";
  }

  query.prepare(queryText);
  query.addBindValue(date);

  if (!query.exec()) {
    qDebug() << "Failed select members for sales report: "
             << query.lastError().text();
    return;
  }

  while (query.next()) {
    int id = query.value(0).toInt();
    QString name = query.value(1).toString();

    ui->memberList->addItem(
        QString(sortById ? "%2 - %1" : "%1 - %2").arg(name).arg(id));
  }
}

void SalesReportTab::selectItems() {
  ui->itemList->clear();
  QSqlQuery query;

  query.prepare("SELECT DISTINCT"
                "    items.name,"
                "    SUM(purchases.quantity) * items.price AS revenue "
                "FROM items "
                "INNER JOIN purchases ON purchases.item_id = items.id "
                "GROUP BY items.id "
                "HAVING purchases.date = ?");
  query.addBindValue(date);

  if (!query.exec()) {
    qDebug() << "Failed select items for sales report: "
             << query.lastError().text();
    return;
  }

  while (query.next()) {
    QString name = query.value(0).toString();
    QString revenue = Utils::moneyDisplay(query.value(1).toInt());

    ui->itemList->addItem(QString("%1 - %2").arg(name).arg(revenue));
  }
}

void SalesReportTab::select() {
  if (date.isNull()) {
    return;
  }
  selectMembers();
  selectItems();
}

void SalesReportTab::on_dateSelect_userDateChanged(const QDate &date) {
  this->date = date;
  select();
}

void SalesReportTab::on_sortByComboBox_activated(int index) {
  switch (index) {
  case 0:
    if (sortById) {
      sortById = false;
      selectMembers();
    }
    break;
  case 1:
    if (!sortById) {
      sortById = true;
      selectMembers();
    }
    break;
  }
}
