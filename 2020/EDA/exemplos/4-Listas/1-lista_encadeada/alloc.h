#ifndef ALLOC_H
#define ALLOC_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Chama o malloc tradicional, e trata se houver algum problema
void *mallocx(size_t n);

// Chama o calloc tradicional, e trata se houver algum problema
void *callocx(size_t n, size_t s);

// Chama o realloc tradicional, e trata se houver algum problema
void *reallocx(void *ptr, size_t n);

#endif
