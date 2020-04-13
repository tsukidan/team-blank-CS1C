#ifndef DBSETUP_H
#define DBSETUP_H

#include "item.h"
#include "member.h"
#include "purchase.h"
#include "user.h"
#include <QtSql>


bool setupDB();
bool existingAdmin();

#endif // DBSETUP_H
