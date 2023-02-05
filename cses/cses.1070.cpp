#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n;
	cin >> n;
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	else if(n<=3) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	
	for(int i=(n-((n&1) + 1)); i>=1; i-=2)
		cout << i << " ";
	
	cout << n << " ";
	
	for(int i=2; i<n-2; i+=2)
	{
		cout << i << " ";
	}
	cout 	<< (n-(!(n&1) + 1)) << endl;
	
	return 0;
}
