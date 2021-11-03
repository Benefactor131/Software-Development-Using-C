//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 09.25.2021

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

using namespace std;

size_t g_sysClock{};

namespace sdds {
	Event::Event() : currentTime(g_sysClock)
	{
		currentTime = g_sysClock;
	}

	Event::Event(const Event& obj) {
		*this = obj;
	}

	Event& Event::operator=(const Event& obj)
	{
		currentTime = obj.currentTime;
		strCpy(obj.eventName);
		return *this;
	}

	Event::~Event()
	{
		if (eventName != nullptr)
			delete[] eventName;
	}

	void Event::strCpy(const char* str)
	{
		if (str && str[0] != '\0')
		{
			if (eventName)
				delete[] eventName;
			eventName = new char[strlen(str) + 1];
			strcpy(eventName, str);
		}
	}
	
	
	void Event::display() {
		static int counter = 1;
		if (eventName != nullptr)
		{
			size_t hours = currentTime / 3600;
			size_t minutes = (currentTime - hours * 3600) / 60;
			size_t seconds = currentTime - hours * 3600 - minutes * 60;

			cout << setw(2) << setfill(' ') << counter++ << ". " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " => " << eventName << endl;
		}
		else
		{
			cout << setw(2) << setfill(' ') << counter++ << ". | No Event |" << endl;
		}
	}

	void Event::set(const char* name)
	{
		if (name && name[0] != '\0')
		{
			Event obj;
			currentTime = obj.currentTime;
			strCpy(name);
		}
		else
		{
			delete[] eventName;
			eventName = nullptr;
			currentTime = 0;
		}
	}
}
