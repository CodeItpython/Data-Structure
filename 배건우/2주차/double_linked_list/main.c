#include "linked_list.h"
#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float_double_linked_list *L = (float_double_linked_list *)malloc(sizeof(float_double_linked_list));
  init(L);
  insert(L, 0, 1.0);
  insert(L, 1, 2.0);
  insert(L, 2, 3.0);
  insert(L, 3, 4.0);
  printf("%f\n", peek(L, 0)->data);
  printf("%f\n", peek(L, 1)->data);

  push_back(L, 5.0);
  print_list(L);
  return 0;
}