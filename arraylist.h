#include "types.h"

#define DEFAULT_SIZE 256




typedef struct {
  i32 arr[DEFAULT_SIZE];
  size_t size;
  i32 used;
}arraylist ;


arraylist* create_arraylist(size_t len);
void destroy_arraylist(arraylist* a );
size_t getSize(arraylist* a );
void push(arraylist* a, i32 i );
void double_arraylist(arraylist** a );
