/*A rectangle with sides equal to even integers a and b is drawn on the Cartesian plane. 
Its center (the intersection point of its diagonals) coincides with the point (0, 0), 
but the sides of the rectangle are not parallel to the axes; 
instead, they are forming 45 degree angles with the axes.

How many points with integer coordinates are located inside the given rectangle (including on its sides)?*/

#include <math.h>

long long rectangle_rotation(int a, int b)
{
    double ah = a/sqrt(2), bh = b/sqrt(2);
    long long count = floor(ah) * floor(bh) + ceil(ah) * ceil(bh);
    return count % 2 ? count : count - 1;
}
