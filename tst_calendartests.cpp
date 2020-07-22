#include "Registro.h"
#include <QCoreApplication>
#include <QtTest>

class CalendarTests : public QObject
{
    Q_OBJECT

public:
    CalendarTests();
    ~CalendarTests();

private slots:
    //------------------Date tests----------------------
    void initTestCase();
    void WrongDateinCTor();
    void setWrongTimeOfDay();
    void setWrongDate();
    void setWrongDateANDTime();
    void setRightDate();
    void serRightDateANDTime();
    void CompareDates();
    void CompareTimes();
    //------------------Activity tests-------------------
    void StartTimeGreaterEndTimeinCTor();
    void StartTimeGreaterEndTimewithSetTime();
    void EndTimeLesserStartTimeinCTor();
    void EndTimeLesserStartTimewithSetTime();
    //------------------Registro tests-------------------
    void AddActivity();
    void EditActivityNoDayFound();
    void DeleteActivityNoDayFound();

    void cleanupTestCase();
};

CalendarTests::CalendarTests() {}

CalendarTests::~CalendarTests() {}

void CalendarTests::initTestCase() {}

void CalendarTests::WrongDateinCTor()
{
    QVERIFY_EXCEPTION_THROWN(Date c(29, 2, 2001, 00, 00, 00), InvalidDateException);
}

void CalendarTests::setWrongTimeOfDay()
{
    Date p;
    QVERIFY_EXCEPTION_THROWN(p.setTimeofDay(27, 91, 289), InvalidDateException);
}

void CalendarTests::setWrongDate()
{
    Date k;
    QVERIFY_EXCEPTION_THROWN(k.setDate(29, 2, 2001), InvalidDateException);
}

void CalendarTests::setWrongDateANDTime()
{
    Date po;
    QVERIFY_EXCEPTION_THROWN(po.setDate(45, 21, 1532), InvalidDateException);
    QVERIFY_EXCEPTION_THROWN(po.setTimeofDay(190, 11, 152), InvalidDateException);
}

void CalendarTests::setRightDate()
{
    Date c;
    c.setDate(29, 2, 2000);
    QCOMPARE(c.IsAValidDate(), true);
}

void CalendarTests::serRightDateANDTime()
{
    Date k;
    k.setDate(29, 2, 2000);
    QCOMPARE(k.IsAValidDate(), true);
    k.setTimeofDay(00, 00, 01);
    QCOMPARE(k.convertTimeToQString(), "0:0");
}

void CalendarTests::CompareDates()
{
    //Return true se p1<p2
    Date p1;
    p1.setDate(1, 1, 1999);
    Date p2;
    QCOMPARE(p1 < p2, true);
}

void CalendarTests::CompareTimes()
{
    Date p3;
    Date p4;
    p3.setTimeofDay(10, 11, 00);
    p4.setTimeofDay(10, 12, 00);
    QCOMPARE(Date::compareTimes(p3, p4), true);
}

void CalendarTests::StartTimeGreaterEndTimeinCTor()
{
    Date n;
    n.setTimeofDay(13, 12, 00);
    Date op;
    op.setTimeofDay(11, 21, 00);
    QVERIFY_EXCEPTION_THROWN(Activity po("Parrucchiere", "A casa di Lucia", n, op),
                             NotAValidActivity);
}

void CalendarTests::StartTimeGreaterEndTimewithSetTime()
{
    Date i;
    i.setTimeofDay(10, 11, 00);
    Date y;
    y.setTimeofDay(11, 11, 00);
    Activity n("Test", "TestDesc", i, y);
    i.setTimeofDay(15, 11, 00);
    n.setStartdate(i);
    y.setTimeofDay(11, 11, 00);
    QVERIFY_EXCEPTION_THROWN(n.setEnddate(y), NotAValidActivity);
}

void CalendarTests::EndTimeLesserStartTimeinCTor()
{
    Date u;
    u.setDate(1, 1, 1995);
    Date d;
    QVERIFY_EXCEPTION_THROWN(Activity s("Test", "TestDesc", d, u), NotAValidActivity);
}

void CalendarTests::EndTimeLesserStartTimewithSetTime()
{
    Date r;
    r.setTimeofDay(11, 10, 00);
    Date g;
    g.setTimeofDay(12, 11, 00);
    Activity k("Test", "Testdesc", r, g);
    Date i;
    i.setTimeofDay(9, 00, 00);
    QVERIFY_EXCEPTION_THROWN(k.setEnddate(i), NotAValidActivity);
}

void CalendarTests::AddActivity()
{
    Register c;
    Date o;
    Date k;
    o.setTimeofDay(9, 00, 00);
    k.setTimeofDay(10, 11, 12);
    Date p;
    Activity ka("Test", "Test2", o, k);
    c.addActivity(p, ka);
    QCOMPARE(c.findActivity(p, ka.getName()) == ka, true);
}

void CalendarTests::EditActivityNoDayFound()
{
    Register c;
    Date o;
    Date k;
    o.setTimeofDay(9, 00, 00);
    k.setTimeofDay(10, 11, 12);
    Date newdate(1, 1, 1999, 0, 0, 0);
    Activity ka("Test", "Test2", o, k);
    c.addActivity(o, ka);
    QVERIFY_EXCEPTION_THROWN(c.editActivity(newdate, ka.getName(), o, o, k, "Test3"), NoDayFound);
}

void CalendarTests::DeleteActivityNoDayFound()
{
    Register c;
    Date o;
    Date p;
    Date start;
    o.setTimeofDay(10, 11, 00);
    p.setTimeofDay(11, 10, 00);
    Activity ac("Test", "Testdesc", o, p);
    c.addActivity(start, ac);
    c.deleteActivity(start, ac.getName());
    QVERIFY_EXCEPTION_THROWN(c.findActivity(start, ac.getName()), NoDayFound);
}

void CalendarTests::cleanupTestCase() {}

QTEST_MAIN(CalendarTests)

#include "tst_calendartests.moc"
