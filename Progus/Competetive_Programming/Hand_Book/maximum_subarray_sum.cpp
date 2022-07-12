#include <iostream>
#include <vector>
using namespace std;

//~ template <typename T>
//~ T max(T a, T b) {return a>b ?a : b;}

vector <int> ms_array;

long long int algorithm_1(int X[], int n)
{
	int max_sum = 0;
	
	for(int a=0; a<n; a++)
	{
		for(int b=a; b<n; b++)
		{
			int sum = 0;
			vector <int> s_array;
			for(int c=a; c<=b; c++)
			{
				s_array.push_back(X[c]);
				sum+=X[c];
			}
			if(sum>max_sum)
			{
				max_sum = sum;
				ms_array = s_array;
			}
		}
	}
	return max_sum;
}

long long int algorithm_2(int X[], int n)
{
	int max_sum = 0;
	
	for(int a=0; a<n; a++)
	{
		vector <int> s_array;
		int sum = 0;
		for(int b=a; b<n; b++)
		{	
			s_array.push_back(X[b]);
			sum+=X[b];
				
			if(sum>max_sum)
			{
				max_sum = sum;
				ms_array = s_array;
			}
		}
	}
	return max_sum;
}

long long int algorithm_3(int X[], int n)
{
	cout<<endl;
	int s=0, p=0;
	for(int i=0; i<n; i++)
	{
		s = max(X[i], (s+X[i]));
		p = max(s, p);
		
		cout<<i+1<<". s: "<<s<< " and p: "<<p<<endl;
	}
	return p;
}

void disv(vector <int> v)
{
	for(auto x: v) cout << x << " ";
	cout<<"\n";
}

int main()
{
	cout <<"Max: "<<max(3.3, 6.677777)<<endl;
	int n;
	cin >> n;
	int array[n];
	for(int i=0; i<n; i++) cin>>array[i];
	
	cout <<"Maximum sub-array sum is: "<<algorithm_3(array, n)<<endl;
	
	//cout <<"The sub-array is: "; disv(ms_array);
	
	return 0;
}
