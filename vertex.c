#include <stdio.h>
#include <stdbool.h>
#include "new.h"
#include "vertex.h"
#include "object.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this)
        raise("Out of memory");
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
    this->z = va_arg((*args), int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static char *Vertex_str(VertexClass *this)
{
    char *buffer = malloc(sizeof(char) * this->base.__size__);

    if (buffer == NULL)
        raise("Out of memory");
    snprintf(buffer, this->base.__size__, "<Vertex (%d, %d, %d)>",
    this->x, this->y, this->z);
    return (buffer);
}

static VertexClass *Vertex_add(VertexClass *this, VertexClass *other)
{
   VertexClass *new_vertex = new(Vertex, 0, 0, 0);

    if (!this || !other || !new_vertex)
        raise("Out of memory");
    new_vertex->x = (this->x + other->x);
    new_vertex->y = (this->y + other->y);
    new_vertex->z = (this->z + other->z);
    return (new_vertex);
}

static VertexClass *Vertex_sub(VertexClass *this, VertexClass *other)
{
   VertexClass *new_vertex = new(Vertex, 0, 0, 0);

    if (!this || !other || !new_vertex)
        raise("Out of memory");
    new_vertex->x = (this->x - other->x);
    new_vertex->y = (this->y - other->y);
    new_vertex->z = (this->z - other->z);
    return (new_vertex);
}

static VertexClass *Vertex_mul(VertexClass *this, VertexClass *other)
{
   VertexClass *new_vertex = new(Vertex, 0, 0, 0);

    if (!this || !other || !new_vertex)
        raise("Out of memory");
    new_vertex->x = (this->x * other->x);
    new_vertex->y = (this->y * other->y);
    new_vertex->z = (this->z * other->z);
    return (new_vertex);
}

static VertexClass *Vertex_div(VertexClass *this, VertexClass *other)
{
   VertexClass *new_vertex = new(Vertex, 0, 0, 0);

    if (!this || !other || !new_vertex)
        raise("Out of memory");
    else if (other->x == 0 || other->y == 0 || other->z == 0)
        raise("Error division by zero is not allowed");
    new_vertex->x = (this->x / other->x);
    new_vertex->y = (this->y / other->y);
    new_vertex->z = (this->z / other->z);
    return (new_vertex);
}

static bool Vertex_eq(VertexClass *this, VertexClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->x == other->x && this->y == other->y && this->z == other->z)
        return (true);
    return (false);
}

static bool Vertex_gt(VertexClass *this, VertexClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->x > other->x && this->y > other->y && this->z > other->z)
        return (true);
    return (false);
}

static bool Vertex_lt(VertexClass *this, VertexClass *other)
{
    if (!this || !other)
        raise("Out of memory");
    if (this->x < other->x && this->y < other->y && this->z < other->z)
        return (true);
    return (false);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = (binary_operator_t)&Vertex_mul,
        .__div__ = (binary_operator_t)&Vertex_div,
        .__eq__ = (binary_comparator_t)&Vertex_eq,
        .__gt__ = (binary_comparator_t)&Vertex_gt,
        .__lt__ = (binary_comparator_t)&Vertex_lt
    },
    .x = 0,
    .y = 0
};

const Class   *Vertex = (const Class *)&_description;
