#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"



arraylist* create_arraylist(size_t len)
{
  arraylist* a = (arraylist*) malloc(sizeof(arraylist));

  a->size = len;
  a->used = 0;
  return a;
}

void destroy_arraylist(arraylist* a )
{
  free(a);
}

size_t getSize(arraylist* a )
{
  return a->size;
}

void double_arraylist(arraylist** a )
{
  size_t old_size = getSize(*a);
  arraylist* newlist = (arraylist*) malloc(2 * old_size);

  memcpy((*a)->arr, newlist->arr, sizeof(i32) * old_size);
  newlist->size = 2 * old_size;
  newlist->used = (*a)->used;
  destroy_arraylist(*a);
  *a = newlist;
}

void push(arraylist* a, i32 i )
{
  size_t s = getSize(a);

  if ((a->used + 1 ) > 0.75 * s){
      double_arraylist(&a);
  }
  a->arr[a->used] = i;
  a->used++;
  return;
}

i32 get(arraylist* a , i32 index)
{
  if ( index < 0 || index > getSize(a) ) {
    return -1;
  }
  return a->arr[index];
}

void print_arraylist(arraylist* a )
{
  size_t len = getSize(a);
  for (i32 i = 0; i < len; i++){
    i32 curr = get(a, i);
    if (curr != 0 ){
      printf("%d at i=%d\n",curr, i );
    }
  }
  printf("-------------------------------------\n");
}


int main(void)
{
  arraylist* lst = create_arraylist(3);

  push(lst, 420);
  print_arraylist(lst);
  push(lst, 1337);
  print_arraylist(lst);

  push(lst, 69);
  print_arraylist(lst);

  push(lst, 232);
  print_arraylist(lst);


  destroy_arraylist(lst);
}
