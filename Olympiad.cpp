#include <bits/stdc++.h>

using namespace std;

void display(int *array, int length)
{
	for(int i=0; i<length; i++) printf("%d ", array[i]);
	puts("");
}

int unionOfSets(int set_A[], int a, int set_B[], int b, int union_array[])
{
	int i;
	for(i=0; i<a; i++) union_array[i] = set_A[i];
	for(; i<a+b; i++) union_array[i] = set_B[i-a];
	
	sort(union_array, union_array+i);
	int unique_length = unique(union_array, union_array+i) - union_array;
	
	return unique_length;
}

int intersectOfSets(int set_A[], int a, int set_B[], int b, int intersect_array[])
{
	int s = a, l = b;
	int *seta = set_A, *setb = set_B;
	
	if(a > b)
	{
		s = b;	l = a;
		seta = set_B;	setb = set_A;
	}
	
	int intersect_length = 0;
	for(int i=0; i<s; i++)
		for(int j=0; j<l; j++)
			if(seta[i] == setb[j]) intersect_array[intersect_length++] = seta[i];
	
	sort(intersect_array, intersect_array+intersect_length);
	
	return intersect_length;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int kase = 1; kase <=t; kase++)
	{
		int a, b;
		char c;
		scanf("%d %d %c", &a, &b, &c);
		
		int set_A[a], set_B[b];
		for(int i=0; i<a; i++) scanf("%d", &set_A[i]);
		for(int i=0; i<b; i++) scanf("%d", &set_B[i]);
		
		int result_array[a+b];
		int result_length;
		
		printf("Case #%d: ", kase);
		switch(c)
		{
			case 'U': 
				result_length = unionOfSets(set_A, a, set_B, b, result_array);
				
				display(result_array, result_length);
			break;
			
			case 'I':
				result_length = intersectOfSets(set_A, a, set_B, b, result_array);
				
				display(result_array, result_length);
			break;
		}
	}
	return 0;
}
	
