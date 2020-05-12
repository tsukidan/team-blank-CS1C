#include "salesreport.h"
#include "ui_salesreport.h"

Salesreport::Salesreport(QWidget *parent)
    : QWidget(parent), ui(new Ui::Salesreport) {
  ui->setupUi(this);
  QSqlQueryModel *model = new QSqlQueryModel;
  QSqlQuery query;

  query.prepare(
      "SELECT items.name, (items.price/100.0), purchases.quantity, "
      "(purchases.quantity * ((items.price + items.price * 0.0775) / 100.0)) "
      "AS "
      "revenue FROM items INNER "
      "JOIN purchases ON purchases.item_id=items.id WHERE purchases.date=?");
  query.addBindValue((ui->dateEdit->date()).toString("yyyy-MM-dd"));
  if (!query.exec()) {
    qDebug() << "Query Fail" << query.lastError().text();
    return;
  }
  double totalRev = 0;
  int qtyBought = 0;
  while (query.next()) {
    totalRev += query.value(3).toDouble();
    qtyBought += query.value(2).toInt();
  }

  model->setQuery(query);
  model->setHeaderData(0, Qt::Horizontal, tr("Name"));
  model->setHeaderData(1, Qt::Horizontal, tr("Price"));
  model->setHeaderData(2, Qt::Horizontal, tr("Quantity"));
  model->setHeaderData(3, Qt::Horizontal, tr("Revenue"));
  ui->salestable->setModel(model);

  updateMembers();

  ui->revenue->setText(QString("Total Daily Revenue $%1").arg(totalRev));
  ui->itemsBought->setText(QString("Items Purchased %1").arg(qtyBought));
  ui->memberList->show();
  ui->salestable->show();
}

void Salesreport::updateMembers() {
  QSqlQueryModel *model2 = new QSqlQueryModel;
  QSqlQuery query;
  query.prepare(
      "SELECT DISTINCT members.id, members.name, members.executive FROM "
      "members INNER JOIN "
      "purchases ON purchases.member_id=members.id WHERE purchases.date=?");
  query.addBindValue((ui->dateEdit->date()).toString("yyyy-MM-dd"));
  if (!query.exec()) {
    qDebug() << "Query Fail member list" << query.lastError().text();
    return;
  }
  int numStandard = 0;
  int numExecutive = 0;
  while (query.next()) {
    (query.value(2) == true ? numExecutive++ : numStandard++);
  }
  model2->setQuery(query);
  model2->setHeaderData(0, Qt::Horizontal, tr("ID"));
  model2->setHeaderData(1, Qt::Horizontal, tr("Name"));
  model2->setHeaderData(2, Qt::Horizontal, tr("Executive"));
  ui->memberList->setModel(model2);
  ui->numStan->setText(QString("%1 Standard Members Shopped").arg(numStandard));
  ui->numExec->setText(
      QString("%1 Executive Members Shoped").arg(numExecutive));
}

Salesreport::~Salesreport() { delete ui; }

void Salesreport::on_filterType_stateChanged(int checked) {
  if (checked == 0) {
    ui->memberType->setEnabled(false);
    on_dateEdit_dateChanged(ui->dateEdit->date());
    return;
  } else {
    ui->memberType->setEnabled(true);
    on_memberType_currentIndexChanged(ui->memberType->currentIndex());
    return;
  }
}

void Salesreport::on_dateEdit_dateChanged(const QDate &date) {
  QSqlQueryModel *model = new QSqlQueryModel;
  QSqlQuery query;
  if (ui->filterType->isChecked()) {
    on_memberType_currentIndexChanged(ui->memberType->currentIndex());
    return;
  }
  query.prepare(
      "SELECT items.name, (items.price/100.0), purchases.quantity, "
      "(purchases.quantity * ((items.price + items.price * 0.0775) / 100.0)) "
      "AS "
      "revenue FROM items INNER "
      "JOIN purchases ON purchases.item_id=items.id WHERE purchases.date=?");
  query.addBindValue(date.toString("yyyy-MM-dd"));
  if (!query.exec()) {
    qDebug() << "IN DATE CHANGE fail query";
  }

  double totalRev = 0;
  int qtyBought = 0;
  while (query.next()) {
    totalRev += query.value(3).toDouble();
    qtyBought += query.value(4).toInt();
  }

  model->setQuery(query);
  model->setHeaderData(0, Qt::Horizontal, tr("Name"));
  model->setHeaderData(1, Qt::Horizontal, tr("Price"));
  model->setHeaderData(2, Qt::Horizontal, tr("Quantity"));
  model->setHeaderData(3, Qt::Horizontal, tr("Revenue"));

  updateMembers();

  ui->salestable->setModel(model);
  ui->revenue->setText(QString("Total Daily Revenue $%1").arg(totalRev));
  ui->salestable->show();
}

void Salesreport::on_memberType_currentIndexChanged(int index) {
  QSqlQueryModel *model = new QSqlQueryModel;
  QSqlQuery query;
  switch (index) {
  case 1:
    query.prepare(
        "SELECT items.name, (items.price/100.0), purchases.quantity, "
        "(purchases.quantity * ((items.price + items.price * 0.0775) / 100.0)) "
        "AS revenue FROM items "
        "INNER JOIN members ON purchases.member_id=members.id INNER JOIN "
        "purchases ON purchases.item_id=items.id WHERE purchases.date=? AND "
        "members.executive=false");
    break;
  case 0:
    query.prepare(
        "SELECT items.name, (items.price/100.0), purchases.quantity, "
        "(purchases.quantity * ((items.price + items.price * 0.0775) / 100.0)) "
        "AS revenue FROM items "
        "INNER JOIN members ON purchases.member_id=members.id INNER JOIN "
        "purchases ON purchases.item_id=items.id WHERE purchases.date=? AND "
        "members.executive=true");
    break;
  default:
    break;
  }
  query.addBindValue((ui->dateEdit->date()).toString("yyyy-MM-dd"));
  if (!query.exec()) {
    qDebug() << "IN DATE CHANGE SUCCESSFUL QUERY EXEC";
  }

  double totalRev = 0;
  int qtyBought = 0;
  while (query.next()) {
    totalRev += query.value(3).toDouble();
    qtyBought += query.value(4).toInt();
  }

  model->setQuery(query);
  model->setHeaderData(0, Qt::Horizontal, tr("Name"));
  model->setHeaderData(1, Qt::Horizontal, tr("Price"));
  model->setHeaderData(2, Qt::Horizontal, tr("Quantity"));
  model->setHeaderData(3, Qt::Horizontal, tr("Revenue"));

  ui->salestable->setModel(model);
  ui->revenue->setText(QString("Total Daily Revenue $%1").arg(totalRev));
  ui->salestable->show();
}
