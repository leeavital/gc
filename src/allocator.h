#ifndef ALLOCATOR_H
#define ALLOCATOR_H

typedef struct lgc_object_t lgc_object_t;

struct lgc_object_t {
  lgc_object_t **objects;
  void *data; // the data!
  int in_reference_count;
  int out_reference_count; // this is effectively how many elements are in
                           // objects
};

/**
 * allocator an lgc_object_t on the heap. The allocated memory can be safely
 * freed
 * using lgc_free.
 */
lgc_object_t lgc_allocate(int size);

/**
 * Safely free any heap data contained in the passed lgc_object_t
 */
void lgc_free(lgc_object_t *obj);

/**
 * Update the object graph to say "from now holds a reference to to".
 *
 * This object graph will be respected when calling lgc_free.
 */
void lgc_reference(lgc_object_t *from, lgc_object_t *to);

/**
 * Only useful for debugging
 */
void lgc_print_object(lgc_object_t *);

#endif
