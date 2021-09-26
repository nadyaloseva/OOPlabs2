#include "complex.h"

Tcomplex::Tcomplex()
{

re=0;
im=0;

}
Tcomplex::Tcomplex(int v){
    re=v;
    im=0;

}

Tcomplex Tcomplex:: operator*(TComplex c)
{
    Tcomplex temp;
    temp.re=re*c.re-im*c.im;
    temp.im=re*c.im+im*c.re;
    return temp;
}

Tcomplex Tcomplex::  operator+(TComplex c)
{
    Tcomplex temp;
    temp.re=re+c.re;
    temp.im=im+c.im;
    return temp;
}

istream& operator>> (istream& is, Tcomplex& c)
{
    is>>c.re>>c.im;
    return is;

}

ostream& operator>> (ostream& os, Tcomplex c){
    os<<"("<<c.re<<"+"<<c.im<< "i)";
    return os;

}
