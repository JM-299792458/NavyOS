/*
 * Copyright (C) 2020 Jordan DALCQ & contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* I define the Libc, so I can add everything I want ok ? */

#ifndef _NAVY_LIBC_VECTOR_H_
#define _NAVY_LIBC_VECTOR_H_

#include <stddef.h>

typedef struct 
{
    void **array;
    size_t length;
    size_t capacity;
} Vector;

void init_vector(Vector *);
void vector_free(Vector *);
void vector_push_back(Vector *, void *);
void *vector_pop_back(Vector *);
void *vector_get(Vector, size_t);
void vector_dump_str(Vector);

char *vector_join(Vector, char);

Vector vector_split(char *, char);

#endif