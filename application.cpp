#include <conio.h>
#include <iostream>
#include <regex>
#include <string>
#include "application.h"
#include "polynomial.h"

constexpr int size = 5;
const char* error = "You need to input the coefficients first.";
const char* menu[ size ]
{
    "Input coefficients",
    "Calculate roots",
    "Calculate polynomial",
    "Print polynomial",
    "Exit"
};

TApplication::TApplication( const int option ) :
    option_ { option }
{
}

void TApplication::set_option( const int option )
{
    option_ = option;
}

int TApplication::get_option() const
{
    return option_;
}

number TApplication::input( const int option ) const
{
    const std::string name{ option < 3 ?
                    std::string{ static_cast<char>( option + 97 ) }
                                       : "argument" };

    while ( true )
    {
        std::string input{};

        std::cout << "Input the " << name << ": ";

        std::cin >> input;

        std::cin.ignore( std::cin.rdbuf()->in_avail() );

        if ( std::cin.fail() )
        {
            std::cin.clear();
        }
        else if ( std::regex_match(
                  input, std::regex{ "^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$" } )
                  && ( option || std::stold( input ) ) )
        {
            return std::stod( input );
        }
    }
}

int TApplication::menus() const
{
    int code = 0;
    int key = 0;

    while( code != 13 )
    {
        system( " cls || clear " );

        key = ( key + size ) % size;

        for ( int index = 0; index < size; ++index )
        {
            std::cout << ( index == key ? '>' : '\0' )
                      << menu[ index ]
                      << '\n';
        }
        if ( code = _getch(); code != 13 && ( code == 80 || code == 115 ) )
        {
           ++key;
        }
        else if ( code == 72 || code == 119 )
        {
            --key;
        }
    }

    system( " cls || clear " );

    return key;
}

int TApplication::run()
{
    TPolynomial polynomial{ 0.0, 0.0, 0.0, 0.0 };

    while ( true )
    {
        set_option( menus() );

        switch ( get_option() )
        {
            case 0:
            {
                number a = input( 0 );
                number b = input( 1 );
                number c = input( 2 );

                polynomial.set_coefficients( a, b, c );

                back();

                break;
            }
            case 1:
            {
                if ( polynomial.get_a() )
                {
                    number roots[ 2 ]{ 0.0 };

                    std::cout << polynomial << "=0 has ";

                    if ( polynomial.has_roots( roots ) )
                    {
                        std::cout << "two real roots:\n\nx_1 = "
                                  << roots[ 0 ]
                                  << "\nx_2 = "
                                  << roots[ 1 ];
                    }
                    else
                    {
                        std::cout << "no real roots.";
                    }
                }
                else
                {
                    std:: cout << error;
                }
                back();

                break;
            }
            case 2:
            {
                if ( polynomial.get_a() )
                {
                    polynomial.set_argument( input( 3 ) );

                    std::cout << polynomial << "=" << polynomial.result();

                    polynomial.set_argument( 0.0 );
                }
                else
                {
                    std:: cout << error;
                }
                back();

                break;
            }
            case 3:
            {
                if ( polynomial.get_a() )
                {
                    std::cout << polynomial;
                }
                else
                {
                    std:: cout << error;
                }
                back();

                break;
            }
            case 4:
            {
                return 0;
            }
        }
    }
}

void TApplication::back() const
{
    std::cout << "\n\n>Back";

    int code = 0;

    while ( code != 13 )
    {
        code = _getch();
    }
}
