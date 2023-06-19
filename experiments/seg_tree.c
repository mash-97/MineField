#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

typedef struct{
	int val;
	char name[101];
} Seg;

void test(int *ref) {
	(*ref) += 100000;
	printf("ref: %d\n", *ref);	
}
void printTime() {
	char *date_time_str;
	time_t date_time;
	date_time = time(NULL);
	date_time_str = ctime(&date_time);
	printf("time: %s", date_time_str);
}

int add(int a, int b){
	printf("%d + %d = %d\n", a, b, a+b);
	return a+b;
}

int operate(int a, int b, int (*f)(int,int)){
	return f(a, b);
}

void fr_test() {
	
	freopen("seg.out", "w+", stdout);
	freopen("seg.int", "r+", stdin);
	
	Seg * s = (Seg *) malloc(sizeof(Seg)*5);
	
	int sum = 0;
	for(int i=0; i<5; i++)
	{
		freopen("seg.in", "r+", stdin);
		(s+i)->val = 5*i*5;
		scanf(" %[^\n]", (s+i)->name);
		printf("[%d]\n", i);
		printf("val: %d\n", (s+i)->val);
		printf("name: %s\n", (s+i)->name);
		sum += s[i].val;
	}
	printf("s: %d\n", sum);
	test(&sum);
	printf("after ref, s: %d\n", sum);
	printf("op: %d\n", operate(5, 1, add));
	printf("==============================\n");
	printTime();
	printf("==============================\n");
}

int twos_multiple(int num) {
	if(num <= 0) return 0;
	int i=1;
	while(i<num) i*=2;
	return i;
}

int parent(int indx) {
	return indx/2;
}
int left_child(int indx) {
	return indx*2;
}
int right_child(int indx) {
	return indx*2+1;
}

int get_btree_size(int size_offset) {
	int btree_size = (twos_multiple(size_offset)*2);
	return btree_size;
}

void print_btree(int level, int last_indx, int size_offset, int * btree) {
	static int is = 6;
	if(size_offset==0) {
		printf("\n");
		return;
	}
	
	int first_interval_size = (int) pow(2, level)-1; 
	int interval_size = (int) pow(2, level+1)-1;
	
	void print_space(const int is, int unit_size){
		for(int i=1; i<=(unit_size*is); i++) printf(" ");
	}
	// pre-spaces
	print_space(is, first_interval_size);
	
	printf("%6d", btree[--last_indx]);
	
	for(int i=size_offset-1; i>0; i--) {
		print_space(is, interval_size);
		printf("%6d", btree[--last_indx]);
	}
	printf("\n");	
	print_btree(level+1, last_indx, size_offset/2, btree);
}

void build_btree(int leaf_size, int * leaf_array, int btree_size, int * btree) {
	int btree_indx = btree_size-1;
	
	printf("===============\n");
	for(int i=1; i<btree_size; i++) {
		printf(" %d ", btree[i]);
	}
	printf("===============\n");
	
	for(int j=leaf_size-1; j>=0; j--) {
		btree[btree_indx] = leaf_array[j];
		btree[parent(btree_indx)] += btree[btree_indx];
		btree_indx--;
	}
	

	while(btree_indx>0) {
		btree[parent(btree_indx)] += btree[btree_indx];
		btree_indx--;
	}		
	return;
}

// indx => current node
// indx_offset => starts from the current code
// 				  navigates the traversing
// val => new value
// size_offset => number of leaf s in the tree
int change_value(int indx, int indx_offset, const int val, int size_offset, int *btree) {
	int sd = size_offset/2;
	int tmp;
	if(sd==0){
		tmp = btree[indx];
		btree[indx] = val;
		return tmp;
	}
	if(indx_offset <= sd) {
		tmp = change_value(left_child(indx), indx_offset, val, size_offset/2, btree);
	}
	
	else {
		tmp = change_value(right_child(indx), indx_offset-sd, val, size_offset/2, btree);
	}
	btree[indx] -= tmp;
	btree[indx] += val;
	return tmp;
}

