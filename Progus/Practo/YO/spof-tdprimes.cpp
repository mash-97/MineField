#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <ctime>
using namespace std;

int limit(int number)
{
	int lim = (number>>5)+((number&31 )!=0 ? 1 : 0);
	return (lim>>1)+((lim&1)!=0 ? 1 : 0);
}

void markBit(pair<int,int> bit_index, int *array)
{
	array[bit_index.first] |= (1<<bit_index.second);
}

bool checkBit(pair<int,int> bit_index, int *array)
{
	return array[bit_index.first] & (1<<bit_index.second);
}

pair<int,int> indexOf(int number)
{
	return {(number>>5)>>1, (number>>1)&31};
}

vector<int> sieveOf(int number)
{
	int mark_array_limit = limit(number);
//	printf("mark_array_limit: %d\n", mark_array_limit);
	int mark[mark_array_limit];
	for(int i=0; i<mark_array_limit; i++) mark[i] = 0;
	
	markBit(indexOf(1), mark);
	
	vector<int> primes;
	primes.push_back(2);
	
	int lim = (int) sqrt(number*1.0+1.0);
	for(int i=3; i<=number; i+=2)
		if(!checkBit(indexOf(i), mark))
		{
			primes.push_back(i);
			if(i<=lim)
			{
				for(long long int j=i*i; j <= (long long int)number; j+= (i<<1))
					markBit(indexOf(j), mark);
			}
		}
	return primes;
}


int main()
{	
	vector<int> primes = sieveOf(99999999);
	
	int s = primes.size();
	for(int i=0; i<s; i+=100)
		printf("%d\n", primes[i]);
	return 0;
}


