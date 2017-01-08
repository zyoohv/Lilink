#ifndef MANINFO_H
#define MANINFO_H

#include "lilink.h"

class ManInfo
{
public:

    ManInfo(int, QString, QString, QString, QString);
    ~ManInfo();

    int getFundamentalId() const;

    QString getUsrId() const;
    void setUsrId(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getInformation() const;
    void setInformation(const QString &value);

    QString getInfoContent() const;
    void setInfoContent(const QString &value);

private:

    int fundamentalId;
    QString usrId;
    QString name;
    QString information;
    QString infoContent;
};

#endif // MANINFO_H
