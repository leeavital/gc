#include "../src/allocator.h"

#include <stdio.h>
#include <assert.h>

int main() {
  printf("ok\n");

  lgc_object_t root = lgc_allocate(4);
  lgc_object_t left = lgc_allocate(4);
  lgc_object_t right = lgc_allocate(4);

  assert(root.in_reference_count == 0);
  assert(root.out_reference_count == 0);
  assert(left.in_reference_count == 0);
  assert(left.out_reference_count == 0);
  assert(right.in_reference_count == 0);
  assert(right.out_reference_count == 0);

  lgc_reference(&root, &left);
  lgc_reference(&root, &right);

  assert(root.in_reference_count == 0);
  assert(root.out_reference_count == 2);
  assert(left.in_reference_count == 1);
  assert(left.out_reference_count == 0);
  assert(right.in_reference_count == 1);
  assert(right.out_reference_count == 0);

  lgc_free(&root);

  assert(root.in_reference_count == 0);
  assert(root.out_reference_count == 0);
  assert(left.in_reference_count == 0);
  assert(left.out_reference_count == 0);
  assert(right.in_reference_count == 0);
  assert(right.out_reference_count == 0);


}
