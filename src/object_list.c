#include "object_list.h"

lgc_objectlist_t lgc_objectlist_create() {
  int initial_size = 10;
  lgc_object_t **objects = malloc(sizeof(lgc_object_t*) * initial_size);

  lgc_objectlist_t lst;
  lst.capacity = initial_size;
  lst.size = 0;
  lst.objects = objects;

  return lst;
}

void lgc_objectlist_push(lgc_objectlist_t* list, lgc_object_t *obj) {
  list->objects[list->size] = obj;
  list->size += 1;

  if (list->size == list->capacity) {
    int new_capacity = list->capacity * 2;
    realloc(list->objects, sizeof(lgc_object_t*) * new_capacity); 
    list->capacity = new_capacity;
  }
}

void lgc_objectlist_free(lgc_objectlist_t* lst) {
  free(lst->objects);
}
