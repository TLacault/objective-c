#include <stdio.h>
#include <stdbool.h>
#include "new.h"
#include "float.h"
#include "object.h"

typedef struct
{
    Class   base;
    float     a;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        raise("Out of memory");
    this->a = (float)va_arg((*args), double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static char *Float_str(FloatClass *this)
{
    char *buffer = malloc(sizeof(char) * this->base.__size__);

    if (buffer == NULL)
        raise("Out of memory");
    snprintf(buffer, this->base.__size__, "<Float (%f)>", this->a);
    return (buffer);
}

static FloatClass *Float_add(FloatClass *this, FloatClass *other)
{
    FloatClass *new_Float = new(Float, 0, 0);

    if (!this || !other || !new_Float)
        raise("Out of memory");
    new_Float->a = (this->a + other->a);
    return (new_Float);
}

static FloatClass *Float_sub(FloatClass *this, FloatClass *other)
{
    FloatClass *new_Float = new(Float, 0, 0);

    if (!this || !other || !new_Float)
        raise("Out of memory");
    new_Float->a = (this->a - other->a);
    return (new_Float);
}

static FloatClass *Float_mul(FloatClass *this, FloatClass *other)
{
    FloatClass *new_Float = new(Float, 0, 0);

    if (!this || !other || !new_Float)
        raise("Out of memory");
    new_Float->a = (this->a * other->a);
    return (new_Float);
}

static FloatClass *Float_div(FloatClass *this, FloatClass *other)
{
    FloatClass *new_Float = new(Float, 0, 0);

    if (!this || !other || !new_Float)
        raise("Out of memory");
    else if (other->a == 0)
        raise("Error division by zero is not allowed");
    new_Float->a = (this->a / other->a);
    return (new_Float);
}

static bool Float_eq(FloatClass *this, FloatClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->a == other->a)
        return (true);
    return (false);
}

static bool Float_gt(FloatClass *this, FloatClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->a > other->a)
        return (true);
    return (false);
}

static bool Float_lt(FloatClass *this, FloatClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->a < other->a)
        return (true);
    return (false);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .a = 0
};

const Class   *Float = (const Class *)&_description;