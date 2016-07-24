#include "../src/object_list.h"
#include <assert.h>

int main() {

  lgc_object_t obj = lgc_string("foo");

  lgc_objectlist_t lst = lgc_objectlist_create();

  for (int i = 0; i < 15; i++) {
    lgc_objectlist_push(&lst, &obj); 
  }

  assert(lst.size == 15);
  assert(lst.capacity == 20);

  for (int i = 0; i < lst.size; i++) {
    lgc_object_t *item = lst.objects[i]; 
    assert(item == &obj);
  }
}
