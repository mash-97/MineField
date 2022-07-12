#include <stdio.h>

int main(){
     int array[1000];
     int anum = 0;
     int i = 0;
     while(anum != 42){
               scanf("%d", &anum);
               if(anum >-100 && anum<100 && anum != 42){
                    array[i] = anum;
                    i++;
               }
     }
     for(int j = 0; j<i; j++) printf("%d\n", array[j]);
     return 0;
}
