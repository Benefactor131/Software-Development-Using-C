//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 09.27.2021
//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my workshopsand assignments.

#pragma once
#ifndef _SDDS_STRINGSET_H_
#define _SDDS_STRINGSET_H_

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

namespace sdds
{
    class StringSet
    {
        string* strings{ nullptr };
        size_t stringsCount = 0;
    public:
        //Constructor
        StringSet();
        //Destructor
        ~StringSet();
        //Constructor with one argument
        StringSet(const char* f);
        //Copy Constructor
        StringSet(const StringSet& obj);
        //Move Constructor
        StringSet(StringSet&& obj)noexcept;
        //Copy Assignment
        StringSet& operator=(const StringSet& obj);
        //Move Assignment
        StringSet& operator=(StringSet&& obj) noexcept;
        //Function for returning number of strings in the current object
        size_t size();
        //Index Subscript Operator
        string operator[](size_t index) const;
    };
}

#endif // !_SDDS_STRINGSET_H_

