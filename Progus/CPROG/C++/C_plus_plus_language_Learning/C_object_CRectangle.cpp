#include <iostream>
using namespace std;

class CRectangle
{
	
	public:
		int x, y;
		void set_rect(int a, int b)
		{
			x = a;
			y = b;
		}
		
		int area()
		{
			return x*y;
		}
};

//~ void CRectangle::set_rect(int a, int b)
//~ {
	//~ x = a;
	//~ y = b;
//~ }

//~ int CRectangle::area()
//~ {
	//~ return x*y;
//~ }

int main()
{
	CRectangle rect;
	rect.set_rect(3,4);
	cout << "rect.x : " << rect.x << endl;
	cout << "rect.y : " << rect.y << endl;
	cout << rect.area() << endl;
	return 0;
}
