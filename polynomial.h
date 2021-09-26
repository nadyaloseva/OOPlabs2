#ifndef TPOLYNOMIAL_H
#define TPOLYNOMIAL_H

#include <ostream>
#include "number.h"

class TPolynomial
{
    number a_;
    number b_;
    number c_;
    number argument_;

public:
    TPolynomial( const number, const number, const number, const number );

    friend std::ostream& operator<<( std::ostream&, const TPolynomial& );

    void set_coefficients( const number, const number, const number );
    void set_argument( const number );

    number get_a() const;

    bool has_roots( number* ) const;
    number result() const;
};

#endif // TPOLYNOMIAL_H
