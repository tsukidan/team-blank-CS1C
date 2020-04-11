#ifndef SEEDING_H
#define SEEDING_H

#include "member.h"
#include <QDate>

namespace SeedData {
const int MEMERS_SIZE = 15;
const Member MEMBERS[MEMERS_SIZE] = {
    Member(12897, "Fred Frugal", true, QDate(2020, 12, 15)),
    Member(44444, "Larry Largefamily", false, QDate(2020, 10, 1)),
    Member(12345, "Sally Shopper", false, QDate(2020, 8, 1)),
    Member(35647, "Linda Livesalone", true, QDate(2020, 12, 15)),
    Member(31311, "Sam Single", true, QDate(2020, 12, 5)),
    Member(96309, "Mary IsHappy", true, QDate(2020, 12, 5)),
    Member(12121, "Harry Havealotsofkids", true, QDate(2020, 12, 30)),
    Member(77777, "Sam Spendstomuch ", true, QDate(2020, 11, 15)),
    Member(16161, "Benjamin BusinessShopper", false, QDate(2020, 11, 20)),
    Member(61616, "Sally SuperShopper", false, QDate(2021, 3, 20)),
    Member(56723, "Sue Shoparound", true, QDate(2020, 3, 21)),
    Member(67899, "BulkClub Bob", false, QDate(2020, 10, 22)),
    Member(88888, "Carrie CaresAboutMoney", true, QDate(2020, 10, 22)),
    Member(12899, "Johnny Shopper", false, QDate(2020, 10, 4)),
    Member(67890, "Betty Buysalot", false, QDate(2021, 3, 12))};
} // namespace SeedData

#endif // SEEDING_H
