//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 09.27.2021
//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my workshopsand assignments.

#include "TimedEvents.h"
namespace sdds {
    TimedEvents::TimedEvents() {
        recNum = 0;
        records->eventName = nullptr;
        records->timeUnit = nullptr;
        records->eventDuration = {};
        eventStart = {};
        eventEnd = {};
    }

    TimedEvents::~TimedEvents()
    {
        records->eventName = nullptr;
        delete[] records->eventName;
        records->timeUnit = nullptr;
        delete[] records->timeUnit;
    }

    void TimedEvents::startClock()
    {
        eventStart = chrono::steady_clock::now();
    }

    void TimedEvents::stopClock()
    {
        eventEnd = chrono::steady_clock::now();
    }

    void TimedEvents::addEvent(const char* name)
    {
        records[recNum].eventName = name;
        records[recNum].timeUnit = "nanoseconds";
        records[recNum].eventDuration = chrono::duration_cast<chrono::nanoseconds>(eventEnd - eventStart);
        recNum++;
    }
    
    ostream& operator<<(ostream& os, const TimedEvents& obj)
    {
        os << "--------------------------\n";
        os << "Execution Times:\n";
        os << "--------------------------\n";

        for (auto i = 0u; i < obj.recNum; i++)
            os << setw(20) << left
            << obj.records[i].eventName << ' '
            << setw(12) << right
            << obj.records[i].eventDuration.count() << ' '
            << obj.records[i].timeUnit << '\n';
        os << "--------------------------\n";

        return os;
    }
}