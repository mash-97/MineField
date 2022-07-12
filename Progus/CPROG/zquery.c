#include <stdio.h>


int main(){
     int N, M, L, R;
     int to, tmo;
     int array[50000];
     scanf("%d%d", &N, &M);
          for(int i=0; i<N; i++)scanf("%d", &array[i]);
          while(M--){
               scanf("%d%d", &L, &R);
                    to = 0, tmo = 0;
                    for(int i=L-1; i<R; i++){
                         if(array[i]==1)to++;
                         else if(array[i]==-1)tmo++;
                    }
                    if((to>tmo || to==tmo) && tmo != 0)printf("%d\n", tmo*2);
                    else if(tmo>to && to!=0)printf("%d\n", to*2);
                    else printf("0\n");
          }
     return 0;
}
