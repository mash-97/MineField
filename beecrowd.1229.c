#include <stdio.h>
#include <malloc.h>

typedef struct Node{
	int id;
	Node *adjacents;
};


int main(){
	int N;
	Node *a = (*Node) malloc(sizeof(Node));
	a->id = 1;
	printf("a: %d\n", a->id);
	
	while(scanf("%d", &N)!=EOF){
		printf("N: %d\n", N);
	}
	return 0;	
}