#include <stdio.h>

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    char string[n+1];
    scanf(" %[^\n]", string);

    for(int i=0; i<n; i++)
      string[i] = (string[i] | 32);
    
    char meow[4] = {'m', 'e', 'o', 'w'};
    int indx=0, flag=1;
    if(string[0]!='m') flag=0;
    for(int i=0; i<n&&flag; i++) {
      if(meow[indx]!=string[i])
        if(indx+1<4 && meow[++indx]==string[i])
	  continue;
        else
	  flag = 0;
    }
    if(flag && indx==3)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
