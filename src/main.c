#include <stdio.h>

#include "allocator.h"

int main() {
  printf("hello\n");
  int four = 4;

  lgc_object_t obj = lgc_allocate(1);
  *((int *)obj.data.heapMemory) = 3;

  lgc_object_t obj2 = lgc_allocate(2);
  lgc_reference(&obj, &obj2);

  *((int *)obj2.data.heapMemory) = 4;

  printf("outreferences to obj1 %d\n", obj.out_reference_count);

  lgc_free(&obj);

  printf("outreferences to obj1 %d\n", obj.out_reference_count);
}
