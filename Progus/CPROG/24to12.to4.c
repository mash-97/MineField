#include <stdio.h>
int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        int tH, tM;scanf("%d:%d", &tH, &tM);
        if(tH>12)printf("Case %d: %d:%d PM\n", i, tH-12, tM);
        else printf("Case %d: %d:%d AM\n", i, tH, tM);
    }
    return 0;
}
