#include "../src/allocator.h"
#include <assert.h>

int main() {
  lgc_object_t root =  lgc_allocate(1);
  lgc_object_t next = lgc_allocate(1);

  lgc_reference(&root, &next);
  lgc_reference(&root, &next);

  assert(root.out_reference_count == 2);

  lgc_free(&root);
}
