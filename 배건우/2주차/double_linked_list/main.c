#include "linked_list.h"
#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float_double_linked_list *L = (float_double_linked_list *)malloc(sizeof(float_double_linked_list));

  init(L);
  insert(L, 1, 1.0);
  printf("%f", peek(L, 1)->data);
  return 0;
}