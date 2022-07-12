#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> numbers[10000];

void produce_factors(int n)
{
	numbers[1].push_back(1);
	int lim = (int) sqrt(n*1.0) + 1;
	for(int i=2; i<=n; i+=2)
	{
		numbers[i].push_back(1);
		numbers[i].push_back(2);
	}
	
	for(int i=3; i<=n; i+=2)
	{
		numbers[i].push_back(i);
		if(i <= lim)
		{
			for(int j=i*i; j<=n; j+=2*i)
				numbers[j].push_back(i);
		}
	}
	
	for(int i=2; i<=n; i+=2)
		numbers[i].push_back(i);
}

void display_vector(vector <int> v)
{
	for(auto x = v.begin(); x!=v.end(); x++)
		cout << *x << " ";
	cout << endl;
}

int main()
{
	produce_factors(100);
	int n;
	x: 
	cout << "Enter a number between 1 and 100 to see factors: ";
	cin >> n;
	
	cout << "Factors of " << n << " are: ";
	display_vector(numbers[n]);
	cout <<endl;
	goto x;
	return 0;
}
