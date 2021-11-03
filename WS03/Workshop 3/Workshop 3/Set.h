//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 10.10.2021
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshopsand assignments.

#ifndef _SDDS_SET_
#define _SDDS_SET_

namespace sdds {
	template<unsigned N, typename T >
	class Set {
		T arr[N];
		size_t elems = 0u;
	public:
		size_t size() const;
		const T& get(size_t idx) const;
		void operator+=(const T& item);
	};

	template<unsigned N, class T>
	size_t Set<N, T>::size() const {
		return elems;
	}

	template<unsigned N, class T>
	const T& Set<N, T>::get(size_t idx) const {
		return arr[idx];
	}

	template<unsigned N, class T>
	void Set<N, T>::operator+=(const T& item) {
		if (elems < N) {
			arr[elems++] = item;
		}
	}
}

#endif // !_SDDS_SET_H_