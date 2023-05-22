//
// Created by miguel on 21-05-2023.
//

#include "Point.hpp"

Fixed det(const Point& a, const Point& b) {
    return ((a.getX() * b.getY()) - (a.getY() * b.getX()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Point vb = b - a;
    Point vc = c - a;
    Fixed det1 = (det(point, vc) - det(a, vc)) / det(vb, vc);
    Fixed det2 = (det(a, vb) - det(point, vb)) / det(vb, vc);

    return (det1.toFloat() > 0 && det2.toFloat() > 0 && (det1 + det2).toFloat() < 1);
}