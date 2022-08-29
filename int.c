#include <stdio.h>
#include <stdbool.h>
#include "new.h"
#include "int.h"
#include "object.h"

typedef struct
{
    Class   base;
    int     a;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!this)
        raise("Out of memory");
    this->a = va_arg((*args), int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *Int_str(IntClass *this)
{
    char *buffer = malloc(sizeof(char) * this->base.__size__);

    if (buffer == NULL)
        raise("Out of memory");
    snprintf(buffer, this->base.__size__, "<Int (%d)>", this->a);
    return (buffer);
}

static IntClass *Int_add(IntClass *this, IntClass *other)
{
    IntClass *new_Int = new(Int, 0, 0);

    if (!this || !other || !new_Int)
        raise("Out of memory");
    new_Int->a = (this->a + other->a);
    return (new_Int);
}

static IntClass *Int_sub(IntClass *this, IntClass *other)
{
    IntClass *new_Int = new(Int, 0, 0);

    if (!this || !other || !new_Int)
        raise("Out of memory");
    new_Int->a = (this->a - other->a);
    return (new_Int);
}

static IntClass *Int_mul(IntClass *this, IntClass *other)
{
    IntClass *new_Int = new(Int, 0, 0);

    if (!this || !other || !new_Int)
        raise("Out of memory");
    new_Int->a = (this->a * other->a);
    return (new_Int);
}

static IntClass *Int_div(IntClass *this, IntClass *other)
{
    IntClass *new_Int = new(Int, 0, 0);

    if (!this || !other || !new_Int)
        raise("Out of memory");
    else if (other->a == 0)
        raise("Error division by zero is not allowed");
    new_Int->a = (this->a / other->a);
    return (new_Int);
}

static bool Int_eq(IntClass *this, IntClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->a == other->a)
        return (true);
    return (false);
}

static bool Int_gt(IntClass *this, IntClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->a > other->a)
        return (true);
    return (false);
}

static bool Int_lt(IntClass *this, IntClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->a < other->a)
        return (true);
    return (false);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .a = 0
};

const Class   *Int = (const Class *)&_description;