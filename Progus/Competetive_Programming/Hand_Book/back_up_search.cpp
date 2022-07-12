#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector< vector<int> > subsets;

void gen(int i)
{
	static vector <int> sub_set;
	if(i==n+1)
	{
		subsets.push_back(sub_set);
		return;
	}
	else
	{
		gen(i+1);
		sub_set.push_back(i);
		gen(i+1);
		sub_set.pop_back();
	}
}

void dis(vector <vector <int>> v)
{
	for(auto x: v)
	{
		for(auto y: x) cout<<y<<" ";
		cout<<endl;
	}
}

void gen_bit(int l)
{
	for(int i=0; i< (1<<l); i++)
	{
		vector <int> sub_set;
		for(int j=0; j<l; j++)
		if(i&(1<<j)) sub_set.push_back(j+1);
		
		subsets.push_back(sub_set);
	}
}

bool compo(vector <int> &a, vector <int> &b)
{
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main()
{
	scanf("%d", &n);
	//gen(1);
	gen_bit(n);
	sort(subsets.begin(), subsets.end(), compo);
	dis(subsets);
	return 0;
}
