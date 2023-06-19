#include <iostream>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	cout << min(n, q);
	int array[n];
	for(int i=0; i<n; i++) 
		cin >> array[i];
	
	int min_array[n];
	min_array[0] = array[0];
	for(int i=1; i<n; i++)
		min_array[i] = min(min_array[i-1], array[i]);
	
	while(q--) {
		int a, b;
		cin >> a >> b;
		--a;--b;
		if(a==0) cout << min_array[b];
		else {
			
	
	return 0;
}
