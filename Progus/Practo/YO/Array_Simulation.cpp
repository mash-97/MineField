#include<bits/stdc++.h>

int N =100000000,prime[10000000]; 
int count = 0;
int status[100000000>>5];
void sieve()
{
	 int i, j, sqrtN; 
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 ) 
     {
		 if( (status[i>>5] & ( 1 << (i&31) ))==0)
		 {
	 		 for( j = i*i; j <= N; j += (i<<1) )
			 {
				 status[j>>5] |= (1 << (j&31));
	 		 }
		 }
	 }
	
	 prime[count++] = 2;
	 for(i=3;i<=N;i+=2)
		 if( (status[i>>5] & ( 1 << (i&31) ))==0)
			prime[count++] = i;
}

int main()

{
	sieve();
	for(int i=0; i<=count; i+=100)
		printf("%d\n", prime[i]);
	
	return 0;
}
