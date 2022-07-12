#include <iostream>
#include <vector>
#include <string>

using namespace std;

void gen(int n, int k, vector <vector<int>> &v)
{
	static vector<int>subset;
	if(k==n+1)
	{
		v.push_back(subset);
		return;
	}
	else
	{
		gen(n, k+1, v);
		subset.push_back(k);
		gen(n, k+1, v);
		subset.pop_back();
	}
}

vector <vector<int>> dom_bit(int *array, int n)
{
	vector <vector<int>> subsets;
	int n2 = 1<<n;
	for(int i=0; i<n2; i++)
	{
		vector <int> subs;
		for(int j=0; j<n; j++)
		if(i&(1<<j)) subs.push_back(array[j]);
		
		subsets.push_back(subs);
	}
	
	return subsets;
}

void disv(vector<int> v)
{
	for(auto x: v) cout<<x<<" ";
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;

	int array[n];
	for(auto &x: array) cin>>x;
	vector <vector <int>> v = dom_bit(array, n);
	for(auto x: v) disv(x);
	cout<<endl;
	return 0;
}
