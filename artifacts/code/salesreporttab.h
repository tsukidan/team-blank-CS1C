#ifndef SALESREPORTTAB_H
#define SALESREPORTTAB_H

#include "inventorymodel.h"
#include "membersmodel.h"
#include <QWidget>

namespace Ui {
class SalesReportTab;
}

class SalesReportTab : public QWidget {
  Q_OBJECT

public:
  explicit SalesReportTab(QWidget *parent = nullptr);
  ~SalesReportTab();

  void select();

private slots:
  void on_dateSelect_userDateChanged(const QDate &date);

  void on_sortByComboBox_activated(int index);

private:
  void selectMembers();
  void selectItems();

  Ui::SalesReportTab *ui;
  bool sortById;
  QDate date;
};

#endif // SALESREPORTTAB_H
