#include "database.h"

void SetDatabase(QSqlDatabase *db)
{
    *db = QSqlDatabase::addDatabase("QMYSQL");
    db->setDatabaseName("lilink_usr");
    db->setHostName("119.29.150.242");
    db->setUserName("mysql");
    db->setPassword("Zyh@508061");
}

bool CheckPasswd(QString* usrName, QString* passWord, int &fundamentalId, QSqlDatabase *db)
{
    QSqlQuery query(*db);
    query.exec(QString("select FundamentalId, PassWord from usr_passwd where usrname=\"") + *usrName + QString("\";"));
    \
    if (query.next() && *passWord == query.value(1).toString()) {
        fundamentalId = query.value(0).toInt();
        return true;
    }
    QMessageBox::warning(NULL, QString("Error!"), QString("Password error!"));
    return false;
}

ManInfo* GetUsrInfo(int fundamentalId, QSqlDatabase *db)
{
    QSqlQuery query(*db);
    query.exec(QString("select * from usr_information where FundamentalId=") + QString::number(fundamentalId, 10) + QString(";"));
    query.next();

    return new ManInfo(query.value(0).toInt(), query.value(4).toInt(),
                       query.value(1).toString(),query.value(2).toString(),
                       query.value(3).toString());
}


QList<ManInfo*>* GetFriendsList(int fundamentalId, QSqlDatabase *db)
{
    QList<ManInfo*>* friendsList = new QList<ManInfo*>;
    friendsList->append(GetUsrInfo(fundamentalId, db));

    QSqlQuery query(*db);
    query.exec(QString("select * from usr_friends where FundamentalId1=") + QString::number(fundamentalId, 10) + QString(";"));
    while (query.next()) {
        friendsList->append(GetUsrInfo(query.value(1).toInt(), db));
    }

    query.exec(QString("select * from usr_friends where FundamentalId2=") + QString::number(fundamentalId, 10) + QString(";"));
    while (query.next()) {
        friendsList->append(GetUsrInfo(query.value(0).toInt(), db));
    }
    return friendsList;
}
