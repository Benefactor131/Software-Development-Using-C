//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 10.24.2021
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshopsand assignments.
#pragma once
#ifndef CONFIRMATIONSENDER_H
#define CONFIRMATIONSENDER_H

#include "Restaurant.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** arr{ nullptr };
		size_t nums{ 0 };
	public:
		//default constructor
		ConfirmationSender();
		//destructor
		virtual ~ConfirmationSender();
		//copy constructor
		ConfirmationSender(ConfirmationSender& obj);
		//move constructor
		ConfirmationSender(ConfirmationSender&& obj)noexcept;
		//copy assignment
		ConfirmationSender& operator=(ConfirmationSender& obj);
		//move assignment
		ConfirmationSender& operator=(ConfirmationSender&& obj)noexcept;
		//Addition assignment operator 
		ConfirmationSender& operator+=(const Reservation& res);
		//Subtraction assignment operator
		ConfirmationSender& operator-=(const Reservation& res);
		//Insertion Operator
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& obj);
	};
}

#endif 