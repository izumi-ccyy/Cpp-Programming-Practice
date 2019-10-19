// string1.h -- String class methods
#include "string1.h"
#include <cstring>
#include <string.h>
using std::cin;
using std::cout;

// initiallizing static class number
int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
// construct String from C string
String::String(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    strcpy_s(str, len + 1, s);
    num_strings++;
}

String::String()
{
    len = 1;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String &st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy_s(str, len + 1, st.str);
}

String::~String()
{
    --num_strings;
    delete[] str;
}

// overloaded operator methods
//assign a String to a String
String &String::operator=(const String &st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    strcpy_s(str, len + 1, st.str);
    return *this;
}

//assign a C string to a String
String &String::operator=(const char *s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    strcpy_s(str, len + 1, s);
    return *this;
}

// read-write char access for non-const String
char &String::operator[](int i)
{
    return str[i];
}

// read-only char access for const String
const char &String::operator[](int i) const
{
    return str[i];
}

// overload operator friends
bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

// quick and dirty String input
istream &operator>>(istream &is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}