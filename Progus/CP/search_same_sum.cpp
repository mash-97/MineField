#include <iostream>
#include <vector>

#define MAX_N 100000
using namespace std;

int world_array[MAX_N];

int n;
int m;
int min_len;

vector <int> r;

void search_sum(int *array_n, int l_sum, int len)
{	
	static vector <int> s;
	if(l_sum > m || len == n) return;
	else if(l_sum==m)
	{
		//cout<<"min_len: "<<min_len<<", len: "<<len<<endl;
		if(min_len>len)
		{
			min_len = len;
			r = s;
		}
		return;
	}
	else
	{
		for(int i=0; i<n; i++)
		if(!world_array[i])
		{
			world_array[i] = 1;
			s.push_back(array_n[i]);
			search_sum(array_n, (l_sum+array_n[i]), len+1);
			
			s.pop_back();
			world_array[i] = 0;
		}
	}
}


int main()
{
	cin>>n>>m;
	
	min_len = n;
	for(int i=0; i<n; i++) world_array[i] = 0;
	
	int array[n];
	for(int &a: array) cin>>a;
	
	search_sum(array, 0, 0);
	cout<<"Min len is: "<<min_len<<endl;
	cout<<"Size: "<<r.size()<<endl;
	for(auto x: r) cout<<x<<" ";
	cout<<endl;
	return 0;
}
