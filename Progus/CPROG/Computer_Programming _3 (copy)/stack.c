#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
enum SORT_MODE {INC=0, DEC = 1};
typedef enum SORT_MODE SORT_MODE;

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

typedef struct Stack
{
	int count;
	Node *head;
}Stack;

typedef struct List
{
	int size;
	SORT_MODE sort_mode;
	Node *head;
}List;

// Node
Node * popFirstNode(Node **head);
Node * prependNode(Node *head, Node *node);
Node * appendNode(Node *head, Node *node);
Node * createNode(int data, Node *next);
void insertNodeSort(SORT_MODE mode, Node **head, Node *node);
int * convertNodesDataIntoArray(Node *node, int size);
Node *lastNode(Node *head);
int nbs(int l, int r, Node *head_node, Node *left_node, Node *right_node, int data);
void deleteNode(Node **head, int data);
Node *checkAt(Node *head, int pos);


// Stack
Node * pop(Stack *stack);
void push(Stack *stack, int data);
Stack newStack();
int * convertStackIntoArray(Stack stack, int *size);

// List
List newList();
int *convertListIntoArray(List list, int *size);
void insertDataIntoList(List *list, int data);
int lbs(List list, int data);
void deleteDataFromTheList(List *list, int data);
int checkTheDataAt(List list, int pos);

void printArray(int size, int *array)
{
	for(int i=0; i<size; i++)
		printf("%d ", array[i]);
	puts("\n");
}

int binarySearch(int size, int *array, int x)
{
	int left = 0;
	int right = size-1;
	int mid;
	
	while(left<=right)
	{
		mid = left+(right-left)/2;
		if(array[mid] == x) return mid;
		else if(array[mid] > x) right = mid-1;
		else left = mid+1;
	}
	return -1;
}

int compare(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}

int rando(int min, int max)
{
	time_t t;
	srand((unsigned)time(&t));
	int num = random() % (max+1-min) + min;
	return num;
}

int main()
{
	Stack stack = newStack();
	push(&stack, 5);
	push(&stack, 6);
	push(&stack, 1);
	push(&stack, 33);
	push(&stack, 34);
	push(&stack, 3);
	push(&stack, 88);
	push(&stack, 22);
	push(&stack, 99);
	int asize, *array = convertStackIntoArray(stack, &asize);
	
	
	
	qsort(array, asize, sizeof(int), compare);
	printArray(asize, array);
	clock_t s = clock();
	for(int i=0; i<100000; i++){
		int x = i;
		if(binarySearch(asize, array, x)>=0) 
			printf("%d is found in index: %d\n", x, binarySearch(asize, array, x));
		//else 
			//printf("%d is not found in the array\n", x);
	}
	printf("Stack size: %d\n", stack.count);
	clock_t e = clock();
	printf("%0.6lf\n", (double)(e-s)/CLOCKS_PER_SEC);
	puts("\n\n\n");
	List list = newList();
	list.sort_mode = INC;
	insertDataIntoList(&list, 5);
	insertDataIntoList(&list, 1);
	insertDataIntoList(&list, 10);
	insertDataIntoList(&list, 7);
	insertDataIntoList(&list, 20);
	
	printf("List size: %d\n", list.size);
	array = convertListIntoArray(list, &asize);
	printArray(asize, array);
	List index_list = newList();
	for(int i=0; i<list.size; i++) insertDataIntoList(&index_list, i);
	s = clock();
	
	for(int i=0; i<list.size; i++)
	{
		
		int pos = rando(0, index_list.size-1);
		int x = checkTheDataAt(index_list, pos);
		//printf("index_list.size: %d, pos: %d, x: %d\n", index_list.size, pos, x);
		//printf("x: %d, index_list.size: %d\n", x, index_list.size);
		deleteDataFromTheList(&index_list, x);
		if(lbs(list, array[x])>=0) 
			printf("%d is found in index: %d\n", array[x], lbs(list,  array[x]));
		//else 
			//printf("%d is not found in the array\n", x);
	}
	e = clock();
	printf("%0.6lf\n", (double)(e-s)/CLOCKS_PER_SEC);
	printf("Index List.size: %d\n", index_list.size);
	return 0;
}

// Stack
Stack newStack()
{
	Stack new_stack;
	new_stack.count = 0;
	new_stack.head  = NULL;
	return new_stack;
}

void push(Stack *stack, int data)
{
	stack->count += 1;
	stack->head = prependNode(stack->head, createNode(data, stack->head));
}

