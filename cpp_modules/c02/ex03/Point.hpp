#ifndef  _POINT_HPP_
# define _POINT_HPP_

# include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point(void);
        Point(float const x, float const y);
        Point(const Point& other);
        ~Point(void);

        Point & operator=(const Point& copy);
        Fixed getX(void) const;
        Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

# endif
