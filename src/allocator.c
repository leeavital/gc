#include <stdlib.h>

#include "allocator.h"
#include <stdio.h>

lgc_object_t lgc_allocate(int size) {
  void *data = malloc(size);
  // maximum of 100 outreferences
  lgc_object_t **out_references = malloc(sizeof(void *) * 100);

  lgc_object_t obj;
  obj.memory_type = HEAP;
  obj.data.heapMemory = data;
  obj.objects = out_references;
  obj.in_reference_count = obj.out_reference_count = 0;
  return obj;
}

lgc_object_t lgc_string(char *str) {
  lgc_object_t obj;

  obj.memory_type = STR;
  obj.data.constString = str;
  obj.in_reference_count = obj.out_reference_count = 0;

  return obj;
}

void lgc_reference(lgc_object_t *from, lgc_object_t *to) {
  from->objects[from->out_reference_count] = to;
  from->out_reference_count += 1;
  to->in_reference_count += 1;
}

void lgc_free(lgc_object_t *obj) {
  if (obj->in_reference_count == 0) {
    // if this object points to heap memory, remove it from the heap
    if (obj->memory_type == HEAP) {
      free(obj->data.heapMemory);
    }

    for (int i = 0; i < obj->out_reference_count; i++) {
      lgc_object_t *child = obj->objects[i];
      child->in_reference_count -= 1;
      lgc_free(child);
    }
    // technically this should be useless information, but
    obj->out_reference_count = 0;
  } else if (obj->in_reference_count < 0) {
    // probably a double free
  }
}

void lgc_print_object(lgc_object_t *obj) {
  printf("Object{in_reference_count=%d, \
      out_reference_count=%d}\n",
         obj->in_reference_count, obj->out_reference_count);
}
