#include <stdio.h>

int main()
{
	int T,n;
	scanf("%d", &T);
	int j;
	for(j=1; j<=T; j++)
	{
		scanf("%d", &n);
		int array[n];
		int i;
		for(i=0;i<n; i++)scanf("%d", &array[i]);
		printf("Set %d: ", j);
		for(i=0;; i+=2){
			printf("%d ", array[i]);
			if(i+2<n)printf(" ");
			else break;
		}
		printf("\n");
	}
	return 0;
}
