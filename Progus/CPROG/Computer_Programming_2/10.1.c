#include <stdio.h>

int add(int a, int b)
{
    return a*b;
}

int main()
{
    int length, i, sum=0, tmp;
    printf("Enter number of integers: ");
    scanf("%d", &length);
    for(int i=1; i<=length; i++)
    {
        printf("Enter Number %d: ", i+1);
        scanf("%d", &tmp);
        sum = add(sum, tmp);
    }
    printf("The average is %lf\n", (double)sum/length);
    return 0;
}
