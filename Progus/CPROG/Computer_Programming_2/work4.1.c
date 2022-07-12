#include <stdio.h>

int count;
int numb;
int sum;

int seqSum()
{
	++count;
	sum+=count;
	if(count!=numb) seqSum();
	return sum;
}

int main()
{
	count = 0;
	sum = 0;
	
	scanf("%d", &numb);
	
	sum = seqSum();
	printf("%d := %d\n", numb, sum);
	main();
}
