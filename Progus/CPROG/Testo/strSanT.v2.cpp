#include <bits/stdc++.h>
using namespace std;

int checkStr(char *s, char *t, int n)
{
	char ss[n], tt[n];
	
	strcpy(ss, s);
	strcpy(tt, t);
	
	sort(ss, ss+n);
	sort(tt, tt+n);
	
	for(int i=0; i<n; i++) if(ss[i]!=tt[i]) return 0;
	
	return 1;
}

void swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int n;
	scanf("%d", &n);
	char s[n], t[n];
	scanf("%s", s);
	scanf("%s", t);
	
	int moves[10010];
	int total_moves = 0;
	int i=0;
	
	if(!checkStr(s, t, n)) printf("-1\n");
	else
	{
		while(total_moves < 10000)
		{
			if(strcmp(s, t)==0) break;
			if(i<n-1)
			{
				swap(&s[i], &s[i+1]);
				moves[total_moves++] = ++i;
			}
			else
			{
				i=0;
			}
		}
		
		//printf("s: %s, t: %s\n", s, t);
		if(total_moves >= 10000) printf("-1\n");
		else 
		{
			printf("%d\n", total_moves);
			for(i=0; i<total_moves-1; i++) printf("%d ", moves[i]);
			printf("%d\n", moves[i]);
		}
	}
	
	return 0;
}
	
	
