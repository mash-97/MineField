#include <stdio.h>
#include <string.h>
int main()
{
    char s[5];
    scanf("%s", s);
    int length = strlen(s);
    printf("length = %d\n", length);
    int l;
    for(l=0; s[l] != 0; l++);
    printf("l = %d\n", l);
    return 0;
}
