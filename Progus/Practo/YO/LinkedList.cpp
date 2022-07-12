#include <iostream>
#include <stdio.h>
using namespace std;

template <class Type>
class LinkedList
{
	private:
		struct Node
		{
			Type data;
			Node *next;
		};
		
		Node *createNode(Type data, Node *next)
		{
			Node *node = new Node;
			node->data = data;
			node->next = next;
			return node;
		}
	
	public:
		int length;
		Node *head;
		Node *tail;
		
		LinkedList()
		{
			this->length = 0;
			this->head = NULL;
			this->tail = NULL;
		}
		LinkedList(Node *head, Node *tail)
		{
			this->length = 0;
			this->head = head;
			this->tail = tail;
		}
		
		
		
		void push_back(Type data)
		{ 
			this->length += 1;
			Node *new_node = createNode(data, NULL);
			if(head==NULL)
			{
				head = new_node;
				tail = new_node;
				return;
			}
			tail->next = new_node;
			tail = new_node;
		}
		
		void push_front(Type data)
		{
			this->length += 1;
			Node *new_node = createNode(data, head);
			if(head==NULL)
			{
				head = new_node;
				tail = new_node;
				return;
			}
			head = new_node;
		}
		
		void reverseList()
		{
			Node *c = head;
			Node *p = NULL;
			Node *temp;
			tail = head;
			while(c!=NULL)
			{
				temp = c->next;
				c->next = p;
				p = c;
				c = temp;
			}
			head = p;
		}
		
		void insertSortedly(Node *node, int sort_mode)
		{
			this->length += 1;
			if(node==NULL) return;
			if(head==NULL)
			{
				head = node;
				tail = node;
				node->next = NULL;
				return;
			}
			if((head->data <= node->data) == sort_mode)
			{
				node->next = head;
				head = node;
				return;
			}
			Node *c = head->next;
			Node *p = head;
			while(c!=NULL)
			{
				if((c->data <= node->data)==sort_mode)
				{
					node->next = c;
					p->next = node;
					return;
				}
				p = c;
				c = c->next;
			}
			node->next = tail->next;
			tail->next = node;
			tail = node;
		}
		
		void insertionSort(int sort_mode)
		{
			if(head==tail) return;
			LinkedList<Type> list;
			Node *c = head;
			Node *n;
			while(c!=NULL)
			{
				n = c->next;
				list.insertSortedly(c, sort_mode);
				c = n;
			}
			this->head = list.head;
			this->tail = list.tail;
			this->length = list.length;
		}
		
		void disp()
		{
			Node *c = head;
			while(c!=NULL)
			{
				cout<<c->data<<" ";
				c = c->next;
			}
			cout<<"\n\n";
		}
};
	
int main()
{
	LinkedList<int> list;
	list.push_back(33);
	list.push_back(34);
	list.push_back(35);
	list.push_back(11);
	list.push_back(9);
	list.push_front(10);
	list.push_front(101);
	list.push_front(-234);
	for(int i=0; i<10; i++)
		(rand()%2)==0 ? list.push_front(rand()%100+1) : list.push_back(rand()%1000+100);
	cout<<list.length<<endl;
	list.disp();
	puts("");
	list.insertionSort(1);
	
	cout<<list.length<<endl;
	list.disp();
	return 0;
}
