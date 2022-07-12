#include <stdio.h>

int main()
{
	int T, num, res, tot, rem;
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d", &num);
		res = num;
		tot = 0;
		while(res!=0)
		{
			rem = res%10;
			res /= 10;
			tot += rem*rem*rem;
		}
		if(tot == num)printf("%d is an armstrong number!\n", num);
		else printf("%d is not an armstrong number!\n", num);
	}
	return 0;
}
