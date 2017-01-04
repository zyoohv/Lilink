#include "maninfo.h"


ManInfo::ManInfo(int newFundamentalId, int newUsrId, QString newName, QString newInformation, QString newInfoContent)
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

void ManInfo::setFundamentalId(int value)
{
    fundamentalId = value;
}

int ManInfo::getUsrId() const
{
    return usrId;
}

void ManInfo::setUsrId(int value)
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
