#include <iostream>
#include <map>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <utility>
using namespace std;

void dispBits(int n)
{
	for(int i=31; i>=0; i--) 
		printf("%d", ((n>>i) & 1));
	puts("");
}

int limit(int min, int max)
{
	return abs(min)+abs(max)+1;
}

int bitArrayLimit(int limit, int size)
{
	return (limit/size)+(limit%size!=0);
}

pair<int,int> getBitIndex(int min, int value, int size)
{
	return {(value-min)/size, (value-min)%size};
}

int getIndexValue(int min, pair<int,int> bit_index, int size)
{
	return min + (size*bit_index.first) + bit_index.second;
}

void mark(int pos, int &n)
{
	n = n | (1<<pos);
}

bool isMark(int pos, int n)
{
	return (n>>pos) & 1;
}

int countingSort(int min, int max, int n, int *array)
{
	int lim = bitArrayLimit(limit(min, max), 32);
	printf("Inside countingSort:: array.size: %d\n\n", lim); 
	int mark_array[lim];
	printf("mark array size: %d, mark_array[0] size: %d\n", (int)sizeof(mark_array), (int)sizeof(mark_array[0]));
	
	for(int i=0; i<lim; i++) mark_array[i] = 0;
	
	pair<int,int> p;
	for(int i=0; i<n; i++)
	{
		p = getBitIndex(min, array[i], 32);
		mark(p.second, mark_array[p.first]);
	}
	
	int k = 0;
	for(int i=0; i<lim; i++)
	{
		for(int j=0; j<32; j++)
			if(isMark(j, mark_array[i]))
				array[k++] = getIndexValue(min, {i, j}, 32);
	}
	return k;
}

void disp(int n, int *array)
{
	FILE *f = fopen("countingSort.output", "w");
	for(int i=0; i<n; i++)
		fprintf(f, "%d ", array[i]);
	fputs("", f);
	fclose(f);
}

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

pair<bool,int> isSorted(int n, int *array)
{
	for(int i=1; i<n; i++)
		if(array[i-1]>=array[i])
			return {false, i};
	return {true, -1};
}

int getIIndex(int min, int value)
{
	return value-min;
}
int getIIndexValue(int min, int index)
{
	return index+min;
}
int getILimit(int min, int max)
{
	return abs(min)+abs(max)+1;
}

int countingSortUsingBitset(int min, int max, int n, int *array)
{
	
	
	int lim = getILimit(min, max);
	printf("Helper Array Size: %d\n", lim);
	bool helper_array[lim];
	printf("int: %d, char: %d, helper array: %d, helper_array[0] size: %d, \n", 
		(int)sizeof(int), (int)sizeof(char), (int)sizeof(helper_array), (int)sizeof(helper_array[0]));
	for(int i=0; i<lim; i++) helper_array[i] = false;
	for(int i=0; i<n; i++)
		helper_array[getIIndex(min, array[i])] = true;
	
	int count = 0;
	for(int i=0; i<lim; i++)
		if(helper_array[i]==true)
			array[count++] = getIIndexValue(min, i);
	
	return count;
}
	

int main()
{
	FILE *f = fopen("countingSort.input", "r");
	int n;
	fscanf(f, "%d", &n);
	int array[n];
	int brray[n];
	int crray[n];
	
	int min = (int)__builtin_inf(), max = -(int)__builtin_inf();
	for(int i=0; i<n; i++)
	{
		fscanf(f, "%d", &array[i]);
		if(array[i]<min) min = array[i];
		if(array[i]>max) max = array[i];
		crray[i] = brray[i] = array[i];
	}
	fclose(f);
	
	clock_t as = clock();
	int cn = countingSortUsingBitset(min, max, n, array);
	cn = countingSort(min, max, n, array);
	clock_t ae = clock();
	
	clock_t bs = clock();
	sort(brray, brray+n);
	clock_t be = clock();
	
	clock_t cs = clock();
	qsort(crray, n, sizeof(int), &compare);
	clock_t ce = clock();
	
	
	printf("min: %d, max: %d\n", min, max);
	printf("countingSort Time: %.2lf\n", (double)(ae-as)/CLOCKS_PER_SEC);
	printf("stlSort      Time: %.2lf\n", (double)(be-bs)/CLOCKS_PER_SEC);
	printf("quickSort    Time: %.2lf\n", (double)(ce-cs)/CLOCKS_PER_SEC);
	
	disp(cn, array);
	pair<bool, int> result;
	if((result = isSorted(cn, array)).first) 
		printf("Sorted!\n");
	else 
		printf("False!!! %d %d\n", array[result.second-1], array[result.second]);
	
	return 0;
}
