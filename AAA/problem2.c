#include <stdio.h>
#include <string.h>

// Check if the string contains comment starts with double front slash: (//)
int startsWithDoubleFrontSlash(char *string, int length){
    for(int i=0; i<length-1; i++){
        if(string[i]=='/' && string[i+1]=='/'){
            return 1;
        }
        else if(!(string[i]==' ' || string[i]=='\t')){
            return 0;
        }
    }
    return 0;
}

/* Checks if the string contains comment starts with a front slash, an asterisk pattern (/*) and
ends with --> */
int startsWithSlashAndAsterisk(char *string, int length){
    int first_pattern_found = -1;
    for(int i=0; i<length-1; i++){
        if(string[i]=='/' && string[i+1]=='*'){
            first_pattern_found = i;
            break;
        }
        else if(!(string[i]==' ' || string[i]=='\t')){
            return 0;
        }
    }
    if(first_pattern_found==-1) return 0;

    for(int i=length; i>first_pattern_found+3; i--){
        if(string[i]=='/' && string[i-1]=='*'){
            return 1;
        }
        else if(!(string[i]==' ' || string[i]=='\t' || string[i]=='\0' || string[i]=='\n')){
            return 0;
        }
    }
    return 0;
}

int main(){
    char line[1000];
    scanf("%[^\n]s", line);

    int length = strlen(line);
    if(startsWithDoubleFrontSlash(line, length) || startsWithSlashAndAsterisk(line, length))
        printf("It's a comment!\n");
    else
        printf("It's not a comment!\n");
    return 0;
}
