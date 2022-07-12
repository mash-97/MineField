#include <stdio.h>
#include <string.h>

//** WITH FREEWORLD's LICENCE
/* \
 *  \
 * 	YO whazzup dude!
 * /
 */
 // Remember: The original writer isn't responsible for any inconvenience
int max(int a, int b)
{
	return a>b ? a:b;
}
int min(int a, int b)
{
	return a<b ? a:b;
}
int longestCommonSubsequence(char *marray, char *narray, char *sequence)
{
	int m = strlen(marray);
	int n = strlen(narray);
	int array[m+1][n+1];
	for(int i=0; i<=m; i++) array[i][0]=0;
	for(int i=0; i<=n; i++) array[0][i]=0;
	
	for(int i=1; i<=m; i++)
	for(int j=1; j<=n; j++)
	{
		if(marray[i-1]==narray[j-1])
			array[i][j] = array[i-1][j-1]+1;
		else 
			array[i][j] = max(array[i-1][j], array[i][j-1]);
	}
	int llength = array[m][n];
	int k=llength-1;
	sequence[llength] = 0;
	
	int i=m, j=n;
	while(i>0 && j>0)
	{
		if(array[i][j]>array[i][j-1] && array[i][j]> array[i-1][j])
			sequence[k--] = marray[--i];
		else if(array[i-1][j]>array[i][j-1])
			i--;
		else 
			j--;
	}
	return llength;
}

int main()
{
	char st1[100];
	char st2[100];
	
	scanf(" %s", st1);
	scanf(" %s", st2);
	
	char subst[min(strlen(st1), strlen(st2))+1];
	int length = longestCommonSubsequence(st1, st2, subst);
	printf("length: %d\n", length);
	printf("subsequence: %s\n", subst);
	
	return 0;
}

