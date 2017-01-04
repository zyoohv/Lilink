#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QCoreApplication>
#include "maninfo.h"

void SetDatabase(QSqlDatabase *db);

bool CheckPasswd(QString* usrName, QString* passWord, int &fundamentalId, QSqlDatabase* db);

QList<ManInfo*>* GetFriendsList(int fundamentalId, QSqlDatabase* db);

ManInfo* GetUsrInfo(int fundamentalId, QSqlDatabase* db);


#endif // DATABASE_H
