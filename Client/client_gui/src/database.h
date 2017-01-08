#ifndef DATABASE_H
#define DATABASE_H

#include "lilink.h"
#include "maninfo.h"

/* Server Information
 */
const QString addr = QString("119.29.150.242");
const int port = 50005;

/* table : usr_information
 */
const QString fundamentalIdId = QString("0");
const QString nameId = QString("1");
const QString informationId = QString("2");
const QString infoContentId = QString("3");
const QString usrIdId = QString("4");

/*  This function checks the exist of the usrname
 *  and check if the password is right.
 *  If the password and usrname are right, we also get
 *  the fundamentalId of the usr.
 *  notice that the fundamentalId can't be seen and change by usr.
 */
bool CheckPasswd(QString* usrName, QString* passWord, int &fundamentalId);

QList<ManInfo*>* GetFriendsList(int fundamentalId);

/* This function gets the all information of the usr
 * which owning the fundamentalId it given.
 * What's more, it apend the information to the friendslist
 */
ManInfo* GetUsrInfo(int fundamentalId);

/* This function sends the informations of fundamentalId
 * who wants to break the linking
 * Notice that we don't provide the 'link' function
 */
void DeleteFriendLink(int fundamentalId1, int fundamentalId2);


/* Appling the changed information
 * In other word, it update the server's record
 * by *thisMan.
 */
void ApplyUsrInfo(ManInfo *thisMan);

/* Add new friend with fundamentalId
 * Then append it to the uuid usrId and return true
 * If not existed than return false
 */
bool AppendNewFriend(QList<ManInfo*>* friendsList, QString usrId);

#endif // DATABASE_H
