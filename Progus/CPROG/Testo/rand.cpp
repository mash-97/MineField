#include <iostream>
#include <cstdlib>

using namespace std;

const int ITERATIONS = 1e7;

int main()
{
	double sum = 0;
	
	for(int i=0; i<ITERATIONS; i++)
	{
		sum += rand() % 1000000;
		if(i<=100) printf("%d\n", rand()%1000000); 
	}
	
	cout << "Average value: " << sum/ITERATIONS << '\n';
	
	return 0;
}
