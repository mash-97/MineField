#include <stdio.h>

int main(){
    char text[10000];
    int i=0;
    char c;
    while((c=getchar()) != EOF){
        if(c==' ' || c=='\n' || c=='\t') continue;
        text[i++] = c;
    }
    text[i++]='\0';

    printf("%s\n", text);

    return 0;
}
