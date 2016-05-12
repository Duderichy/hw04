#include <stdio.h>
#include <math.h>


struct point
{
    double x;
    double y;
};


struct triangle
{
    struct point a;
    struct point b;
    struct point c;
};

double area (struct triangle t);

double area (struct triangle t)
{
    double s;

    s = 0.5 * fabs ((t.b.x - t.a.x) * (t.c.y - t.a.y) - (t.c.x -
            t.a.x) * (t.b.y - t.a.y));
    return s;
}

double distancepoints(struct point a, struct point b);
/*
This function takes two point structs as inputs and calculates the distance
between them using the following formula sqrt((x1-x2)^2+(y1-y2)^2)
*/

double distancepoints(struct point a, struct point b)
{
  double x = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
  return x;
}

double perimetertriangle (struct triangle t);
/*
This function takes a triangle struct as input and computes the distance between
all the points using the distancepoints function
*/

double perimetertriangle (struct triangle t)
{
  double ab = distancepoints(t.a,t.b);
  double bc = distancepoints(t.b, t.c);
  double ca = distancepoints(t.c, t.a);

  double p = ab + bc + ca;

  return p;
}



int main (void)
{
    struct triangle t = (struct triangle) { {2, 2.}, {4., 4}, {8., 8.} };

    double a = area (t);

    double p = perimetertriangle(t);

    printf ("area = %f\n", a);
    printf ("perimeter = %f\n", p);
    printf ("radius = %f\n", 2*a/p);

    return 0;
}
