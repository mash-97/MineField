#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Aa
{
	public:
	int x, y;
	Aa(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	static bool comp(const void *a, const void *b);
	
	bool operator<(Aa &b)
	{
		if(x==b.x) return y < b.y;
		return x < b.x;
	}
	bool operator>(Aa &b)
	{
		if(x==b.x) return y > b.y;
		return x > b.x;
	}
};

bool Aa::comp(const void * a, const void * b)
{
		Aa * aa = (Aa*)a;
		Aa * bb = (Aa*)b;
		return aa > bb;
}

bool comp(const void * a, const void * b)
{
		Aa * aa = (Aa*)a;
		Aa * bb = (Aa*)b;
		if(aa->x==bb->x) return aa->y > bb->y;
		return aa->x > bb->y;
}

int main()
{
	vector<Aa*> a(10);
	int k=0;
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			a[k++] = new Aa(i,j);
	a[k++] = new Aa(34, 22);
	
	sort(a.begin(), a.end(), Aa::comp);
	for(int i=0; i<10; i++) cout<<"a["<<i<<"]:: x: "<<a[i]->x<<", y: "<<a[i]->y<<"\n";
	return 0;
}
