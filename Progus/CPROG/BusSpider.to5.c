#include <stdio.h>
int main(){
    int T; scanf("%d", &T);
    for(int k=1; k<=T; k++){
        int N, M; scanf("%d%d", &N, &M);
        int q=0, min=110;
        for(int i=1; i<=N; i++){
            int c, p; scanf("%d%d", &c, &p);
            if(min>c-p){q=i;min=c-p;}
        }
        if(min!=0)printf("Case %d: Bus number %d\n", k, q);
        else printf("Case %d: He is in the queue\n", k);
    }
    return 0;
}
