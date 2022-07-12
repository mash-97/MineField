#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace std;

#define MARK_ARRAY_SIZE  1000002
int mark[MARK_ARRAY_SIZE];

vector<int> sieveOfEratosthenes(int n)
{
	mark[0] = mark[1] = 1;
	vector<int> primes;
	if(n==0 || n==1) return primes;
	
	int limit = (int) sqrt(n+1);
	primes.push_back(2);
	for(int i=4; i<=n; i+=2) mark[i] = 1;
	
	int i = 3;
	while(i<=n)
	{
		if(!mark[i])
		{
			primes.push_back(i);
			
			if(i<= limit)
				for(int j=i*i; j<=n; j += 2*i)
					mark[j] = 1;
		}
		i+=1;
	}
	return primes;
}

vector<vector<int>> pffs(int n, double &times)
{
	clock_t s = clock();
	vector<vector<int>> pfs(n+1);
	pfs[0].push_back(0);
	pfs[1].push_back(1);
	
	for(int i=2; i<=n; i++)
	if(pfs[i].size()==0) 
	{
		pfs[i].push_back(i);
		for(int j=2*i; j<=n; j+=i)
		{
			int number = j;
			while(number%i==0)
			{
				pfs[j].push_back(i);
				number /= i;
			}
		}
	}
	
	clock_t e = clock();
	times = (double)(e-s)/CLOCKS_PER_SEC;
	return pfs;
}

int main()
{
	loop:
	int n;
	scanf("%d", &n);
	
	double loops;
	vector<vector<int>> pfs = pffs(n, loops);
	
	for(int i=0; i<=n; i++)
	{
		printf("%d ==> ", i);
		for(auto x : pfs[i]) 
			printf("%d ", x);
		puts("");
	}
	printf("Total times: %lf\n", loops);
	puts("");
	goto loop;
	
	return 0;
}
