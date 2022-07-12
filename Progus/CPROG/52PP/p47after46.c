#include <stdio.h>

void concateWithSortA(int n1, int array1[], int n2, int array2[], int array[])
{
	int i=0, j=0, k=0;
	while(i<n1 || j<n2)
	{
		if(array1[i]>array2[j]) array[k++] = array2[j++];
		
		else array[k++] = array1[i++];
	}
}

void removeTwiced(int n, int array[])
{
	for(int i=0; i<n-1; i++)if(array[i]==array[i+1])for(int j=i+1; j<n-1; j++)array[j]=array[j+1];
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n1;
		scanf("%d", &n1);
		int an1[n1];
		for(int i=0; i<n1; i++)scanf("%d", &an1[i]);
		
		int n2;
		scanf("%d", &n2);
		int an2[n2];
		for(int i=0; i<n2; i++)scanf("%d", &an2[i]);
		
		int an[n1+n2];
		concateWithSortA(n1, an1, n2, an2, an);
		removeTwiced(n1+n2, an);
		printf("%d", an[0]);
		for(int i=1; i<n1+n2; i++)printf(" %d", an[i]);
		puts("");
		
	}
	
	return 0;
}
