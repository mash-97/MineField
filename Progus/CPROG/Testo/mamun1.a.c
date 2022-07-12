#include <stdio.h>
int main()
{
	int i=0;
	while(i<6)
	{
		if(i==3){ i++; continue;}
		printf("Index is %d\n", i);
		i++;
	}
	return 0;
}
