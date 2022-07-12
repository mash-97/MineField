#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;



vector<int>	prime_factors(int number)
{
	vector<int> factors;
	for(int x = 2; x*x <= number; x++)
	{
		while(number % x == 0) 
		{
			factors.push_back(x);
			number /= x;
		}
	}
	
	if(number!=0) factors.push_back(number);
	return factors;
}

map<int,int> mapify(vector<int> v)
{
	sort(v.begin(), v.end());
	map<int,int> m;
	int x = v[0];
	auto init = v.begin();
	auto upb = upper_bound(v.begin(), v.end(), x);

	if(x!=1) m[x] = upb-v.begin();
	while(upb!=v.end())
	{
		x = *upb;
		init = upb;
		upb = upper_bound(upb, v.end(), x);
		if(x!=1) m[x] = upb-init;
	}
	return m;
}
		

template <class Type>
void dispv(vector<Type> v)
{
	for(auto i : v)
		cout<< i <<" ";
	cout<<endl;
}

int main()
{
	static int number;
	scanf("%d", &number);
	
	static vector<int> v;
	v = prime_factors(number);
	
	map<int,int> m = mapify(v);
	dispv<int>(v);
	
	for(auto i: m)
		cout<<i.first<<" :: "<<i.second<<endl;
	
	main();
	return 0;
}
