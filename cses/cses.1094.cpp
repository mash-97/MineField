#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int n, t;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> t;
		v.push_back(t);
	}
	
	long long int minimum_operations=0;
	
	for(int i=1; i<(int)v.size(); i++){
		if(v[i]<v[i-1])
		{
			minimum_operations += (v[i-1]-v[i]);
			v[i] += (v[i-1]-v[i]);
		}
	}
	
	cout << minimum_operations << endl;
	
	return 0;
}
