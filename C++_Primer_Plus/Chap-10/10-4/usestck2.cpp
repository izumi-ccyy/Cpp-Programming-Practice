// usestck02.cpp -- the client program
// compile with stock00.cpp
#include "stock02.h"
#include <iostream>

const int SKTS = 4;
int main()
{
    // create an array of initialized objects
    Stock stocks[SKTS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < SKTS; st++)
        stocks[st].show();

    // set pointer to first element
    const Stock *top = &stocks[0];
    for (st = 1; st < SKTS; st++)
        top = &top->topval(stocks[st]);
    // now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
    top->show();

    return 0;
}