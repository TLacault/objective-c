#include <stdio.h>
#include <stdbool.h>
#include "new.h"
#include "point.h"
#include "object.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this)
        raise("Out of memory");
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static char *Point_str(PointClass *this)
{
    char *buffer = malloc(sizeof(char) * this->base.__size__);

    if (buffer == NULL)
        raise("Out of memory");
    snprintf(buffer, this->base.__size__, "<Point (%d, %d)>", this->x, this->y);
    return (buffer);
}

static PointClass *Point_add(PointClass *this, PointClass *other)
{
    PointClass *new_point = new(Point, 0, 0);

    if (!this || !other || !new_point)
        raise("Out of memory");
    new_point->x = (this->x + other->x);
    new_point->y = (this->y + other->y);
    return (new_point);
}

static PointClass *Point_sub(PointClass *this, PointClass *other)
{
    PointClass *new_point = new(Point, 0, 0);

    if (!this || !other || !new_point)
        raise("Out of memory");
    new_point->x = (this->x - other->x);
    new_point->y = (this->y - other->y);
    return (new_point);
}

static PointClass *Point_mul(PointClass *this, PointClass *other)
{
    PointClass *new_point = new(Point, 0, 0);

    if (!this || !other || !new_point)
        raise("Out of memory");
    new_point->x = (this->x * other->x);
    new_point->y = (this->y * other->y);
    return (new_point);
}

static PointClass *Point_div(PointClass *this, PointClass *other)
{
    PointClass *new_point = new(Point, 0, 0);

    if (!this || !other || !new_point)
        raise("Out of memory");
    else if (other->x == 0 || other->y == 0)
        raise("Error division by zero is not allowed");
    new_point->x = (this->x / other->x);
    new_point->y = (this->y / other->y);
    return (new_point);
}

static bool Point_eq(PointClass *this, PointClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->x == other->x && this->y == other->y)
        return (true);
    return (false);
}

static bool Point_gt(PointClass *this, PointClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->x > other->x && this->y > other->y)
        return (true);
    return (false);
}

static bool Point_lt(PointClass *this, PointClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->x < other->x && this->y < other->y)
        return (true);
    return (false);
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = (binary_operator_t)&Point_mul,
        .__div__ = (binary_operator_t)&Point_div,
        .__eq__ = (binary_comparator_t)&Point_eq,
        .__gt__ = (binary_comparator_t)&Point_gt,
        .__lt__ = (binary_comparator_t)&Point_lt
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
