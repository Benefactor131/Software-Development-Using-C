//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 09.27.2021
//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my workshopsand assignments.

#include "StringSet.h"

namespace sdds {
    StringSet::StringSet() {
        strings = nullptr;
        stringsCount = 0;
    }

    StringSet::StringSet(const char* name) {
        ifstream file(name);
        string str;
        size_t counter = 0;
        if (file.good())
        {
            while (!file.eof())
            {
                getline(file, str, ' ');
                counter++;
            }
        }
        file.close();
        stringsCount = counter;
        file.open(name);
        
        strings = new string[counter];
        if (file.is_open())
        {
            for (auto i = 0u; i < counter; ++i) {
                getline(file, strings[i], ' ');
            }
        }

        file.close();
    }


    StringSet::StringSet(const StringSet& obj) {
        *this = obj;
    }


    StringSet& StringSet::operator=(const StringSet& obj) {
        if (this != &obj)
        {
            stringsCount = obj.stringsCount;

            delete[] strings;

            strings = new string[stringsCount];
            for (auto i = 0u; i < stringsCount; ++i)
            {
                strings[i] = obj.strings[i];
            }
        }

        return *this;
    }

    StringSet::StringSet(StringSet&& obj) noexcept{
        stringsCount = obj.stringsCount;
        strings = obj.strings;

        obj.stringsCount = 0;
        obj.strings = nullptr;
    }

    StringSet& StringSet::operator=(StringSet&& obj) noexcept{
        if (this != &obj)
        {
            this->stringsCount = obj.stringsCount;
            
            this->strings = obj.strings;

            obj.stringsCount = 0;
            obj.strings = nullptr;
        }

        return *this;
    }

    size_t StringSet::size()
    {
        return stringsCount;
    }

    StringSet::~StringSet() {
        delete[] strings;
    }

    string StringSet::operator[](size_t index) const {
        if (!strings || index > stringsCount) {
            return "";
        }
        return strings[index];
    }
}

