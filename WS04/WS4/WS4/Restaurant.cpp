//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 10.24.2021
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include "Restaurant.h"

using namespace std;

namespace sdds
{
	Restaurant::~Restaurant()
	{
		delete[] res;
	}

	Restaurant::Restaurant(const Reservation* reservations[], size_t count)
	{
		if (count && reservations[0]) {
			res_num = count;
			res = new Reservation[count];
			for (size_t i = 0; i < count; ++i)
			{
				res[i] = Reservation(*reservations[i]);
			}
		}
	}

	Restaurant::Restaurant(const Restaurant& obj)
	{
		operator=(obj);
	}

	Restaurant::Restaurant(Restaurant&& obj)noexcept
	{
		operator=(move(obj));
	}

	Restaurant& Restaurant::operator=(const Restaurant& obj)
	{
		if (this != &obj)
		{
			if (obj.res_num && obj.res)
			{
				res_num = obj.res_num;
				delete[] res;
				res = new Reservation[obj.res_num];
				for (size_t i = 0; i < obj.res_num; ++i) {
					res[i] = obj.res[i];
				}
			}
			else cout << "object.m_num =0 or object.m_res is null ptr" << endl;
		}

		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& obj) noexcept
	{
		if (this != &obj)
		{
			if (obj.res_num && obj.res)
			{
				res_num = obj.res_num;
				delete[] res;
				res = obj.res;
				obj.res = nullptr;
				obj.res_num = 0;
			}
			else cout << "object.m_num =0 or object.m_res is null ptr" << endl;
		}

		return *this;
	}

	size_t Restaurant::size() const
	{
		return res_num;
	}

	ostream& operator<<(ostream& os, const Restaurant& res)
	{
		static size_t count = 1;

		if (res.res_num && res.res)
		{
			os << "--------------------------\nFancy Restaurant (" << count << ")\n--------------------------\n";
			for (size_t i = 0; i < res.res_num; ++i)
			{
				os << res.res[i];
			}
			os << "--------------------------\n";
		}
		else {
			os << "--------------------------\nFancy Restaurant (" << count << ")\n--------------------------\nThis restaurant is empty!\n--------------------------\n";
		}

		count++;

		return os;
	}
}