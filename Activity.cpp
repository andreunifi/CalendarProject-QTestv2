//
// Created by andre on 02/07/2020.
//
#include "Activity.h"

bool Activity::operator<(const Activity &rhs) const
{
    return startdate < rhs.startdate;
}

bool Activity::operator>(const Activity &rhs) const
{
    return rhs < *this;
}

bool Activity::operator<=(const Activity &rhs) const
{
    return !(rhs < *this);
}

bool Activity::operator>=(const Activity &rhs) const
{
    return !(*this < rhs);
}

const string Activity::getName() const
{
    return name;
}

QString Activity::getQStringName()
{
    QString k;
    k = QString::fromStdString(getName());
    return k;
}

QString Activity::getQStringDesc()
{
    QString a;
    a = QString::fromStdString(getDescriptionName());
    return a;
}

const string Activity::getDescriptionName() const
{
    return description_name;
}

Date Activity::getStartdate() const
{
    return startdate;
}

Date Activity::getEnddate() const
{
    return enddate;
}

void Activity::setName(const string &name)
{
    Activity::name = name;
}

void Activity::setDescriptionName(const string &descriptionName)
{
    description_name = descriptionName;
}

void Activity::setStartdate(const Date &startdate)
{
    Activity::startdate = startdate;
}

void Activity::setEnddate(const Date &enddate)
{
    Activity::enddate = enddate;
    if (checkifvalid() == false)
        throw NotAValidActivity("L'attività non è valida-endate");
}

std::string Activity::returnStdString()
{
    std::string f;
    f = Activity::getDescriptionName();
    return f;
}
//CompareTimes verifies that startdate is < than enddate
bool Activity::checkifvalid()
{
    if (startdate.IsAValidDate() == true && enddate.IsAValidDate() == true
        && Date::compareTimes(startdate, enddate) == true) {
        return true;
    } else {
        return false;
    }
}
