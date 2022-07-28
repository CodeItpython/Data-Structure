#include "que.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  Queue Q;
  init_queue(&Q); //큐 초기화

  int n, k, tmp;

  printf("n과 k를 입력하세요\n");
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; i++)
  {
    push(&Q, i + 1); // 1~n까지의 수를 que에 push
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k - 1; j++)
    {
      tmp = pop(&Q); // que의 앞부분에서 k번째 수까지 에서 pop한 수를 tmp에 저장하고
      push(&Q, tmp); // tmp를 que의 뒷부분에 저장
    }
    if (size(&Q) == 1) //큐안에 수가 1개남아있다면 break
      break;

    tmp = pop(&Q); //여기서 tmp는 지정된k번째의 수를 가리키고있다.
    printf("%d ", tmp);
  }
  printf("%d", pop(&Q)); //남아있는 마지막que의 잔여물을 출력해주어야한다.(위의 반복문에서 break한 결과이기때문)

  return 0;
}