//
// Created by andre on 13/06/2020.
//
#include <cstdlib>
#include <exception>
#include <iostream>
#include <time.h>
#include <QDate>
#include <QTime>
#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H

using namespace std;
class InvalidDateException : public exception
{
private:
    std::string message = " ";

public:
    explicit InvalidDateException(const string &errormessage) { message = errormessage; }
    const char *what() const noexcept override { return message.c_str(); }
};

class Date
{
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    unsigned int hour;
    unsigned int minute;
    unsigned int seconds;
    bool isvalidDate;
    void setHour(const unsigned int &hour)
    {
        if (hour <= 23) {
            Date::hour = hour;
        } else {
            throw InvalidDateException("L'ora impostata non e' corretta");
        }
    }

    void setMinute(const unsigned int &minute)
    {
        if (minute <= 59) {
            Date::minute = minute;
        } else {
            throw InvalidDateException("I minuti devono essere compresi da 00 a 59");
        }
    }
    void setYear(const unsigned int &year) { Date::year = year; }
    void setMonth(const unsigned int &month)
    {
        if (month <= 12) {
            Date::month = month;
        } else {
            throw InvalidDateException("Questo mese non appartiene al calendario gregoriano");
        }
    }
    void setDay(const unsigned int &day)
    {
        if (day <= 31) {
            Date::day = day;
        } else {
            throw InvalidDateException(
                "Il giorno inserito non rispetta le regole del calendario gregoriano");
        }
    }
    void setSeconds(const unsigned int &seconds)
    {
        if (seconds <= 59) {
            Date::seconds = seconds;
        } else {
            throw InvalidDateException("il campo secondi e' stato impostato male");
        }
    }

public:
    Date() : day(1), month(1), year(2000), hour(00), minute(00), seconds(00), isvalidDate(true) {}
    Date(int d, int m, int y, int h, int mi, int s)
    {
        setDay(d);
        setMonth(m);
        setYear(y);
        setHour(h);
        setMinute(mi);
        setSeconds(s);
        isvalidDate = Date::IsAValidDate();
    };

    bool IsAValidDate();

    int getDay() const { return day; }

    int getMonth() const { return month; }

    int getYear() const { return year; }

    unsigned int getHour() const { return hour; }

    unsigned int getMinute() const { return minute; }

    unsigned int getSeconds() const { return seconds; }

    //DEBUG
#ifdef QT_DEBUG
    void printDate() const
    {
        cout << getDay() << "/" << getMonth() << "/" << getYear() << "      " << getHour() << ":"
             << getMinute() << ":" << getSeconds() << endl;
    }
#endif
    ~Date() = default;

    bool operator<(const Date &rhs) const;

    bool operator>(const Date &rhs) const;

    bool operator<=(const Date &rhs) const;

    bool operator>=(const Date &rhs) const;

    Date operator=(Date *rhs);
    bool operator==(const Date &rhs) const;
    bool operator!=(const Date &rhs) const;

    void setdate(int i, int j, int k);
    void setTimeofDay(int l, int m, int n);
    std::string returnDateString();
    void ConvertFromQdate(QDate c);
    QString convertToQSTring();
    void COnvertFromQTime(QTime s);
    static bool compareTimes(const Date &c, const Date &o);
    QString convertToQString2();
};
#endif //UNTITLED_DATE_H
