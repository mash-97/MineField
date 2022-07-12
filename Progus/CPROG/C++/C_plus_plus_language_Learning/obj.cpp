#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cordinate
{
	public:
		double x;
		double y;
		string s;
	Cordinate(double a, double b, string ss)
	{
		x = a;
		y = b;
		s = ss;
	}
	
		
};


void display(vector <Cordinate*> a)
{
	int vector_len = a.size();
	for(int i=0; i<vector_len; i++)
		cout << i <<". x: "<<a[i]->x<<" and y: "<<a[i]->y<<" s: "<<a[i]->s<<endl;
	puts("");
}

int main()
{
	vector <Cordinate*> b;
	b.push_back(new Cordinate(3.3, 5.5, "3 and 5"));
	b.push_back(new Cordinate(2.2, 8.8, "2 and 8"));
	//a.pop_back();
	display(b);
	vector <int> a;
	a.push_back(5);
	a.push_back(4);
	cout << a.max_size() << endl;
	cout << a.front() << endl;
	return 0;
}
