#include <stdio.h>


int  main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, r, b;
		scanf("%d%d%d", &n, &r, &b);
		
		if(b==1){
			int div2 = r/2;
			for(int i=0; i<div2; i++) 
				printf("R");
			printf("B");
			for(int i=div2+1; i<n; i++)
				printf("R");
			printf("\n");
			continue;
		}
		
		int divrb = r/b;
		int hndivrb = n/(divrb+1);
		int hnrem = n%(divrb+1);
		
		char hc[divrb+2];
		hc[divrb+1] = '\0';
		
		for(int i=0; i<divrb; i++) hc[i] = 'R';
		hc[divrb] = 'B';
		
		
		if(hnrem>divrb){
			int sub = (hnrem-divrb);
			int eaddr = sub/2;
			int laddr = sub/2;
			
			if((sub&1)==1) laddr += 1;
			
			char ec[eaddr+laddr+2];
			ec[eaddr+laddr+1] = '\0';
			for(int i=0; i<eaddr; i++) ec[i] = 'R';
			ec[eaddr] = 'B';
			for(int i=eaddr+1; i<laddr+1; i++) ec[i] = 'R';
			
			for(int i=1; i<hndivrb; i++)
				printf("%s", hc);
			printf("%s", ec);
		}
		else{
			for(int i=1; i<=hndivrb; i++) 
				printf("%s", hc);
			for(int i=1; i<=hnrem; i++)
				printf("R");
		}
		printf("\n");
			
			
	}
		
	return 0;
}
