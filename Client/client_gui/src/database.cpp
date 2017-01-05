#include "database.h"

/*  This function sends message only.
 *  It means that it don't receive any message
 *  sendback by server.
 *  timeout: 5000 ms
 */
void SendMsg(QByteArray command)
{
    qDebug() << "Sending Command: " << command;
    QTcpSocket *client = new QTcpSocket();
    client->connectToHost(QHostAddress(addr), port);

    if (client->waitForConnected(5000)) {
        //qDebug() << "Connected to Host Successful!";
    }
    else {
        QMessageBox::warning(NULL, QString("Warning"), QString("NetWork Busy!"));
        qDebug() << "Connected Fail!";
        return ;
    }

    client->write(command);
    client->close();
}

/*  This function sends message and receive reply.
 *  But notice that it receive one piece of message only.
 *  timeout: 5000 ms
 */
QString GetMsg(QByteArray command)
{
    qDebug() << "Searching Command: " << command;
    QTcpSocket *client = new QTcpSocket();
    client->connectToHost(QHostAddress(addr), port);

    if (client->waitForConnected(5000)) {
        //qDebug() << "Connected to Host Successful!";
    }
    else {
        QMessageBox::warning(NULL, QString("Warning"), QString("NetWork Busy!"));
        qDebug() << "Connected Fail!";
        return QString("");
    }

    client->write(command);

    /* receive searching result
     * timeout default : 30000 ms
     */
    QByteArray recvb;
    if (client->waitForReadyRead()) {
        recvb = client->readAll();
    }
    else {
        qDebug() << "Searching Result is Empty!";
        return QString("");
    }

    client->close();
    return QVariant(recvb).toString();
}

/*  This function checks the exist of the usrname
 *  and check if the password is right.
 *  If the password and usrname are right, we also get
 *  the fundamentalId of the usr.
 *  notice that the fundamentalId can't be seen and change by usr.
 */
bool CheckPasswd(QString* usrName, QString* passWord, int &fundamentalId)
{
    /* combine the searching command
     * format : select * from usr_passwd where UsrName='zyoohv';
     */
    QByteArray command;
    command.clear();
    command.append(QString("select * from usr_passwd where UsrName='"));
    command.append(*usrName);
    command.append(QString("';"));

    QString recv = GetMsg(command);

    if (recv.length() <= 2) {
        qDebug() << "Not Exited!";
        return false;
    }

    /* check information and return result
     * format: ((2147483646L, 'bear', 'bear123'),)
     */
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(recv.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {
            QVariantMap result = jsonDocument.toVariant().toMap();
            if (result[QString("2")].toString() == *passWord) {
                fundamentalId = result[QString("0")].toInt();
                return true;
            }
        }
    }

    return false;
}

/* This function gets the all information of the usr
 * which owning the fundamentalId it given.
 * What's more, it apend the information to the friendslist
 */
ManInfo* GetUsrInfo(int fundamentalId)
{
    /* combine the searching command
     * format : select * from usr_information where FundamentalId=2147483646;
     */
    QByteArray command;
    command.clear();
    command.append(QString("select * from usr_information where FundamentalId="));
    command.append(QString::number(fundamentalId, 10));
    command.append(QString(";"));

    QString recv = GetMsg(command);

    /* get the information of 'fundamentalId'
     * it's a little complex and not sure how to improve it.
     * format: "((2147483646L, 'Bear', 'A Silly Bear',
     *     'I\\'m Bear <br><a href=\"https://www.baidu.com\">click</a>', 2147483646L),)"
     */
    int usrId;
    QString name;
    QString information;
    QString infoContent;

    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(recv.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {
            QVariantMap result = jsonDocument.toVariant().toMap();
            usrId = result[QString("4")].toInt();
            name = result[QString("1")].toString();
            information = result[QString("2")].toString();
            infoContent = result[QString("3")].toString();
        }
    }

    return new ManInfo(fundamentalId, usrId, name,information,infoContent);
}


QList<ManInfo*>* GetFriendsList(int fundamentalId)
{
    qDebug() << "GetFriendsList begin with fundamentalId=" << fundamentalId;

    QList<ManInfo*>* friendsList = new QList<ManInfo*>;
    friendsList->append(GetUsrInfo(fundamentalId));

    /* combine the searching command
     * format : select * from usr_information where FundamentalId=2147483646;
     */
    QByteArray command;
    command.clear();
    command.append(QString("select FundamentalId2 from usr_friends where FundamentalId1="));
    command.append(QString::number(fundamentalId, 10));
    command.append(QString(";"));

    QString recv = GetMsg(command);

    qDebug() << "friends list: " << recv;

    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(recv.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {
            QVariantMap result = jsonDocument.toVariant().toMap();

            for (int i = 0; ; i++) {
                if (result[QString::number(i, 10)].toString().length() == 0) break;
                friendsList->append(GetUsrInfo(result[QString::number(i, 10)].toInt()));
            }
        }
    }

    /* combine the searching command
     * format : select * from usr_information where FundamentalId=2147483646;
     */
    command.clear();
    command.append(QString("select FundamentalId1 from usr_friends where FundamentalId2="));
    command.append(QString::number(fundamentalId, 10));
    command.append(QString(";"));

    recv = GetMsg(command);

    qDebug() << "friends list: " << recv;

    jsonDocument = QJsonDocument::fromJson(recv.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {
            QVariantMap result = jsonDocument.toVariant().toMap();

            for (int i = 0; ; i++) {
                if (result[QString::number(i, 10)].toString().length() == 0) break;
                friendsList->append(GetUsrInfo(result[QString::number(i, 10)].toInt()));
            }
        }
    }

    return friendsList;
}

/* This function sends the informations of fundamentalId
 * who wants to break the linking
 * Notice that we don't provide the 'link' function
 */
void DeleteFriendLink(int fundamentalId1, int fundamentalId2)
{
    /* combine the searching command
     * format : select * from usr_passwd where UsrName='zyoohv';
     */
    QByteArray command;
    command.clear();
    command.append(QString(""));
    command.append(QString(" "));
    command.append(QString("';"));
}
