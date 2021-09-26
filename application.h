#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include "number.h"

class TApplication
{
    int option_;

public:
    TApplication( const int );

    void set_option( const int );

    int get_option() const;

    number input( const int ) const;

    int menus() const;
    int run();
    void back() const;
};

#endif // TAPPLICATION_H
