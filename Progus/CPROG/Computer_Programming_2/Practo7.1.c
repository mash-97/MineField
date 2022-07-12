#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *m;
	int n;
	printf("How much ?: and enter: ");
	scanf("%d", &n);
	
	m = 
	
	 malloc(sizeof(m)*n);
	for(int i=0; i<n; i++) scanf("%d", &m[i]);
	
	printf("number you entered: ");
	for(int i=0; i<n; i++) printf("%d ", m[i]);
	printf("\n");
	
	return 0;
}

