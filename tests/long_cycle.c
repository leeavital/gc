#include "../src/allocator.h"
#include <assert.h>

int main() {
  lgc_object_t one =  lgc_allocate(1);
  lgc_object_t two = lgc_allocate(1);
  lgc_object_t three = lgc_allocate(1);

  lgc_reference(&one, &two);
  lgc_reference(&two, &three);
  lgc_reference(&three, &one);

  assert(one.out_reference_count == 1);
  assert(one.in_reference_count == 1);


  lgc_print_object(&one);

  lgc_free(&one);

  lgc_print_object(&one);

  // no state change...we can't deal with cyclic dependencies
  assert(one.out_reference_count == 1);
  assert(one.in_reference_count == 1);
}
