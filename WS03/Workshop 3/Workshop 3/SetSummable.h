//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 10.10.2021
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshopsand assignments.

#ifndef _SDDS_SETSUMMABLE_H_
#define _SDDS_SETSUMMABLE_H_

#include "Set.h"
#include "PairSummable.h"

namespace sdds
{
	template <unsigned N, class T>
	class SetSummable : public Set<N, T>
	{
	public:
		T accumulate(const std::string& filter) const
		{
			T lclT(filter);
			for (unsigned i = 0; i < Set<N, T>::size(); i++)
			{
				if (lclT.isCompatibleWith(this->get(i))) {
					lclT += this->get(i);
				}
			}
			return lclT;
		}
		
		PairSummable<std::string, std::string> accumulate() const
		{
			PairSummable<std::string, std::string> PS;
			for (unsigned i = 0; i < Set<N, T>::size(); i++)
			{
				if (PS.key() == this->get(i).key()) {
					PS += Set<N, T>::get(i);
				}
			}
			return PS;
		}
	};
}
#endif // !_SDDS_SETSUMMABLE_H_
