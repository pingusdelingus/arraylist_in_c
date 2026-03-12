#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

#define INIT_SIZE 10
#define NEG_INF_32 INT32_MIN

i32* create_arraylist()
{
   i32* result = (i32*) malloc( (sizeof(i32) * INIT_SIZE ) + sizeof(Header));

    Header* h = (Header*) result;
    h->size = INIT_SIZE;
    h->used = 0;

    return (i32*) (h + 1);
  
}


i32* create_arraylist_s(size_t req_size)
{
   i32* result = (i32*) malloc( (sizeof(i32) * req_size ) + sizeof(Header));

    Header* h = (Header*) result;
    h->size = req_size;
    h->used = req_size / 2;

    return (i32*) (h + 1);
  
}


void destroy_arraylist(i32* l )
{
  Header*h = (Header*)l;
  h--;
  free(h);
}

size_t getSize(i32* l )
{

  Header* h = (Header*) l;
  h--;

  return h->size;
}

void double_arraylist(i32** l )
{
  printf("doubling arraylist \n");
  size_t curr_size = getSize(*l);
  i32* newlist = create_arraylist_s(2 * curr_size);

  memcpy(newlist,*l, curr_size );
  *l = newlist;
  destroy_arraylist(*l);
}


void push(i32* l, i32 item)
{
  Header* h = (Header*) l;
  h--;

  if ((h->used) + 1 >= 0.75 * h->size){
    double_arraylist(&l);
  }

  l[h->used] = item;

  h->used++;
}

i32 get(i32* l, i32 index)
{
  size_t size = getSize(l);
  if (index < 0 || index >size ){
    return NEG_INF_32;
  }

  

  return l[index];

}// end of get

i32 rm(i32* l , i32 index)
{
    size_t size = getSize(l);

    if (index > size){
    return NEG_INF_32;
  }
  i32 rmd = l[index]; 
  l[index] = 0;
  return rmd;
}// end of removek


void print_arraylist(i32* list )
{
  i32 curr = 0;
  for (i32 i = 0; i < getSize(list); i++){
      curr = get(list, i );
      if (curr != 0){
        printf("%d, at i=%d\n",get(list,i), i );
    }
  }
    printf("--------------------------------------------\n");
}

int main(void)
{
  i32* list = create_arraylist();

  push(list, 69);
    print_arraylist(list);
  push(list, 420);
    print_arraylist(list);
  push(list, 1337);
    print_arraylist(list);
  push(list, 42);
    print_arraylist(list);
  push(list, 43);
    print_arraylist(list);
  push(list, 44);
    print_arraylist(list);
  push(list, 45);
    print_arraylist(list);
  push(list, 46);
    print_arraylist(list);
  push(list, 47);
    print_arraylist(list);
  push(list, 48);
   
    print_arraylist(list);

    rm(list, 1);

    print_arraylist(list);

  destroy_arraylist(list);
}
