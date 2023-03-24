#include "Point.hpp"
#include "Fixed.hpp"

void paint(Point const a, Point const b, Point const c)
{
    std::cout << "A(" << a.getX() << ", " << a.getY() << ")" << std::endl;
    std::cout << "B(" << b.getX() << ", " << b.getY() << ")" << std::endl;
    std::cout << "C(" << c.getX() << ", " << c.getY() << ")" << std::endl << std::endl;

    int inside = 0;
    std::cout << " y" << std::endl;
    for (int y = 9; y >= 0; y--)
    {
        std::cout << y << " |";
        for (int x = 0; x < 20; x++)
        {
            Point tmp_a(a.getX().toInt() * 2, a.getY().toInt());
            Point tmp_b(b.getX().toInt() * 2, b.getY().toInt());
            Point tmp_c(c.getX().toInt() * 2, c.getY().toInt());
            inside = bsp(tmp_a, tmp_b, tmp_c, Point(x, y));
            if (x == a.getX().toInt() * 2 && y == a.getY().toInt())
                std::cout << "A";
            else if (x == b.getX().toInt() * 2 && y == b.getY().toInt())
                std::cout << "B";
            else if (x == c.getX().toInt() * 2 && y == c.getY().toInt())
                std::cout << "C";
            else if (inside)
                std::cout << ".";
            else
                std::cout << " ";
            inside = 0;
        }
        std::cout << std::endl;
        if (y == 0)
        {
            std::cout << "  +------------------- x" << std::endl;
            std::cout << "   0 1 2 3 4 5 6 7 8 9" << std::endl;
        }
    }
    std::cout << std::endl;
}

int main(void)
{
    Point a(1, 1);
    Point b(4, 1.5f);
    Point c(4, 4);

    paint(a, b, c);
    std::cout << "Point 1: " << (bsp(a, b, c, Point(5, 3)) ? "YES!" : "NO!") << std::endl;
    std::cout << "Point 2: " << (bsp(a, b, c, Point(3, 2)) ? "YES!" : "NO!") << std::endl;
    std::cout << "Point 3: " << (bsp(a, b, c, Point(2, 1)) ? "YES!" : "NO!") << std::endl;
    std::cout << "Point 4: " << (bsp(a, b, c, Point(3.75f, 3.25f)) ? "YES!" : "NO!") << std::endl;
    

    return 0;
}
