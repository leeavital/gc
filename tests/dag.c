#include "../src/allocator.h"
#include <assert.h>

int main() {
  lgc_object_t root = lgc_allocate(1);
  lgc_object_t left = lgc_allocate(1);
  lgc_object_t right = lgc_allocate(1);
  lgc_object_t bottom = lgc_allocate(1);

  lgc_reference(&root, &left);
  lgc_reference(&root, &right);
  lgc_reference(&left, &bottom);
  lgc_reference(&right, &bottom);

  assert(bottom.in_reference_count == 2);

  lgc_free(&root);

  assert(bottom.in_reference_count == 0);
}
