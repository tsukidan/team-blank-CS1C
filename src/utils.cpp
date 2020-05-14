#include "utils.h"

QString Utils::moneyDisplay(double cents) {
  return QString("$") + QString::number(cents / 100.0, 'f', 2);
}