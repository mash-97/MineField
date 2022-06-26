#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char string[1000001];
	scanf(" %[^\n]", string);
	
	int max_count = -1;
	int tmp_count = 1;
	char prev_char = string[0];
	int string_length = strlen(string);
	
	for(int i=1; i<string_length; i++){
		if(prev_char==string[i])
			tmp_count += 1;
		else{
			if(tmp_count>max_count)
				max_count = tmp_count;
			tmp_count = 1;
			prev_char = string[i];
		}
	}
	if(tmp_count>max_count) max_count=tmp_count;
	printf("%d\n", max_count);
	
	return 0;
}
