//
// Created by andre on 01/07/2020.
//
#ifndef UNTITLED_ACTIVITY_H
#define UNTITLED_ACTIVITY_H
#include "Date.h"
#include <exception>
#include <iostream>
#include <QString>
using namespace std;
class NotAValidActivity : public exception
{
private:
    std::string message;

public:
    explicit NotAValidActivity(const string &errormessage) { message = errormessage; }
    const char *what() const noexcept override { return message.c_str(); }
};
class Activity
{
private:
    string name;
    string description_name;
    Date startdate;
    Date enddate;
    bool isvalid;

public:
    Activity() = default;
    Activity(const string &a, const string &n, const Date &s, const Date &e)
        : name(a), description_name(n), startdate(s), enddate(e), isvalid(true)
    {
        if (checkifvalid() == false)
            throw NotAValidActivity("L'attività non è valida");
    }
    //DEBUG USE
#ifdef QT_DEBUG
    void printInfo() const
    {
        cout << name << endl;
        cout << description_name << endl;
        startdate.printDate();
        enddate.printDate();
    }
#endif
    //Clone constructor
    Activity(const Activity &p)
        : name(p.getName()), description_name(p.getDescriptionName()), startdate(p.getStartdate()),
          enddate(p.getEnddate())
    {}

    bool operator==(const Activity &rhs) const { return startdate == rhs.startdate; }

    bool operator!=(const Activity &rhs) const { return !(rhs == *this); }

    bool operator<(const Activity &rhs) const;

    bool operator>(const Activity &rhs) const;

    bool operator<=(const Activity &rhs) const;

    bool operator>=(const Activity &rhs) const;

    const string getName() const;

    QString getQStringName();

    QString getQStringDesc();

    const string getDescriptionName() const;

    Date getStartdate() const;

    Date getEnddate() const;

    void setName(const string &name);

    void setDescriptionName(const string &descriptionName);

    void setStartdate(const Date &startdate);

    void setEnddate(const Date &enddate);

    std::string returnStdString();

    Activity returnActivity() { return *this; }

    bool checkifvalid();
};

#endif //UNTITLED_ACTIVITY_H
