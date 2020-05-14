#ifndef BOOLEANCOMBOBOXDELEGATE_H
#define BOOLEANCOMBOBOXDELEGATE_H

#include <QComboBox>
#include <QItemDelegate>

class BooleanComboBoxDelegate : public QItemDelegate {
  Q_OBJECT
public:
  explicit BooleanComboBoxDelegate(QString truthy, QString falsey,
                                   QObject *parent = nullptr);

  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const;

  void setEditorData(QWidget *editor, const QModelIndex &index) const;

  void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const;

  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                            const QModelIndex &index) const;

private:
  QString truthyText;
  QString falseyText;
};

#endif // BOOLEANCOMBOBOXDELEGATE_H
