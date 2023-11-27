//
// Created by miguel on 16-10-2023.
//
#include "whatever.hpp"

struct Data
{
    int content;
};

int main( void )
{
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	Data	*e = new Data;
	Data	*f = new Data;
	e->content = 5;
    f->content = 10;

    ::swap(e, f);
    std::cout << "e = " << e->content << ", f = " << f->content << std::endl;
    std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

    delete e;
    delete f;

    return 0;
}