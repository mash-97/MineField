#include <bits/stdc++.h>
using namespace std;

class Box
{
	public:
	int a;
	Box(int a)
	{
		this->a = a;
		printf("Constructor called!\n");
	}
	~Box()
	{
		printf("Destructor called!\n");
	}
};

struct B
{
	Box box;
	Box * next_box;
};

int main()
{
	Box * my_boxes = new Box[4];
	delete [] my_boxes;
	
	B *hb = new B;
	hb->box = Box(5);
	hb->next_box = NULL;
	
	
	
	
	return 0;
}
