#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

vector <vector <int> > permutations;
int chosen[1000];

void generate_permutations(int n, int count)
{
	static vector<int> perms;
	
	if(count == n)
	{
		permutations.push_back(perms);
		return;
	}
	
	for(int i=1; i<=n; i++)
	if(!chosen[i])
	{
		perms.push_back(i);
		chosen[i] = 1;
		generate_permutations(n, count+1);
		chosen[i] = 0;
		perms.pop_back();
	}
}

void d(vector<vector<int>> v)
{
	for(auto x: v)
	{
		for(auto y: x) cout<<y<<" ";
		cout<<endl;
	}
}


void generate_permutations_using_next(int n)
{
	vector <int> perm;
	for(int i=1; i<=n; i++) perm.push_back(i);
	do
	{
		permutations.push_back(perm);
	} while(next_permutation(perm.begin(), perm.end()));
}

int main()
{
	int n;
	cin>>n;
	
	clock_t s = clock();
	generate_permutations_using_next(n);
	clock_t e = clock();
	 
	double a = (double)(e-s)/CLOCKS_PER_SEC;
	
	s = clock();
	generate_permutations(n, 0);
	e = clock();
	double b = (double)(e-s)/CLOCKS_PER_SEC;
	
	cout<<"a: "<<(round(a*100)/100)<<" and b: "<<(round(b*100)/100)<<endl;
	//d(permutations);
	return 0;
}
	
