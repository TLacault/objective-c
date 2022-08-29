#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"

void compareAndDivide (Object *a, Object *b)
{
    if (gt (a, b))
        printf("a > b \n");
    else if (lt(a, b))
        printf("a < b \n");
    else
        printf("a == b \n");

    printf("b / a = %s \n", str(division(a, b)));
}

int         main(void)
{
    Object  *x2 = new(Point, 10, 20);
    Object  *x1 = new(Point, 5, 5);
    compareAndDivide(x1, x2);

    Object  *y2 = new(Vertex, 10, 20, 30);
    Object  *y1 = new(Vertex, 5, 5, 5);
    compareAndDivide(y1, y2);

    return (0);
}
