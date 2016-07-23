#ifndef ALLOCATOR_H
#define ALLOCATOR_H

typedef struct lgc_context_t lgc_context_t;
typedef struct lgc_object_t lgc_object_t;


struct lgc_object_t {
  lgc_object_t** objects;
  void* data; // the data!
  int in_reference_count;
  int out_reference_count; //this is effectively how many elements are in objects
};

struct lgc_context_t {
  struct lgc_object_t objects[1000];//TODO: make this dynamic
  int number_objects; // the number of objects in objects
};

lgc_context_t lgc_new_context();

lgc_object_t lgc_allocate(int size);

void lgc_free(lgc_object_t* obj);

void lgc_reference(lgc_object_t *from, lgc_object_t *to);

void lgc_destroy_context(lgc_context_t* ctx);

#endif
