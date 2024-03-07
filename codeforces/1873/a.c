#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        char str[4];
        scanf(" %[^\n]", str);
        int res = ((str[0]=='a') + (str[1]=='b') + (str[2]=='c'));
        if(res==0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
