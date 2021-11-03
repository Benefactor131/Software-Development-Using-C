//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 10.24.2021
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"

using namespace std;

namespace sdds {
	void Reservation::update(int day_, int time_) {
		dd = day_;
		hh = time_;
	}

	Reservation::Reservation(const string& res) {
		string temp = res;
		string res_temp;
		unsigned colon_pos, comma_pos;

		colon_pos = temp.find(':');
		res_id = trim(temp.substr(0, colon_pos));
		res_temp = temp.substr(colon_pos + 1);

		comma_pos = res_temp.find(',');
		res_name = trim(res_temp.substr(0, comma_pos));
		res_temp = res_temp.substr(comma_pos + 1);

		comma_pos = res_temp.find(',');
		email = trim(res_temp.substr(0, comma_pos));
		res_temp = res_temp.substr(comma_pos + 1);

		comma_pos = res_temp.find(',');
		num_of_people = stoi(res_temp.substr(0, comma_pos));
		res_temp = res_temp.substr(comma_pos + 1);

		comma_pos = res_temp.find(',');
		dd = stoi(res_temp.substr(0, comma_pos));
		res_temp = res_temp.substr(comma_pos + 1);

		hh = stoi(res_temp);

	}

	string Reservation::trim(const string& res)
	{
		string temp = res;
		const string WHITESPACE = " \n\r\t\f\v";

		size_t start = temp.find_first_not_of(WHITESPACE);
		if (start != string::npos) temp = temp.substr(start);

		size_t end = temp.find_last_not_of(WHITESPACE);
		if (end != string::npos) temp = temp.substr(0, end + 1);

		return temp;
	}

	ostream& operator<<(ostream& os, const Reservation& reservation)
	{
		string localEmail = "<" + reservation.email + ">";

		os << "Reservation " << right << setw(10) << reservation.res_id << ": "
			<< right << setw(20) << reservation.res_name
			<< "  " << left << setw(20) << localEmail << "    ";

		if (reservation.hh >= 6 && reservation.hh <= 9)
			os << "Breakfast";
		else if (reservation.hh >= 11 && reservation.hh <= 15)
			os << "Lunch";
		else if (reservation.hh >= 17 && reservation.hh <= 21)
			os << "Dinner";
		else
			os << "Drinks";

		os << " on day " << reservation.dd << " @ " << reservation.hh << ":00 for "
			<< reservation.num_of_people << ((reservation.num_of_people > 1) ? " people." : " person.") << endl;

		return os;
	}

}
