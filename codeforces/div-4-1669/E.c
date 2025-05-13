#include <stdio.h>

int mats[11][11];

unsigned long long int horizontal_sop() {
    unsigned long long int sop = 0;
    for(int k=0; k<11; k++)
    for(int i=0; i<11; i++)
        for(int j=i+1; j<11; j++)
            sop += ((unsigned long long int)mats[k][i])*mats[k][j];
    return sop;
}
unsigned long long int vertical_sop() {
    unsigned long long int sop = 0;
    for(int k=0; k<11; k++)
    for(int i=0; i<11; i++)
        for(int j=i+1; j<11; j++)
            sop += ((unsigned long long int)mats[i][k])*mats[j][k];
    return sop;
}
int main() {
    // FILE *file = fopen("E.in", "r");
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);

        for(int i=0; i<11; i++)
            for(int j=0; j<11; j++)
                mats[i][j]=0;

        char ss[3];
        for(int i=0; i<n; i++)
        {
            scanf(" %[^\n]", ss);
            mats[ss[0]-'a'][ss[1]-'a'] += 1;
        }

        long long int result = 0;
        result += horizontal_sop();
        result += vertical_sop();
        printf("%llu\n", result);
    }
    return 0;
}
