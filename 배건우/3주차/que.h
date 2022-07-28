#include <stdio.h>
#include <stdlib.h>
#define capacity 100

typedef struct
{
  int que[capacity];
  int front, rear;
} Queue;

void init_queue(Queue *q) //큐 초기화
{
  q->front = q->rear = 0;
}

int is_full(Queue *q)
{
  return ((q->rear + 1) % capacity == q->front);
}

int is_empty(Queue *q)
{
  return (q->front == q->rear);
}

void push(Queue *q, int value)
{
  if (is_full(q)) // que가 꽉차있다면 return
    return;

  q->rear = (q->rear + 1) % capacity;
  q->que[q->rear] = value;
}

int pop(Queue *q)
{
  if (is_empty(q)) // que가 비어있다면 -1 리턴
    return -1;

  q->front = (q->front + 1) % capacity;
  return q->que[q->front];
}

int size(Queue *q) // que의 크기를 반환
{
  if (q->front < q->rear)
    return q->rear - q->front;
  else
    return capacity - q->front + q->rear;
}
