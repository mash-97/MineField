#include <stdio.h>
#include <math.h>
int main()
{
    int number, T; scanf("%d", &T);
    double sqr_root;

    while(T--)
    {
        scanf("%d", &number);
        sqr_root = sqrt(number);
        if(ceil(sqr_root)==floor(sqr_root))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
