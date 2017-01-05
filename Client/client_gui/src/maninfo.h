#ifndef MANINFO_H
#define MANINFO_H

#include "lilink.h"

class ManInfo
{
public:

    ManInfo(int, int, QString, QString, QString);
    ~ManInfo();

    int getFundamentalId() const;
    void setFundamentalId(int value);

    int getUsrId() const;
    void setUsrId(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getInformation() const;
    void setInformation(const QString &value);

    QString getInfoContent() const;
    void setInfoContent(const QString &value);

private:

    int fundamentalId;
    int usrId;
    QString name;
    QString information;
    QString infoContent;
};

#endif // MANINFO_H
