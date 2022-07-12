#include <stdio.h>

int main()
{
    int T, a, b, number, remainder, sum=0; scanf("%d", &T);
    while(T--)
    {
        sum=0;
        scanf("%d", &number);
        remainder=number%10;
        sum+=remainder;
        while(number/=10) remainder = number%10;
        sum+=remainder;
        printf("Sum = %d\n", sum);
    }
    return 0;
}
