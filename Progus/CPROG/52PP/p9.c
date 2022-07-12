#include <stdio.h>
#include <math.h>
int main()
{
    int T; scanf("%d", &T);
    int number;
    while(T--)
    {
        scanf("%d", &number);
        double root = sqrt(number);
        int i = root;
        double d = i;
        if(d==root)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
