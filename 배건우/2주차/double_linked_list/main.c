#include "linked_list.h"
#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float_double_linked_list *L = (float_double_linked_list *)malloc(sizeof(float_double_linked_list));
  init(L); // L 초기화

  push_front(L, 1.0); // head 앞에 추가
  push_front(L, 2.0);
  push_front(L, 3.0);
  push_front(L, 4.0);
  print_list(L);     //출력
  push_back(L, 1.0); // tail 뒤에 추가
  push_back(L, 2.0);
  push_back(L, 3.0);
  push_back(L, 4.0);
  print_list(L);   //출력
  delete_back(L);  // tail삭제
  delete_front(L); // head삭제
  print_list(L);   //출력

  insert(L, 1, 8.0); // index지정을통한 value삽입
  print_list(L);     //출력

  free(L); //할당 해제

  return 0;
}
