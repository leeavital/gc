#ifndef OBJECT_LIST_H
#define OBJECT_LIST_H

#include <stdlib.h>
#include "allocator.h"

/**
 * Dynamically sized list of lgc_object_t
 */
typedef struct lgc_objectlist_t {
  lgc_object_t **objects;
  int size;
  int capacity;
} lgc_objectlist_t;

lgc_objectlist_t lgc_objectlist_create();

void lgc_objectlist_push(lgc_objectlist_t* list, lgc_object_t *obj);

#endif
