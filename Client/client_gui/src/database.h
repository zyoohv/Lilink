#ifndef DATABASE_H
#define DATABASE_H

#include "lilink.h"
#include "maninfo.h"

const QString addr = QString("119.29.150.242");
const int port = 50005;

bool CheckPasswd(QString* usrName, QString* passWord, int &fundamentalId);

QList<ManInfo*>* GetFriendsList(int fundamentalId);

ManInfo* GetUsrInfo(int fundamentalId);

void DeleteFriendLink(int fundamentalId1, int fundamentalId2);

#endif // DATABASE_H
