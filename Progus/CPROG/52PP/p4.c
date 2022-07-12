#include <stdio.h>
#include <math.h>
int main()
{
    int T, i, number, b, root; scanf("%d", &T);b=T;
    while(T--)
    {
        scanf("%d", &number);
        root = sqrt(number)+(number/2);
        printf("Case %d:", b-T);
        for(i=1; i<=root; i++)if(number%i==0)printf(" %d", i);
        if(root!=1)printf(" %d\n", number);
        else printf("\n");
    }
    return 0;
}
