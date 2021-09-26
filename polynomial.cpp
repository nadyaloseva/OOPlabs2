#include <cmath>
#include <sstream>
#include "polynomial.h"
#include "string"

TPolynomial::TPolynomial( const number a,
                          const number b,
                          const number c,
                          const number argument ) :
    a_ { a }, b_ { b }, c_ { c }, argument_ { argument }
{
}

std::ostream& operator<<( std::ostream& ostream, const TPolynomial& polynomial )
{
    std::ostringstream ostringstream;

    ostringstream << polynomial.a_;

    const std::string a { ostringstream.str() };

    ostringstream.str( std::string{} );

    ostringstream << polynomial.b_;

    const std::string b { ostringstream.str() };

    ostringstream.str( std::string{} );

    ostringstream << polynomial.c_;

    const std::string c { polynomial.c_ ? ostringstream.str() : "" };

    ostringstream.str( std::string{} );

    ostringstream << polynomial.argument_;

    const std::string argument { '*' +
                                 ( polynomial.argument_ ? ostringstream.str()
                                                   : "x" ) };

    ostream << a
            << argument
            << "^2"
            << ( polynomial.b_ > 0 ? '+' : '\0' )
            << ( polynomial.b_ ? b + argument : "")
            << ( polynomial.c_ > 0 ? '+' : '\0' )
            << ( polynomial.c_ ? c : "");

    return ostream;
}

void TPolynomial::set_coefficients( const number a,
                                    const number b,
                                    const number c )
{
    a_ = a;
    b_ = b;
    c_ = c;
}

void TPolynomial::set_argument( const number argument )
{
    argument_ = argument;
}

number TPolynomial::get_a() const
{
    return a_;
}

bool TPolynomial::has_roots( number* roots ) const
{
    if ( const number discriminant = b_ * b_ - 4 * a_ * c_; !discriminant )
    {
        roots[ 0 ] = roots[ 1 ] = -b_ / ( 2 * a_ );
    }
    else if ( discriminant > 0)
    {
        roots[ 0 ] = ( -b_ - std::sqrt( discriminant ) ) / ( 2 * a_ );
        roots[ 1 ] = ( -b_ + std::sqrt( discriminant ) ) / ( 2 * a_ );
    }
    else
    {
        return false;
    }
    return true;
}

number TPolynomial::result() const
{
    return argument_ * ( a_ * argument_ + b_ ) + c_;
}
