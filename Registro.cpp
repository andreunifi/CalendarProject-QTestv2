//
// Created by andre on 01/07/2020.
//
#include "Registro.h"
//La funzione aggiunge una attività nel determinato giorno z. Se il giorno z appartiene al registro(quindi ha attività) verifica
// se la lista delle attività di quel giorno è piena/vuota, se vuota aggiunde l'attività in testa, altrimenti aggiunge l'attività in coda e fa il sort della lista;
void Register::addActivity(Date &z, Activity &n)
{
    auto it = Registro.find(z);
    if (it != Registro.end()) {
        if (it->second.empty()) {
            it->second.push_front(n);
        } else {
            if (CustomSortComparator(n, it->second.front())) {
                it->second.push_front(n);
            } else {
                if (CustomSortComparator(it->second.back(), n)) {
                    it->second.push_back(n);
                } else {
                    it->second.push_back(n);
                    it->second.sort(CustomSortComparator);
                }
            }
            // it->second.push_back(n);
            //it->second.sort(CustomSortComparator);
            //funzionavano il 10/07/2020
        }
    } else {
        //debug
        std::cout << "Il giorno specificato non ha nulla programmato" << std::endl;
        std::list<Activity> as;
        as.push_front(n);
        Registro.insert(pair<Date, std::list<Activity>>(z, as));
    }
}
//debug
#ifdef QT_DEBUG
void Register::printAllActivities() const
{
    for (const auto &it : Registro)
        for (auto iz = it.second.begin(); iz != it.second.end(); iz++)
            iz->printInfo();
}
//debug
void Register::printSpecificDay(Date &d) const
{
    auto it = Registro.find(d);
    if (it != Registro.end()) {
        for (auto ip = it->second.begin(); ip != it->second.end(); ip++) {
            ip->printInfo();
        }

    } else {
        std::cout << "il giorno non ha attività programmate" << std::endl;
    }
}
#endif
//Fixme add QTime to the activity
void Register::editActivity(const Date &d,
                            const std::string &c,
                            Date k,
                            Date Startdate,
                            Date Endate,
                            const std::string newname)
{
    auto it = Registro.find(d);
    if (it != Registro.end()) {
        if (it->second.empty()) {
            //use exception
            throw NoActivityfound("Errore,nessuna attività in programma");
        } else {
            for (auto ip = it->second.begin(); ip != it->second.end();) {
                if (ip->getName() == c && ip->getStartdate() == d) {
                    ip->setName(newname);
                    ip->setStartdate(Startdate);
                    ip->setEnddate(Endate);
                    ip->printInfo();
                    if (ip->getStartdate() != d) {
                        Activity c(ip->returnActivity());
                        it->second.erase(ip);
                        if (it->second.empty())
                            Registro.erase(it);
                        addActivity(k, c);
                    }
                } else {
                    ip++;
                }
            }
        }
    } else {
        //uses exception
        throw NoDayFound("Nessun giorno corrispondente trovato");
    }
}
//Se la funzione non trova la data/la lista delle attività è vuota ritorna la stringa c con un appropiato messaggio;
//FIXME il returnDateString, una volta convertito a QDateString, riporta errore di formattazione
std::string Register::output(const Date d)
{
    auto it = Registro.find(d);
    std::string c;
    if (it != Registro.end()) {
        for (auto ip = it->second.begin(); ip != it->second.end(); ip++) {
            c += "\n" + ip->getName() + "  " + ip->getDescriptionName() + " "
                 + ip->getStartdate().returnDateString();
        }
        return c;
    } else {
        c = "Nessuna attività programmata";
        return c;
    }
}

void Register::DeleteActivity(const Date &f, const std::string &a)
{
    auto it = Registro.find(f);
    if (it != Registro.end()) {
        if (it->second.empty()) {
            throw NoActivityfound("Nessuna attività trovata");
        } else {
            for (auto ip = it->second.begin(); ip != it->second.end();) {
                if (ip->getName() == a && ip->getStartdate() == f) {
                    ip = it->second.erase(ip);
                    if (it->second.empty())
                        Registro.erase(it);
                } else {
                    ++ip;
                }
            }
        }
    } else {
        //use exception
        throw NoDayFound("Nessun giorno trovato");
    };
}

bool Register::CustomSortComparator(const Activity &c, const Activity &d)
{
    if (Date::compareTimes(c.getStartdate(), d.getStartdate())) {
        return true;
    } else {
        return false;
    }
}

QString Register::output2(const Date &d)
{
    auto it = Registro.find(d);
    QString k;
    if (it != Registro.end()) {
        for (auto ip = it->second.begin(); ip != it->second.end(); ip++) {
            k += "\n" + ip->getQStringName() + "  " + ip->getQSTringDesc() + " "
                 + ip->getStartdate().convertToQSTring() + " - "
                 + ip->getEnddate().convertToQSTring();
        }
        return k;
    } else {
        k = "Nessuna attività programmata";
        return k;
    }
}

Activity Register::FindActivity(Date z, string name)
{
    auto it = Registro.find(z);
    if (it != Registro.end()) {
        if (it->second.empty()) {
            throw NoActivityfound("Nessuna attività trovata");
        } else {
            for (auto ip = it->second.begin(); ip != it->second.end();) {
                if (ip->getName() == name && ip->getStartdate() == z) {
                    return *ip;
                } else {
                    ++ip;
                }
            }
        }
    } else {
        //use exception
        throw NoDayFound("Nessun giorno trovato");
    };
}
