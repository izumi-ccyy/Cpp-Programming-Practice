// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include "stonewt1.h"
#include <iostream>
using std::cout;

void display(const Stonewt &st, int n);
int main()
{
    Stonewt poppins(9, 2.8);
    double p_wt = poppins;
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Conver to int => ";
    cout << "Popins: " << int(poppins) << " pounds.\n";
    return 0;
}