#include <stdio.h>
int main()
{
    int T, n, i; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(i=1; i<=n*n; i++)
        {
            printf("*");
            if(i%n==0)printf("\n");
        }
        printf("\n");
    }
    return 0;
}
