#include <stdio.h>
#define printNov(v) printf("%s\n", #v);
#define printVos(v) printf("%s\n", v);
#define A "...---..."
long long int pascal[51][51];


void makePascalTriangle()
{
	pascal[0][0] = 1;
	pascal[1][0] = 1;
	pascal[1][1] = 1;
	for(int i=2; i<51; i++)
	{
		int j=0;
		pascal[i][0] = 1;
		for(j=1; j<i; j++) pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
		pascal[i][j] = 1;
	}
}


int main()
{
	makePascalTriangle();
		int T, l_n;
		print(l);
		scanf("%d", &T);
		while(T--)
		{
			scanf("%d", &l_n);
			for(int i=0; i<l_n+1; i++)
			for(int j=0; j<i+1; j++)
			{
				if(j==i)printf("%lld\n", pascal[i][j]);
				else printf("%lld ", pascal[i][j]);
			}
		}
		
		return 0;
}
