#include "booleancomboboxdelegate.h"

BooleanComboBoxDelegate::BooleanComboBoxDelegate(QString truthy, QString falsey,
                                                 QObject *parent)
    : QItemDelegate(parent), truthyText(truthy), falseyText(falsey) {}

QWidget *
BooleanComboBoxDelegate::createEditor(QWidget *parent,
                                      const QStyleOptionViewItem &option,
                                      const QModelIndex &index) const {

  QComboBox *comboBox = new QComboBox;
  comboBox->insertItem(0, truthyText, true);
  comboBox->insertItem(1, falseyText, false);
  return comboBox;
}

void BooleanComboBoxDelegate::setEditorData(QWidget *editor,
                                            const QModelIndex &index) const {
  bool value = index.model()->data(index, Qt::EditRole).toBool();

  QComboBox *comboBox = static_cast<QComboBox *>(editor);
  comboBox->setCurrentIndex(!value);
}

void BooleanComboBoxDelegate::setModelData(QWidget *editor,
                                           QAbstractItemModel *model,
                                           const QModelIndex &index) const {
  QComboBox *comboBox = static_cast<QComboBox *>(editor);
  bool value = comboBox->currentData().toBool();
  model->setData(index, value);
}

void BooleanComboBoxDelegate::updateEditorGeometry(
    QWidget *editor, const QStyleOptionViewItem &option,
    const QModelIndex &index) const {
  editor->setGeometry(option.rect);
}