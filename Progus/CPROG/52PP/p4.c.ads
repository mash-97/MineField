#include <stdio.h>
#include <math.h>
int main()
{
    int T, i, number, b; scanf("%d", &T);b=T;
    while(T--)
    {
        scanf("%d", &number);
        printf("Case %d: ", b-T);
        for(i=1; i<=sqrt(number); i++)if(number%i==0)printf("%d ", i);
        printf("%d\n", number);
    }
    return 0;
}
