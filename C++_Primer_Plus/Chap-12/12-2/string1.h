// string1.h -- fixed and augmented string class definition
#include <iostream>
using std::istream;
using std::ostream;
#ifndef STRING1_H_
#define STRING1_H_
class Stringbad
{
private:
    char *str;
    int len;
    static int num_strings;

public:
    Stringbad(const char *s);
    Stringbad();
    ~Stringbad();
    // friend function
    friend std::ostream &operator<<(std::ostream &os, const Stringbad &st);
};

#endif