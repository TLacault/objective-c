#include <stdio.h>
#include <stdbool.h>
#include "new.h"
#include "char.h"
#include "object.h"

typedef struct
{
    Class   base;
    char     c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        raise("Out of memory");
    this->c = (char)va_arg((*args), int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *Char_str(CharClass *this)
{
    char *buffer = malloc(sizeof(char) * this->base.__size__);

    if (buffer == NULL)
        raise("Out of memory");
    snprintf(buffer, this->base.__size__, "<Char (%c)>", this->c);
    return (buffer);
}

static CharClass *Char_add(CharClass *this, CharClass *other)
{
    CharClass *new_Char = new(Char, 0, 0);

    if (!this || !other || !new_Char)
        raise("Out of memory");
    new_Char->c = (this->c + other->c);
    return (new_Char);
}

static CharClass *Char_sub(CharClass *this, CharClass *other)
{
    CharClass *new_Char = new(Char, 0, 0);

    if (!this || !other || !new_Char)
        raise("Out of memory");
    new_Char->c = (this->c - other->c);
    return (new_Char);
}

static CharClass *Char_mul(CharClass *this, CharClass *other)
{
    CharClass *new_Char = new(Char, 0, 0);

    if (!this || !other || !new_Char)
        raise("Out of memory");
    new_Char->c = (this->c * other->c);
    return (new_Char);
}

static CharClass *Char_div(CharClass *this, CharClass *other)
{
    CharClass *new_Char = new(Char, 0, 0);

    if (!this || !other || !new_Char)
        raise("Out of memory");
    else if (other->c == 0)
        raise("Error division by zero is not allowed");
    new_Char->c = (this->c / other->c);
    return (new_Char);
}

static bool Char_eq(CharClass *this, CharClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->c == other->c)
        return (true);
    return (false);
}

static bool Char_gt(CharClass *this, CharClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->c > other->c)
        return (true);
    return (false);
}

static bool Char_lt(CharClass *this, CharClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->c < other->c)
        return (true);
    return (false);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0
};

const Class   *Char = (const Class *)&_description;