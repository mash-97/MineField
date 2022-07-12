#include <stdio.h>
#include <math.h>

int main(){
     long int a = 0, b = 0;
     while(((scanf("%d %d", &a, &b)) != 0) &&(a <= pow(2,32) && b <= pow(2,32))){
               printf("%d\n", abs(a-b));
     }
     return 0;
}
