//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 09.27.2021
//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my workshopsand assignments.

#pragma once
#ifndef _SDDS_TIMEDEVENTS_H_
#define _SDDS_TIMEDEVENTS_H_
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

#define MAX 10

namespace sdds {
	class TimedEvents {
		unsigned int recNum;
		chrono::steady_clock::time_point eventStart;
		chrono::steady_clock::time_point eventEnd;
		struct Events {
			const char* eventName;
			const char* timeUnit;
			chrono::steady_clock::duration eventDuration;
		} records[MAX];
	public:
		TimedEvents();
		~TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* name);
		friend ostream& operator<<(ostream& os, const TimedEvents& obj);
	};
}
#endif // !_SDDS_TIMEDEVENTS_H_