Node * pop(Stack *stack)
{
	Node * node =  popFirstNode(&stack->head);
	if(node) stack->count -= 1;
	return node;
}

int * convertStackIntoArray(Stack stack, int *size)
{	
	*size = stack.count;
	return convertNodesDataIntoArray(stack.head, stack.count);
}


// Node

Node * createNode(int data, Node *next)
{
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = next;
	return new_node;
}
Node * appendNode(Node *head, Node *node)
{
	Node *current_node = head;
	while(current_node->next != NULL) current_node = current_node->next;
	current_node->next = node;
	return head;
}

Node * prependNode(Node *head, Node *node)
{
	node->next = head;
	return node;
}

Node * popFirstNode(Node **head)
{
	if(*head==NULL) return NULL;
	Node *first_node = *head;
	*head = (*head)->next;
	first_node->next = NULL;
	return first_node;
}

void insertNodeSort(SORT_MODE mode, Node **head, Node *node)
{
	Node *current_node = *head;
	if(current_node==NULL)
	{
		*head = node;
		return;
	}
	if((current_node->data <= node->data) == mode)
	{
		node->next = *head;
		*head = node;
		return;
	}
	
	while(current_node->next != NULL)
	{
		if(((current_node->data <= node->data) == !mode) && (node->data <= current_node->next->data) == !mode)
		{
			node->next = current_node->next;
			current_node->next = node;
			return;
		}
		current_node = current_node->next;
	}
	
	current_node->next = node;
	node->next = NULL;
}

int countNodes(Node *nodes)
{
	Node *current_node = nodes;
	int count = 0;
	while(current_node != NULL)
	{
		count++;
		current_node = current_node->next;
	}
	return count;
}

int * convertNodesDataIntoArray(Node *nodes, int size)
{
	if(size==-1)	size = countNodes(nodes);
		
	int *array = (int*) malloc(sizeof(Node)*(size));
	Node *current_node = nodes;
	int index = 0;
	while(current_node != NULL)
	{
		array[index++] = current_node->data;
		current_node = current_node->next;
	}
	return array;
}

	

Node * freeNodes(Node *node)
{
	if(node==NULL) return NULL;
	if(node->next==NULL)
	{
		free(node);
		return NULL;
	}
	node->next = freeNodes(node->next);
	free(node);
	return NULL;
}


Node *lastNode(Node *head)
{
	if(head==NULL) return NULL;
	Node *current_node = head;
	while(current_node->next != NULL) current_node=current_node->next;
	return current_node;
}

int nbs(int l, int r, Node *head_node, Node *left_node, Node *right_node, int data)
{
	//printf("L: %d    :: R: %d\n", l, r);
	if(l>r || right_node==NULL || left_node==NULL) return -1;
	int mid = (r+l)/2;
	Node *current_node = left_node;
	for(int i=l; i<mid; i++)
		current_node = current_node->next;

	int pos;
	if(current_node->data == data) return mid;
	if(current_node->data > data) pos = nbs(l, mid-1, head_node, left_node, current_node, data);
	if(current_node->data < data) pos = nbs(mid+1, r, head_node, current_node->next, right_node, data);

	return pos;
}

void deleteNode(Node **head, int data)
{
	if(*head==NULL) return;
	Node *prev = NULL;
	Node *curr = *head;

	while(curr != NULL)
	{
		if(curr->data==data) break;
		prev = curr;
		curr = curr->next;
	}
	
	if(curr==NULL) return;
	if(prev==NULL) 
	{
		*head = (*head)->next;
		free(curr);
		return;
	}
	prev->next = curr->next;
	free(curr);
}

Node *checkAt(Node *head, int pos)
{
	Node *current_node = head;
	for(int i=0; i<pos; i++) current_node = current_node->next;
	return current_node;
}

// List
List newList()
{
	List new_list;
	new_list.size = 0;
	new_list.sort_mode = INC;
	new_list.head = NULL;
	return new_list;
}

void insertDataIntoList(List *list, int data)
{
	list->size++;
	insertNodeSort(list->sort_mode, &list->head, createNode(data, NULL));
}

int *convertListIntoArray(List list, int *size)
{
	*size = list.size;
	return convertNodesDataIntoArray(list.head, list.size);
}


int lbs(List list, int data)
{
	return nbs(0, list.size, list.head, list.head, lastNode(list.head), data);
}


void deleteDataFromTheList(List *list, int data)
{
	list->size--;
	deleteNode(&(list->head), data);
}

int checkTheDataAt(List list, int pos)
{
	Node *node = checkAt(list.head, pos);
	return node->data;
}
