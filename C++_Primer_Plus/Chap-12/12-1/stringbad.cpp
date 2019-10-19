// stringbad.h -- Stringbad class methods
#include <cstring>
#include <ostream>
#include "stringbad.h"
using std::cout;

// initiallizing static class number
int Stringbad::num_strings = 0;

// class methods
// construct Stringbad from C string
Stringbad::Stringbad(const char *s)
{
    len = std::strlen(s);
    str = new char(len + 1);
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" < str << "\" object created\n";
}

Stringbad::Stringbad()
{
    len = 4;
    str = new char(4);
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" < str << "\" object created\n";
}

Stringbad::~Stringbad()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete[] str;
}

std::ostream &operator<<(std::ostream &os, const Stringbad &st)
{
    os << st.str;
    return os;
}