#include <stdio.h>
int main()
{
    int T, number;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &number);
        printf("Sum = %d\n", (number%10) + (number/10000));
    }
    return 0;
}
