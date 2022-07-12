#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> v;
int main()
{
	string s;
	int n;
	scanf("%d",&n);
	for(int j=0; j<n; j++)
	for(int i=0; i<2; i++)
	{
		cin>>s;
		v[j].push_back(s);
	}
	
	for(int j=0; j<n; j++)
	{
		printf("\nv[%d]: \n", j);
		for(int i=0; i<2; i++)
			cout<<"\t"<<v[j][i]<<endl;
	}
	return 0;
}
