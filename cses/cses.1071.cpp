#include <iostream>

using namespace std;

long long int rule1(int maxi, int mini) {
	return ((long long int)maxi*(long long int)maxi) - ((long long int)maxi*2 - (long long int)mini-1);
}
long long int rule2(int maxi, int mini) {
	return ((long long int)maxi*(long long int)maxi) - ((long long int)mini-1);
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int y, x;
		cin >> y >> x;
		
		int maxi = max(y, x);
		int mini = min(y, x);
		
		long long int ans;
		if((maxi&1) &&  maxi==y) 
			ans = rule1(maxi, mini);
		else if(maxi&1)
			ans = rule2(maxi, mini);
		else {
			if(maxi==y)
				ans = rule2(maxi, mini);
			else
				ans = rule1(maxi, mini);
		}
		cout << ans << endl;
	}
	return 0;
}
