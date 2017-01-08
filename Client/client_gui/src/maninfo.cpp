#include "maninfo.h"


ManInfo::ManInfo(int newFundamentalId, QString newUsrId, QString newName, QString newInformation, QString newInfoContent)
{
    fundamentalId = newFundamentalId;
    usrId = newUsrId;
    name = newName;
    information = newInformation;
    infoContent = newInfoContent;
}

ManInfo::~ManInfo()
{
    // hello world !
}

int ManInfo::getFundamentalId() const
{
    return fundamentalId;
}

QString ManInfo::getUsrId() const
{
    return usrId;
}

void ManInfo::setUsrId(const QString &value)
{
    usrId = value;
}

QString ManInfo::getName() const
{
    return name;
}

void ManInfo::setName(const QString &value)
{
    name = value;
}

QString ManInfo::getInformation() const
{
    return information;
}

void ManInfo::setInformation(const QString &value)
{
    information = value;
}

QString ManInfo::getInfoContent() const
{
    return infoContent;
}

void ManInfo::setInfoContent(const QString &value)
{
    infoContent = value;
}
