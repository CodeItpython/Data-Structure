#include "sample.h"
#include "sample.c"
#include <stdio.h>

int main(void)
{
  int_array L;
  init(&L, 100);
  insert(&L, 0, 10);
  insert(&L, 1, 20);
  insert(&L, 2, 30);
  insert(&L, 3, 40);
  push(&L, 50);
  push(&L, 60);

  print_arr(&L);
  printf("\n");

  delete (&L, 0);
  print_arr(&L);
  printf("\n");

  delete (&L, 0);
  print_arr(&L);

  free(L.ptr);

  return 0;
}
