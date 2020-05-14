#ifndef SEEDDATA_H
#define SEEDDATA_H

#include "member.h"
#include <QDate>

namespace SeedData {
struct Purchase {
  QDate date;
  int memberId;
  QString itemName;
  float price;
  int quantity;
};

const int DAY1_SIZE = 13;
const Purchase DAY1[DAY1_SIZE] = {
    {QDate(2020, 3, 12), 67890, "1 gallon milk", 6.49, 20},
    {QDate(2020, 3, 12), 67899, "Rye Bread", 4.79, 5},
    {QDate(2020, 3, 12), 12899, "Steak", 8.86, 12},
    {QDate(2020, 3, 12), 12899, "Pork Tenderloin", 13.75, 3},
    {QDate(2020, 3, 12), 12345, "Shrek 3", 19.95, 1},
    {QDate(2020, 3, 12), 12345, "Jay Leno Collection DVDs", 39.95, 10},
    {QDate(2020, 3, 12), 67899, "The Alamo", 19.95, 6},
    {QDate(2020, 3, 12), 67899, "Most Basic DVD Player", 59.99, 1},
    {QDate(2020, 3, 12), 12345, "EPSON Printer", 59.99, 20},
    {QDate(2020, 3, 12), 88888, "EPSON Printer Cart.", 32.50, 50},
    {QDate(2020, 3, 12), 67899, "Starbux Coffee", 7.75, 4},
    {QDate(2020, 3, 12), 12899, "Paper Shredder", 199.99, 25},
    {QDate(2020, 3, 12), 56723, "Envelops", 2.99, 5},
};

const int DAY2_SIZE = 12;
const Purchase DAY2[DAY2_SIZE] = {
    {QDate(2020, 3, 13), 61616, "1 gallon milk", 6.49, 66},
    {QDate(2020, 3, 13), 77777, "Wonder Bread", 1.29, 7},
    {QDate(2020, 3, 13), 77777, "1.5 Dozen eggs", 4.0, 29},
    {QDate(2020, 3, 13), 35647, "Hamburger", 7.25, 1},
    {QDate(2020, 3, 13), 31311, "The Bourne Supremacy", 19.95, 4},
    {QDate(2020, 3, 13), 12121, "Toilet Paper", 11.75, 1},
    {QDate(2020, 3, 13), 67899, "Ponds Lotion", 5.79, 1},
    {QDate(2020, 3, 13), 61616, "VCR/DVD Player", 89.99, 1},
    {QDate(2020, 3, 13), 61616, "Levi 501s", 21.50, 4},
    {QDate(2020, 3, 13), 12345, "Farberware Cookware Set", 289.99, 20},
    {QDate(2020, 3, 13), 61616, "Coffee Creamer", 5.75, 5},
    {QDate(2020, 3, 13), 12345, "Legal Pads", 6.25, 10},
};

const int DAY3_SIZE = 10;
const Purchase DAY3[DAY3_SIZE] = {
    {QDate(2020, 3, 14), 12345, "1 gallon milk", 6.49, 6},
    {QDate(2020, 3, 14), 12345, "Assorted Muffins", 5.89, 2},
    {QDate(2020, 3, 14), 88888, "Home On The Range", 19.98, 4},
    {QDate(2020, 3, 14), 77777, "Disney DVD Collection", 49.95, 55},
    {QDate(2020, 3, 14), 88888, "A Bug's Life", 9.95, 1},
    {QDate(2020, 3, 14), 77777, "The Princess Bride", 17.75, 16},
    {QDate(2020, 3, 14), 61616, "All Laundry Detergent", 7.99, 22},
    {QDate(2020, 3, 14), 35647, "Pringles", 6.99, 8},
    {QDate(2020, 3, 14), 12121, "Levi 501s", 21.50, 10},
    {QDate(2020, 3, 14), 12345, "diet Coke", 6.79, 26},
};

const int DAY4_SIZE = 12;
const Purchase DAY4[DAY4_SIZE] = {
    {QDate(2020, 3, 15), 12345, "1 gallon milk", 6.49, 2},
    {QDate(2020, 3, 15), 12345, "Assorted Muffins", 5.89, 4},
    {QDate(2020, 3, 15), 77777, "Rack of Lamb", 14.79, 4},
    {QDate(2020, 3, 15), 88888, "Foster Farms Whole Chicken", 11.75, 2},
    {QDate(2020, 3, 15), 61616, "Spiderman 2", 19.95, 1},
    {QDate(2020, 3, 15), 61616, "While You Were Sleeping", 17.75, 1},
    {QDate(2020, 3, 15), 12345, "Cheer Laundry Detergent", 7.99, 1},
    {QDate(2020, 3, 15), 67899, "Bkfst Cereal Variety Pack", 7.29, 4},
    {QDate(2020, 3, 15), 12345, "Disney DVD Collection 2", 59.99, 1},
    {QDate(2020, 3, 15), 12899, "Pepsi", 6.75, 8},
    {QDate(2020, 3, 15), 61616, "Coke", 6.79, 7},
    {QDate(2020, 3, 15), 12345, "Assorted Muffins", 5.89, 10},
};

const int DAY5_SIZE = 13;
const Purchase DAY5[DAY5_SIZE] = {
    {QDate(2020, 3, 16), 77777, "Crest Toothpaste", 7.59, 9},
    {QDate(2020, 3, 16), 77777, "Grosse Pointe Blank DVD", 16.99, 2},
    {QDate(2020, 3, 16), 88888, "Serendipity", 16.95, 5},
    {QDate(2020, 3, 16), 12345, "Runaway Jury", 18.95, 2},
    {QDate(2020, 3, 16), 61616, "Pork Tenderloin", 13.75, 88},
    {QDate(2020, 3, 16), 61616, "Brie (Made in U.S.)", 7.25, 2},
    {QDate(2020, 3, 16), 12345, "Fresh Mozzarella", 8.65, 2},
    {QDate(2020, 3, 16), 12345, "Vine Ripe Tomatoes", 6.99, 2},
    {QDate(2020, 3, 16), 77777, "Roasted Garlic Bread", 7.29, 2},
    {QDate(2020, 3, 16), 61616, "Disney DVD Collection 2", 59.99, 1},
    {QDate(2020, 3, 16), 12345, "Sprite", 6.75, 20},
    {QDate(2020, 3, 16), 77777, "Coke", 6.79, 2},
    {QDate(2020, 3, 16), 12345, "Propel Fitness Water", 12.50, 3},
};

const int DAY6_SIZE = 11;
const Purchase DAY6[DAY6_SIZE] = {
    {QDate(2020, 3, 17), 77777, "Crest Toothpaste", 7.59, 55},
    {QDate(2020, 3, 17), 12345, "Beef Steak", 18.95, 2},
    {QDate(2020, 3, 17), 61616, "Pork Tenderloin", 13.75, 44},
    {QDate(2020, 3, 17), 61616, "Brie (Made in U.S.)", 7.25, 2},
    {QDate(2020, 3, 17), 12345, "Fresh Mozzarella", 8.65, 2},
    {QDate(2020, 3, 17), 12345, "Vine Ripe Tomatoes", 6.99, 2},
    {QDate(2020, 3, 17), 77777, "Roasted Garlic Bread", 7.29, 2},
    {QDate(2020, 3, 17), 61616, "Disney DVD Collection 2", 59.99, 1},
    {QDate(2020, 3, 17), 12345, "Sprite", 6.75, 20},
    {QDate(2020, 3, 17), 77777, "Coke", 6.79, 2},
    {QDate(2020, 3, 17), 12345, "Propel Fitness Water", 12.50, 3},
};

const int DAY7_SIZE = 4;
const Purchase DAY7[DAY7_SIZE] = {
    {QDate(2020, 3, 18), 77777, "Oatmeal", 5.59, 33},
    {QDate(2020, 3, 18), 12345, "T-bone Steak", 19.95, 55},
    {QDate(2020, 3, 18), 61616, "Salmon", 33.75, 88},
    {QDate(2020, 3, 18), 61616, "Brocolli", 3.99, 50},
};

static const int DAYS_SIZE = 7;
static const int DAY_SIZES[DAYS_SIZE] = {
    SeedData::DAY1_SIZE, SeedData::DAY2_SIZE, SeedData::DAY3_SIZE,
    SeedData::DAY4_SIZE, SeedData::DAY5_SIZE, SeedData::DAY6_SIZE,
    SeedData::DAY7_SIZE,
};
static const SeedData::Purchase *DAYS[DAYS_SIZE] = {
    SeedData::DAY1, SeedData::DAY2, SeedData::DAY3, SeedData::DAY4,
    SeedData::DAY5, SeedData::DAY6, SeedData::DAY7};

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

#endif // SEEDDATA_H