int range_sum_query(int curr_indx, int ai, int bi, int li, int ri, int *btree) {
	if(ai==li && ((ai==bi && ai==ri) || bi==ri)) return btree[curr_indx];
	
	int left_child_li = li, left_child_ri = ri/2;
	int right_child_li = (ri/2)+1, right_child_ri = ri;
	
	if(ai>=left_child_li && ai<=left_child_ri) {
		if(bi <= left_child_ri) return range_sum_query(left_child(curr_indx), ai, bi, left_child_li, left_child_ri, btree);
		return range_sum_query(left_child(curr_indx), ai, left_child_ri, left_child_li, left_child_ri, btree) +
			   range_sum_query(right_child(curr_indx), right_child_li, bi, right_child_li, right_child_ri, btree);
	}
	if(bi>=right_child_li && bi<=right_child_ri) {
		if(ai <= right_child_li) return range_sum_query(right_child(curr_indx), right_child_li, bi, right_child_li, right_child_ri, btree);
		
	}
	return -1000000;
}

int rsq(int curr_indx, int ai, int bi, int li, int ri, int *btree) {
	
	if(ai==li && ((ai==bi && ai==ri) || bi==ri))
		return btree[curr_indx];
	
	int halve = li+(ri-li)/2;
	if(ai>= li && bi <= halve)
		return rsq(left_child(curr_indx), ai, bi, li, halve, btree);
	
	if(ai > halve && bi <= ri)
		return rsq(right_child(curr_indx), ai, bi, halve+1, ri, btree);
	
	if(ai <= halve && bi > halve)
		return rsq(left_child(curr_indx), ai, halve, li, halve, btree) +
			   rsq(right_child(curr_indx), halve+1, bi, halve+1, ri, btree);
	
	
	return -1000000;
}


int main(){
	//freopen("seg.in", "r+", stdin);
	int temp;
	scanf("%d", &temp);
	while(temp--) {
		int leaf_size;
		printf("enter size: ");
		scanf("%d", &leaf_size);
		int leaf_array[leaf_size];
		for(int i=0; i<leaf_size; i++) {
			scanf("%d", &leaf_array[i]);
		}
		
		int * btree=NULL;
		
		int btree_size = get_btree_size(leaf_size);
		
		btree = (int *) malloc(sizeof(int)*btree_size);
		for(int i=1; i<btree_size; i++)
			btree[i] = 0;
		
		//~ printf("===============\n");
		//~ for(int i=1; i<btree_size; i++) {
			//~ printf(" %d ", btree[i]);
		//~ }
		//~ printf("===============\n");
		
		
		printf("after get btree, btree_size: %d\n", btree_size);
		build_btree(leaf_size, leaf_array, btree_size, btree);
		printf("after build btree\n\n");
		printf("===============\n");
		for(int i=1; i<btree_size; i++) {
			printf(" %d ", btree[i]);
		}
		printf("\n===============\n");
		print_btree(0, btree_size, twos_multiple(leaf_size), btree);
		
		int mod_temp;
		printf("enter mod temp: ");
		scanf("%d", &mod_temp);
		while(mod_temp--) {
			int indx_offset, val;
			printf("enter idxoffset and val: ");
			scanf("%d %d", &indx_offset, &val);
			change_value(1, indx_offset, val, leaf_size, btree);
			printf("after value change: \n");
			print_btree(0, btree_size, twos_multiple(leaf_size), btree);
			printf("\n\n");
		}
		
		printf("number of rsq: ");
		scanf("%d", &mod_temp);
		while(mod_temp--) {
			printf("enter range sum query: ");
			int ai, bi;
			scanf("%d%d", &ai, &bi);
			printf("for %d and %d => %d\n", ai, bi, rsq(1, ai, bi, 1, twos_multiple(leaf_size), btree));
		}
		
		free(btree);
	}
	
	return 0;
}
