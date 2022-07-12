#include <stdio.h>

int main()
{
	int array[5] = {100, 20, 10, 5, 1};
	int ans = 0;
	int note;
	scanf("%d", &note);
	int note1 = note;
	int asn = 0;
	
	for(int i=0; i<5; i++)
	{
		ans += note/array[i];
		note %= array[i];
	}
	
	printf("%d\n", ans);
	return 0;
}
	
