//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 10.24.2021
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshopsand assignments.
#pragma once
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Reservation.h"
namespace sdds
{
	class Restaurant
	{
		Reservation* res{ nullptr };
		size_t res_num{ 0 };
	public:
		//default constructor
		Restaurant() {};
		//destructor
		virtual ~Restaurant();
		//two parameter constructor
		Restaurant(const Reservation* reservations[], size_t cnt);
		//copy constructor
		Restaurant(const Restaurant& obj);
		//move constructor
		Restaurant(Restaurant&& obj)noexcept;
		//copy assignment
		Restaurant& operator=(const Restaurant& obj);
		//move assignment
		Restaurant& operator=(Restaurant&& obj)noexcept;
		//Returns number of reservations
		size_t size() const;
		//Insertion Operator
		friend std::ostream& operator << (std::ostream& os, const Restaurant& obj);
	};
}
#endif 