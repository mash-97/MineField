#include <iostream>
#include <map>
#include <unordered_map>
#include <stdio.h>
using namespace std;


void display(int n, int *array)
{
	for(int i=0; i<n; i++) printf("%d ", array[i]);
	puts("\n");
}

int getLimit(int minimum_value, int maximum_value)
{
	return maximum_value-minimum_value+1;
}

int getIndex(int value, int minimum_value)
{
	return abs(value-minimum_value);
}

int getValue(int index, int minimum_value)
{
	return minimum_value+index;
}

int maximum_value(int n, int *array)
{
	int maxi = -(int)__builtin_inf();
	for(int i=0; i<n; i++) if(array[i]>maxi) maxi = array[i];
	return maxi;
}

int minimum_value(int n, int *array)
{
	int mini = (int) __builtin_inf();
	for(int i=0; i<n; i++) if(array[i]<mini) mini = array[i];
	return mini;
}
	
void counting_sort(int n, int *array)
{
	int minima = minimum_value(n, array);
	int maxima = maximum_value(n, array);
	int limit = getLimit(minima, maxima);
	int helper_array[limit];
	
	for(int i=0; i<limit; i++) helper_array[i] = 0;
	for(int i=0; i<n; i++)	helper_array[getIndex(array[i], minima)]++;
	
	int k=0;
	for(int i=0; i<limit; i++)
	if(helper_array[i])
	{
		int value = getValue(i, minima);
		int total = helper_array[i];
		while(total--) array[k++] = value;
	}
}

void merge_sort(int n, int *array)
{
	map<int, int> map;
	for(int i=0; i<n; i++) map[array[i]]++;
	int k=0; 
	for(auto x: map)
	{
		int value = x.first;
		int total = x.second;
		while(total--) array[k++] = value;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int array[n];
	for(int i=0; i<n; i++) scanf("%d", &array[i]);

	counting_sort(n, array);
	//~ merge_sort(n, array);
	display(n, array);
	return 0;
}

