#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <limits>

//~ #include <bits/stdc++.h>

using namespace std;

int * bsearch(int *A, int len, int numb)
{
	int i=0;
	int j=len;
	int mid;
	
	while(i < j)
	{
		mid = i+(j-i)/2;
		if(A[mid]==numb) return &A[mid];
		else if(A[mid] > numb) j = mid;
		else i = mid;
		
		cout<<"i: "<<i<<" and j: "<<j<<endl;
	}
	return NULL;
}

int bse(int *t, int n, int x)
{
	cout<<"\n\nFor "<<x<<"::\n";
	int k = 0;
	for(int b=n/2; b>=1; b /= 2)
	{
		cout<<"b: "<<b<<"::\t\t";
		
		while(k+b < n && t[k+b] <= x)
		{
			k+=b;
			cout<<"k: "<<k<<" ";
		}
		cout<<endl;
	}
	
	if(t[k] == x) return x;
	return 0;
}

int main()
{
	long long unsigned l = numeric_limits<long long unsigned>::max();
	cout<<l<<endl;
	
	return 0;
}
