#include <stdio.h>
int main()
{
    int T;scanf("%d", &T);
    while(T--)
    {
        int number; scanf("%d", &number);
        for(int i=1; i<=number; i++)
        {
            for(int j=1; j<=number; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
