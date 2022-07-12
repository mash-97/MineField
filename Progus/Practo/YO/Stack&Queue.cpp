#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


	

template<class Type>
class Stack
{
	//static int STACKS;
	
	public:
	int MAX_SIZE;
	int top;
	int print_message;
	Type *stack_data;
	Type STACK_EMPTY;
	
	Stack()
	{
		//STACKS++;
		this->MAX_SIZE = 100;
		this->stack_data = new Type[this->MAX_SIZE];
		this->top = 0;
		this->STACK_EMPTY = -(Type)__builtin_inf();
		this->print_message = false;
	}
	Stack(int size)
	{
		//STACKS++;
		this->MAX_SIZE = size;
		this->stack_data = new Type[this->MAX_SIZE];
		this->top = 0;
		this->STACK_EMPTY = -(Type)__builtin_inf();
		this->print_message = false;
	}
	
	void push(Type data)
	{
		if(top < MAX_SIZE)
			this->stack_data[top++] = data;
		else if(this->print_message)
			printf("Stack Overflow\n");
	}
	Type pop()
	{
		if(top > 0)
			return this->stack_data[--top];
		else if(this->print_message)
			printf("Stack Empty!\n");
		return false;
	}
};

int checkIsOkay(char c, char brace, char anti_brace, Stack<char> &stack)
{
	if(c == brace)
		stack.push(brace);
	else if(c == anti_brace)
		return (stack.pop() == brace) ? true : false;
	return true;
}

int isBalanced(char *string)
{
	int length = strlen(string);
	Stack<char>stack((length)/2);
	stack.print_message = false;
	for(int i=0; i<length; i++)
	{
		if(string[i]=='(' || string[i]==')')
			{if(checkIsOkay(string[i], '(', ')', stack)==false) return false;}
		else if(string[i]=='{' || string[i]=='}')
			{if(checkIsOkay(string[i], '{', '}', stack)==false) return false;}
		else if(string[i]=='[' || string[i]==']')
			{if(checkIsOkay(string[i], '[', ']', stack)==false) return false;}
	}
	if(stack.top==0) return true;
	return false;
}

template <class Type>
class Queue
{
	public:
	int QUEUE_SIZE;
	int head;
	int tail;
	Type *queue;
	int print_message;
	Queue()
	{
		this->QUEUE_SIZE = 100;
		this->head = 0;
		this->tail = 0;
		this->queue = new Type[this->QUEUE_SIZE+1];
		this->print_message = false;
	}
	Queue(int size)
	{
		this->QUEUE_SIZE = size;
		this->head = 0;
		this->tail = 0;
		this->queue = new Type[this->QUEUE_SIZE+1];
	}
	
	int enqueue(Type data)
	{
		if(print_message) printf("head: %d, tail: %d\n", head, tail);
		if((tail+1)%(QUEUE_SIZE+1)==head)
		{
			if(print_message) printf("The queue is full:: head: %d, tail: %d\n", head, tail);
			if(print_message) cout << "The data "<<data<<" couldn't be enqueued\n"<<endl;
			return false;
		}
		else
		{
			queue[tail] = data;
			tail = (tail+1)%(QUEUE_SIZE+1);
		}
		if(print_message)	cout << "The data "<<data<<" is enqueued!"<<endl;
		if(print_message) 	printf("head: %d, tail: %d\n\n", head, tail);
		return true;
	}
	Type dequeue()
	{
		Type data;
		if(print_message) printf("head: %d, tail: %d\n", head, tail);
		if(head==tail)
		{
			if(print_message) printf("The queue is empty!\n\n");
			return NULL;
		}
		else
		{
			data = queue[head];
			head = (head+1)%(QUEUE_SIZE+1);
		}
		if(print_message) cout << "The data "<<data<<" is dequeued!"<<endl;
		if(print_message) printf("head: %d, tail: %d\n\n", head, tail);
		return data;
	}
};

template<class Type>
class N
{
	public:
	Type data;
	
	N(Type data)
	{
		this->data = data;
	}
	
	void disp()
	{
		cout<<this->data<<endl;
	}
};
			
int main()
{
	Queue<N<int>*> q(3);
	q.print_message = true;
	
	q.enqueue(new N<int>(1));
	q.enqueue(new N<int>(2));
	q.enqueue(new N<int>(3));
	
	N<int> *n;
	n = q.dequeue();
	n->disp();
	
	n = q.dequeue();
	n->disp();
	
	n = q.dequeue();
	n->disp();
	
	
	return 0;
}
