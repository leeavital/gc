#ifndef ALLOCATOR_H
#define ALLOCATOR_H

typedef struct lgc_object_t lgc_object_t;

enum lgc_memory_type_t {
  HEAP, STR
};

struct lgc_object_t {
  lgc_object_t **objects;
  
  // see lgc_memory_type_t
  enum lgc_memory_type_t memory_type;
  union {
    void* heapMemory;
    char* constString;
  } data;


  // counters for how many objects reference this object and how many objects this object refernces.
  // when the former reaches zero, this object can be freed along with any objects who have this object
  // their sole parent.
  int in_reference_count;
  int out_reference_count;
};

/**
 * allocate an lgc_object_t on the heap. The allocated memory can be safely
 * freed
 * using lgc_free.
 */
lgc_object_t lgc_allocate(int size);

/**
 * allocate an object which points to a string.
 */
lgc_object_t lgc_string(char* str);

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
