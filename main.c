
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "arraylist.h"
#define getSize(a) ((a)->size)

#define push(a, val) do { \
  if (((a)->used + 1) > 0.75 * getSize(a)) { \
    double_arraylist(&(a)); \
  } \
  ((f32*)(a)->arr)[(a)->used++] = (val); \
} while(0)

#define get(res, a, index) do { \
  if ( (index) < 0 || (index) >= getSize(a) ) { \
    (res) = -INT_MAX; \
  } else { \
    (res) = ((f32*)(a)->arr)[(index)]; \
  } \
} while(0)

#define create_arraylist(a, t, len) do { \
  (a) = (arraylist*) malloc(sizeof(arraylist)); \
  if (a) { \
    (a)->arr = malloc(sizeof(t) * (len)); \
    (a)->size = (len); \
    (a)->used = 0; \
  } \
} while(0)

#define destroy_arraylist(a) do { \
  free((a)->arr); \
  free(a); \
} while(0)

void double_arraylist(arraylist** a) {
  printf("doubling size \n");
  size_t old_size = getSize(*a);
  size_t new_size = old_size * 2;
  
  void* new_ptr = realloc((*a)->arr, sizeof(i32) * new_size);
  if (new_ptr) {
    (*a)->arr = new_ptr;
    (*a)->size = new_size;
  }
}// end of double arraylist

#define print_arraylist(a) do { \
  size_t _len = getSize(a); \
  for (i32 i = 0; i < (i32)_len; i++) { \
    i32 curr = 0; \
    get(curr, a, i); \
    if (i < (a)->used) { \
      printf("%f at i=%d\n", curr, i); \
    } \
  } \
  printf("-------------------------------------\n"); \
} while(0)

int main(void) {
  arraylist* a;
  create_arraylist(a, float, 5); // Start small to test doubling

  push(a, 420.0f);
  push(a, 69);
  print_arraylist(a);
  push(a, 1337);
  push(a, 80085);
  
  print_arraylist(a);

  destroy_arraylist(a);
  return 0;
}
