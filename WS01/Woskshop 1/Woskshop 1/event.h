//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 09.25.2021

#pragma once
#ifndef _SDDS_EVENT_H_
#define _SDDS_EVENT_H_

extern size_t g_sysClock;

namespace sdds {
	class Event {
		char* eventName{nullptr};
		size_t currentTime;
	public:
		Event();
		Event(const Event& obj);
		Event& operator=(const Event& obj);
		~Event();
		void strCpy(const char* str);
		void display();
		void set(const char* name = nullptr);
	};
}

#endif 