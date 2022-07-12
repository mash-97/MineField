#include <stdio.h>
#define STACK_MAX 10

typedef struct 
{
	int top;
	int data[STACK_MAX];
} Stack;

// push for inserting integer type data to the stack in the last position of the stack.
// two parameter Stack pointer and a integer item will be passed to the function.
// Stack pointer, because the function will change the main stack.
// item to push this data to the stack.
void push(Stack *s, int item)
{
	if(s->top<STACK_MAX) s->data[s->top++] = item;
	else printf("Stack is full!\n");
}

// pop for pulling the last data from the stack.
// Only one parameter, Stack pointer.
int pop(Stack *s)
{
	int item = -1;
	if(s->top==0) printf("Stack is empty!\n");
	else item = s->data[--s->top];
	return item;
}


int main()
{
	// Making a stack named my_stack
	Stack my_stack;
	int item;
	
	// There is no data in the my_stack, so top is set to 0.
	my_stack.top = 0;
	
	// pushing 1,2 and 3 as data in the my_stack. Here as first argument the address of the my_stack is sent: &my_stack.
	// So pointers of Stack type are sent all the call of push().
	for(int i=1; i<=12; i++) push(&my_stack, i);
	
	
	// pop() function also takes a Stack pointer as its first argument.
	// So &my_stack is sent.
	/*item = pop(&my_stack);
	printf("%d\n", item);
	
	item = pop(&my_stack);
	printf("%d\n", item);
	
	item = pop(&my_stack);
	printf("%d\n", item);
	
	item = pop(&my_stack);
	printf("%d\n", item);*/
	for(int i=1; i<=12; i++) printf("%d\n", pop(&my_stack));
	return 0;
}
	

