#include <stdio.h>

int main() {
    while(1) {
        int N, B;
        scanf("%d%d", &N, &B);
        if(N==0 && B==0) break;

        int bs[B];
        for(int i=0; i<B; i++)
            scanf("%d", &bs[i]);

        int sa[N+1];
        for(int i=0; i<=N; i++)
            sa[i] = 0;
        for(int i=0; i<B; i++)
            sa[bs[i]] = 1;
        for(int i=0, j=0; i<=N; i++)
            if(sa[i]==1)
                bs[j++] = i;

        if(B>0) sa[0]=1;
        int check_n = 1;
        for(int i=0; i<=N; i++)
        {
            if(sa[i]==1) continue;
            int found=0;
            for(int j=0; j<B; j++) {
                if(bs[j]+i>N) break;
                if(sa[bs[j]+i]==1) {
                    found=1;
                    break;
                }
            }
            if(!found) {
                check_n=0;
                break;
            }
        }
        if(!check_n)
            printf("N\n");
        else
            printf("Y\n");
    }
    return 0;
}
