#include <bits/stdc++.h>

using namespace std;

int main(){
	string arr[] = {
			"hello", "world","c++"
		};
	
	do{
		for(int i=0; i<3; i++) cout << arr[i] << " ";
		cout << endl;
	}
	while( next_combination(arr,arr+3));
	
	return 0;
}
