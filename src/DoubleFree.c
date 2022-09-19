//
// Created by sure on 2022-07-22.
//

#include "DoubleFree.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getFree()
{
    char *a, *b, *c;
    char *d, *e, *f;

    a = malloc(0x20);
    b = malloc(0x20);
    c = malloc(0x20);

    strcpy(a, "AAAAAAAA");
    strcpy(b, "BBBBBBBB");
    strcpy(c, "CCCCCCCC");

    printf("a = %p\n", a);
    printf("b = %p\n", b);
    printf("c = %p\n", c);

    free(a);
    free(b);
    free(a); // Fix: remove this

    d = malloc(0x20);
    e = malloc(0x20);
    f = malloc(0x20);

    printf("a = %p\n", d);
    printf("b = %p\n", e);
    printf("c = %p\n", f);

    return 0;
}