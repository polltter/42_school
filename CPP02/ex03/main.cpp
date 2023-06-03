#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point a(0, 0);
    Point b(5, 0);
    Point c(2.5, 5);

    Point point(0, 0);
    std::cout << bsp(a, b, c, point) << std::endl;
    return 0;
}