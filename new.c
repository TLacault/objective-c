#include <stdbool.h>
#include "new.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    Object *new_object = NULL;

    if (!class)
        raise("out of memory");
    new_object = malloc(sizeof(Object) * class->__size__);
    if (new_object == NULL)
        raise("out of memory");
    memcpy(new_object, class, sizeof(Class));
    va_list args;
    va_start(args, class);
    if (class->__ctor__)
        class->__ctor__(new_object, &args);
    va_end(args);
    return (new_object);
}

void delete(Object *ptr)
{
    Class *tmp = NULL;
    if (!ptr)
        raise("out of memory");
    tmp = ptr;
    if (tmp->__dtor__)
        tmp->__dtor__(ptr);
    free(tmp);
}

Object *va_new(const Class *class, va_list* ap)
{
    Object *new_object = NULL;

    if (!class)
        raise("out of memory");
    new_object = malloc(sizeof(Object) * class->__size__);
    if (new_object == NULL)
        raise("out of memory");
    memcpy(new_object, class, sizeof(Class));
    if (class->__ctor__)
        class->__ctor__(new_object, ap);
    return (new_object);
}