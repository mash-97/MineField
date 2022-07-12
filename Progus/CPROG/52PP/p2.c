#include <stdio.h>
#include <string.h>
int main()
{
    int T, length, num; scanf("%d", &T);
    char number[101];
    while(T--)
    {
        scanf("%s", number);
        length = strlen(number);
        num = 0+(number[length-1]-'0');
        if(num%2==0)printf("even\n");
        else printf("odd\n");
    }
    return 0;
}
