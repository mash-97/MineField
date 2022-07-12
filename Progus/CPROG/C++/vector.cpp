#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector< int > a;
	int m;
	for(int i=1; i<=n; i++)
	{
		cin >> m;
		a.push_back(m);
	}
	
	cout << "Showing The Vector: "<< a.size() <<"\n";
	vector < int > ::iterator i;
	i=a.begin();
	
	for(; i!=a.end(); i++)
	{
		cout << *i <<" \n";
	}
	return 0;
	
}
