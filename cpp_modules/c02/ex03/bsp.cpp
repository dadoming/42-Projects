# include "Point.hpp"

static Fixed my_abs(Fixed const value)
{
    return (value < 0 ? (value * -1) : value);
}

static Fixed area(Point const a, Point const b, Point const c)
{
    return (((b.getX() - a.getX()) * (c.getY() - a.getY()) - \
            (c.getX() - a.getX()) * (b.getY() - a.getY())) \
            / 2);
}

// Split the triangle in 3 and if point is inside, the area has to be equal to the sum of the 3 areas
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    /*
    if ((  a.getX() == point.getX() && a.getY() == point.getY()) \
        || b.getX() == point.getX() && b.getY() == point.getY() \
        || c.getX() == point.getX() && c.getY() == point.getY())
        return (false); //point is on the vertice
    Fixed triangleArea = my_abs(area(a, b, c));
    Fixed area1 = my_abs(area(point, a, b)); //area PAB 
    Fixed area2 = my_abs(area(point, b, c)); //area PBC
    Fixed area3 = my_abs(area(point, c, a)); //area PCA
    Fixed sum = area1 + area2 + area3;

    return (sum.operator==(triangleArea));
    */

    Fixed w1 = (a.getX() * (c.getY() - a.getY()) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY())) /\
                ((b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()));

    Fixed w2 = (point.getY() - a.getY() - w1 * (b.getY() - a.getY())) / (c.getY() - a.getY());

    return (w1 > 0 && w2 > 0 && (w1 + w2) < 1);
}
