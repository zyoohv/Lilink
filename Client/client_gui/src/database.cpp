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
    if (client->waitForReadyRead(5000)) {
        recvb = client->readAll();
    }
    else {
        qDebug() << "Searching Result is Empty!";
        return QString("");
    }

    client->close();
    qDebug() << "Searching Result: " << QVariant(recvb).toString();
    return QVariant(recvb).toString();
}


bool CheckPasswd(QString* usrName, QString* passWord, int &fundamentalId)
{
    /* combine the searching command
     * format : select * from usr_passwd where UsrName='zyoohv';
     */
    QByteArray command;
    command.clear();
    command.append(QString("select * from usr_passwd where UsrName=\"") +
                   (*usrName) + QString("\";"));

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


ManInfo* GetUsrInfo(int fundamentalId)
{
    /* combine the searching command
     * format : select * from usr_information where FundamentalId=2147483646;
     */
    QByteArray command;
    command.clear();
    command.append(QString("select * from usr_information where FundamentalId=") +
                   QString::number(fundamentalId, 10) + QString(";"));

    QString recv = GetMsg(command);

    /* get the information of 'fundamentalId'
     * it's a little complex and not sure how to improve it.
     * format: "((2147483646L, 'Bear', 'A Silly Bear',
     *     'I\'m Bear <br><a href=\"https://www.baidu.com\">click</a>', 2147483646L),)"
     */
    QString usrId;
    QString name;
    QString information;
    QString infoContent;

    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(recv.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {
            QVariantMap result = jsonDocument.toVariant().toMap();
            usrId = result[usrIdId].toString();
            name = result[nameId].toString();
            information = result[informationId].toString();
            infoContent = result[infoContentId].toString();
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


void DeleteFriendLink(int fundamentalId1, int fundamentalId2)
{
    /* combine the searching command
     * format : select * from usr_passwd where UsrName='zyoohv';
     */
    QByteArray command;
    command.clear();
    command.append(QString("delete from usr_friends where FundamentalId1=") +
                   QString::number(fundamentalId1, 10) + QString(" and ") +
                   QString("FundamentalId2=") + QString::number(fundamentalId2, 10) + QString(";"));

    SendMsg(command);

    command.clear();
    command.append(QString("delete from usr_friends where FundamentalId1=") +
                   QString::number(fundamentalId2, 10) + QString(" and ") +
                   QString("FundamentalId2=") + QString::number(fundamentalId1, 10) + QString(";"));

    SendMsg(command);
}

void ApplyUsrInfo(ManInfo *thisMan)
{
    QByteArray command;
    command.clear();
    command.append(QString("update usr_information set Name=\"") + thisMan->getName().replace("\"", "\\\"") +
                   QString("\",Information=\"") + thisMan->getInformation().replace("\"", "\\\"") +
                   QString("\",InfoContent=\"") + thisMan->getInfoContent().replace("\"", "\\\"") +
                   QString("\",UsrId=\"") + thisMan->getUsrId() +
                   QString("\" where FundamentalId=") + QString::number(thisMan->getFundamentalId(), 10) + QString(";"));

    SendMsg(command);
}

bool AppendNewFriend(QList<ManInfo *> *friendsList, QString usrId)
{
    QByteArray command;
    command.clear();
    command.append(QString("select * from usr_information where UsrId=\"") +
                   usrId + QString("\";"));

    QString recv = GetMsg(command);

    qDebug() << usrId << ":\"" << recv << "\"";

    if (recv.length() < 10) {
        qDebug() << "usr not existed!";
        return false;
    }

    /* get the information of 'fundamentalId'
     * it's a little complex and not sure how to improve it.
     * format: "((2147483646L, 'Bear', 'A Silly Bear',
     *     'I\'m Bear <br><a href=\"https://www.baidu.com\">click</a>', 2147483646L),)"
     */
    int fundamentalId;
    QString name;
    QString information;
    QString infoContent;

    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(recv.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {
            QVariantMap result = jsonDocument.toVariant().toMap();
            fundamentalId = result[fundamentalIdId].toInt();
            name = result[nameId].toString();
            information = result[informationId].toString();
            infoContent = result[infoContentId].toString();
        }
    }

    command.clear();

    QByteArray insertCommand;
    insertCommand.clear();
    if (friendsList->at(0)->getFundamentalId() < fundamentalId) {
        command.append(QString("select * from usr_friends where FundamentalId1=") +
                       QString::number(friendsList->at(0)->getFundamentalId(), 10) +
                       QString(" and FundamentalId2=") + QString::number(fundamentalId, 10) + QString(";"));
        insertCommand.append(QString("insert into usr_friends (FundamentalId1, FundamentalId2) values (") +
                             QString::number(friendsList->at(0)->getFundamentalId(), 10) + QString(", ") +
                             QString::number(fundamentalId, 10) + QString(");"));
    }
    else if (friendsList->at(0)->getFundamentalId() > fundamentalId) {
        command.append(QString("select * from usr_friends where FundamentalId1=") +
                       QString::number(fundamentalId, 10) + QString(" and FundamentalId2=") +
                       QString::number(friendsList->at(0)->getFundamentalId(), 10) + QString(";"));
        insertCommand.append(QString("insert into usr_friends (FundamentalId1, FundamentalId2) values (") +
                             QString::number(fundamentalId, 10) + QString(", ") +
                             QString::number(friendsList->at(0)->getFundamentalId(), 10) + QString(");"));
    }
    else return false;

    recv = GetMsg(command);
    if (recv.length() > 10) {
        qDebug() << "has been your friend!";
        return false;
    }

    SendMsg(insertCommand);

    friendsList->append(new ManInfo(fundamentalId, usrId, name, information, infoContent));

    return true;
}
