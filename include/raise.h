#pragma once

#include <stdio.h>
#include <stdlib.h>

#define raise(msg)
    do {
        fprintf(stderr, "%s: %u: %s\n", __FILE__, __LINE__, msg);
        abort();
} while (0)
