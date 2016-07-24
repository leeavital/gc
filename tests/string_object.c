#include "../src/allocator.h"
#include <assert.h>

int main() {

  lgc_object_t root = lgc_string("hello world!");

  lgc_free(&root);
  // don't segfault
}
