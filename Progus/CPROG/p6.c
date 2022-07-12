#include <stdio.h>

int main(){
     unsigned int a = 0, b = 0;
     while((scanf("%u%u", &a, &b) != 0) && (a <= 4294967296 && b <= 4294967296)){
          if(a > b) printf("%u\n", a-b);
          else printf("%u\n", b-a);
     }
     return 0;
}
