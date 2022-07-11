
#include <stdio.h>

int test(){

int n;
    scanf("%d", &n);
    int moves[n];
    for(int i=0; i<n; i++)
        scanf("%d", &moves[i]);

    for(int i=moves[0]; i<n;){
        if(i==n-1){
            printf("true\n");
            return 0;
        }
        int next_move = moves[i];

        if((i+next_move>n-1 && i!=n-1) || (moves[i+next_move]==0 && i+next_move != n-1))
        {
            printf("false\n");
            return 0;
        }
        i+=next_move;
    }
    printf("false\n");
    return 0;
}
int main(){
    while(1) test();
    return 0;
}
