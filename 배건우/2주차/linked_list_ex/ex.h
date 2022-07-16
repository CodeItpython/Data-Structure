typedef struct __example_node
{
  //단일 연결 리스트의 노드
  int data;
  struct __example_node *next;
} example_node;

typedef struct __example_list
{
  example_node *head, *tail;
} example_list; // head 와 tail 이 존재하는 단일 연결리스트

//단일 연결 리스트 관련 함수 예제
void init_example(example_list *list);
example_node *peek_example(example_list *list, const int at);
example_node *find_example(example_list *list, const int target);
int insert_example(example_list *list, const int at, const int value);
void push_back_example(example_list *list, const int value);
void push_front_example(example_list *list, const int value);
int delete_example(example_list *list, const int at);
example_node *create_example_node(int data);
