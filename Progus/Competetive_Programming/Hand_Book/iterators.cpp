//~ #include <iostream>
//~ #include <set>
//~ #include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	bitset<10> a(string("0010011010"));
	bitset<10> b(string("1011011000"));
	
	cout<<(a^b)<<endl;

	return 0;
}
