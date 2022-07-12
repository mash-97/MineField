#include <stdio.h>
#include <limits.h>

char bits[50];
int bits_count;
int dec2b(int number)
{
	if(number==0) return 0;
	
	bits[bits_count++] = 48+(number&1);
	return 1+dec2b(number>>1);
}
	int f=0;
int main()
{
	bits_count=0;
	int n=sizeof(int)*CHAR_BIT;
	if(f==0){f=1;printf("n = %d\n", n);}
	int i, count = 0, num;
	
	scanf("%d", &num);
	
	for(i=0; i<n; i++)
	{
		if(num & (1 << i)) count++;
		//printf("%d", (num&(1<<i)));
	}
	printf("Number of 1: %d\n", count);
	
	int length = dec2b(num);
	printf("length = %d\n", length);
	for(i=length-1; i>0; i--)printf("%c", bits[i]);
	printf("%c\n", bits[i]);
	puts("");
	main();
	return 0;
}
