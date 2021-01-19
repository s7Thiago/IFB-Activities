#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Imprime os elementos de um vetor de inteiros
void printv(int* v, size_t size);

// Chama o malloc tradicional, e trata se houver algum problema
void* mallocx(size_t n);

// Chama o calloc tradicional, e trata se houver algum problema
void* callocx(size_t n, size_t s);

// Chama o realloc tradicional, e trata se houver algum problema
void* reallocx(void* ptr ,size_t n);

// Gera um vetor de inteiros com tamanho predefinido
int* generateEntry(int range);

#endif
