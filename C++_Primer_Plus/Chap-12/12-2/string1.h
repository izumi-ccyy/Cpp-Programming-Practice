// string1.h -- fixed and augmented string class definition
#include <iostream>
using std::istream;
using std::ostream;
#ifndef STRING1_H_
#define STRING1_H_
class String
{
private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

public:
    // constructors and other methods
    String(const char *s);
    String();
    String(const String &);
    ~String();
    int length() const { return len; }
    // overloading operator methods
    String &operator=(const String &);
    String &operator=(const char *);
    char &operator[](int i);
    const char &operator[](int i) const;
    // overloaded operator friends
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream &operator<<(ostream &os, const String &st);
    friend istream &operator>>(istream &is, String &st);
    // static function
    static int HowMany();
};

#endif

// comment