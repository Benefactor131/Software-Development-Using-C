//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 10.10.2021
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshopsand assignments.

#ifndef _SDDS_PAIR_
#define _SDDS_PAIR_

#include<iostream>

namespace sdds {
	template<class V, class K>
	class Pair {
		V m_val;
		K m_key;
	public:
		Pair();
		Pair(const K& key, const V& value);
		const V& value() const;
		const K& key() const;
		virtual void display(std::ostream& os) const;
	};

	template<class V, class K>
	Pair<V, K>::Pair() {
		m_val = {};
		m_key = {};
	}

	template<class V, class K>
	Pair<V, K>::Pair(const K& key, const V& value) {
		m_val = value;
		m_key = key;
	}

	template<class V, class K>
	const V& Pair<V, K>::value() const {
		return m_val;
	}

	template<class V, class K>
	const K& Pair<V, K>::key() const {
		return m_key;
	}

	template<class V, class K>
	void Pair<V, K>::display(std::ostream& os) const {
		os << m_key << " : " << m_val << std::endl;
	}

	template<class V, class K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}

}
#endif // !_SDDS_PAIR_H_