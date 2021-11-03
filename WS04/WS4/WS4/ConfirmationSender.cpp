//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//Date: 10.24.2021
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds
{
    ConfirmationSender::ConfirmationSender()
    {
        arr = nullptr;
    }

    ConfirmationSender::~ConfirmationSender()
    {
        delete[] arr;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender& obj)
    {
        operator=(obj);
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& obj) noexcept
    {
        operator=(move(obj));
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender& obj)
    {
        if (this != &obj)
        {
            if (obj.nums && obj.arr)
            {
                nums = obj.nums;
                delete[] arr;
                arr = new const Reservation * [nums];
                for (size_t i = 0; i < obj.nums; ++i)
                {
                    arr[i] = obj.arr[i];
                }
            }
            else cout << "object.m_num =0 or object.m_res is null ptr" << endl;
        }

        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& obj)noexcept
    {
        if (this != &obj)
        {
            if (obj.nums && obj.arr)
            {
                nums = obj.nums;
                delete[] arr;
                arr = obj.arr;
                obj.arr = nullptr;
            }
            else cout << "object.m_num =0 or object.m_res is null ptr" << endl;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
    {
        bool ok = false;

        if (nums)
        {
            for (size_t i = 0; i < nums; ++i)
            {
                if (arr[i] == &res) ok = true;
            }
        }

        if (!ok)
        {
            const Reservation** temp = nullptr;
            temp = arr;
            arr = nullptr;
            arr = new const Reservation * [nums + 1];
            for (unsigned i = 0; i < nums; i++)
            {
                arr[i] = temp[i];
            }
            arr[nums++] = &res;
            delete[] temp;
        }

        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
    {
        bool ok = false;
        unsigned index = 0;

        for (index = 0; index < nums; ++index)
        {
            if (arr[index] == &res)
            {
                ok = true;
                break;
            }
        }

        if (ok)
        {
            arr[index] = nullptr;
            const Reservation** temp = nullptr;
            temp = arr;
            arr = nullptr;
            nums--;
            arr = new const Reservation * [nums];
            for (size_t j = 0; j < nums; ++j)
            {
                if (j < index)arr[j] = temp[j];
                else arr[j] = temp[j + 1];

            }
            delete[] temp;
        }

        return *this;
    }

    ostream& operator<<(ostream& os, const ConfirmationSender& conf)
    {
        os << "--------------------------\nConfirmations to Send\n--------------------------\n";

        if (conf.nums && conf.arr)
        {
            for (size_t i = 0; i < conf.nums; ++i)
            {
                os << *conf.arr[i];
            }
        }
        else
        {
            os << "There are no confirmations to send!\n";
        }

        os << "--------------------------\n";

        return os;
    }
}


