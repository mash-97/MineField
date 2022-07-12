#include <stdio.h>

int reverseNum(int num)
{
	int rev=0;
	while(num!=0)
	{
		rev *= 10;
		rev += num%10;
		num /= 10;
	}
	return rev;
}

int main()
{
	int T, num;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &num);
		printf("%d\n", reverseNum(num));
	}
	return 0;
}
