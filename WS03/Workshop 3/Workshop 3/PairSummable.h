//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 10.10.2021
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshopsand assignments.

#ifndef _SDDS_PAIR_SUMMABLE_
#define _SDDS_PAIR_SUMMABLE_

#include <iomanip>
#include "Pair.h"

namespace sdds
{
	template<class V, class K>
	class PairSummable : public Pair<V, K>
	{
		static V init_val;
		static size_t min_width;
	public:
		PairSummable() {};

		PairSummable(const K& key, const V& value = init_val) :Pair<V, K>(key, value) // call the base constructor
		{
			if (key.size() > min_width) {
				min_width = key.size();
			}
		}

		bool isCompatibleWith(const PairSummable<V, K>& b) const
		{
			return (Pair<V, K>::key() == b.key());
		}

		PairSummable& operator+=(const PairSummable& ps)
		{
			PairSummable ps_temp = PairSummable(Pair<V, K>::key(), Pair<V, K>::value() + ps.value());
			*this = ps_temp;
			return *this;
		}

		void display(std::ostream& os) const
		{
			os << std::setw(min_width) << std::left;
			Pair<V, K>::display(os);
			os << std::right;
		}
	};


	template<class V, class K>
	size_t PairSummable<V, K>::min_width = 0u;

	template<class V, class K>
	V  PairSummable<V, K>::init_val = {};

	template <>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>:: operator+=(const PairSummable& PS)
	{
		std::string str = {};

		if (Pair<std::string, std::string>::value() != "")
		{
			str += Pair<std::string, std::string>::value() + ", ";
		}

		str += PS.value();
		PairSummable<std::string, std::string>temp = PairSummable(Pair<std::string, std::string>::key(), str);
		*this = temp;

		return *this;
	}
}
#endif // !_SDDS_PAIRSUMMABLE_H_