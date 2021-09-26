#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include <iostream>
using namespace std;

class Tcomplex
{
    double re, im;
public:
    Tcomplex();
    Tcomplex(int);

    Tcomplex operator*(TComplex);
    Tcomplex operator+(TComplex);

    friend istream& operator>> (istream&, Tcomplex&);
    friend ostream& operator>> (ostream&, Tcomplex);
};

#endif // TCOMPLEX_H
