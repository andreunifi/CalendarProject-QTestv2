//
// Created by andre on 01/07/2020.
//
#include "Activity.h"
#include "Date.h"
#include <exception>
#include <iostream>
#include <list>
#include <map>

#ifndef UNTITLED_REGISTRO_H
#define UNTITLED_REGISTRO_H

class NoActivityfound : public exception
{
private:
    std::string message = " ";

public:
    explicit NoActivityfound(const string &errormessage) { message = errormessage; }
    const char *what() const noexcept override { return message.c_str(); };
};
class NoDayFound : public exception
{
private:
    std::string message = " ";

public:
    explicit NoDayFound(const std::string &errormessage) : message(errormessage) {}
    const char *what() const noexcept override { return message.c_str(); };
};

class Register
{
private:
    map<Date, std::list<Activity>> Registro;

public:
    Register(){};
    void addActivity(Date &z, Activity &n);
#ifdef QT_DEBUG
    void printAllActivities() const;
    void printSpecificDay(Date &d) const;
#endif
    void editActivity(const Date &a,
                      const std::string &c,
                      Date k,
                      Date Stardate,
                      Date Endate,
                      const std::string newname);
    std::string output(const Date d);
    void DeleteActivity(const Date &f, const std::string &a);
    static bool CustomSortComparator(const Activity &c, const Activity &d);
    //Fixed output?
    //need tests
    QString output2(const Date &d);
    Activity FindActivity(Date z, std::string name);
};
#endif //UNTITLED_REGISTRO_H
