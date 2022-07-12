#include <bits/stdc++.h>
using namespace std;

int main()
{
	while(1)
	{
		int p, i;
		scanf("%d", &p);
		if(p==0)break;
		int agep[p];
		
		for(i=0; i<p; i++) scanf("%d", agep+i);
		
		sort(agep, agep+p);
		
		for(i=0; i<p-1; i++)printf("%d ", agep[i]);
		printf("%d\n", agep[i]);
		
		int *k = unique(agep, agep+p);
		int *l = agep;
		
		for(i=0; l!=k; i++, l++)printf("%d ", agep[i]);
		puts("");
	}
	return 0;
}
