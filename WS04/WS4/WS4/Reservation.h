//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 10.24.2021
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshopsand assignments.
#pragma once
#ifndef _SDDS_RESERVATION_H
#define _SDDS_RESERVATION_H

#include <string>

namespace sdds {
	class Reservation
	{
		std::string res_id;
		std::string res_name{};
		std::string email{};
		int num_of_people{};
		int dd{};
		int hh{};
	public:
		//default constructor
		Reservation() {};
		//Updates reservation day and time
		void update(int day, int time);
		//copy constructor
		Reservation(const std::string& res);
		//Removes leading and trailing spaces
		std::string trim(const std::string& res);
		//Insertion Operator
		friend std::ostream& operator << (std::ostream& os, const Reservation& obj);
	};
}
#endif
