#ifndef ALLOCATOR_H
#define ALLOCATOR_H

typedef struct lgc_object_t lgc_object_t;

struct lgc_object_t {
  lgc_object_t** objects;
  void* data; // the data!
  int in_reference_count;
  int out_reference_count; //this is effectively how many elements are in objects
};

lgc_object_t lgc_allocate(int size);

void lgc_free(lgc_object_t* obj);

void lgc_reference(lgc_object_t *from, lgc_object_t *to);

void lgc_print_object(lgc_object_t*);

#endif
