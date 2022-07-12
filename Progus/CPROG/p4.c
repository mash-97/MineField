#include <stdio.h>
#include <math.h>
int main(){
    int a=0, b=0, c = 66;
    printf("a = %d, b = %d, EOF = %d\n", a, b, EOF);
    while(c != EOF){
        c = scanf("%d%d", &a, &b);
        printf("%d\n", abs(a-b));
    }
    return 0;
}
