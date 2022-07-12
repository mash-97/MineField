#include <stdio.h>

int main()
{
	int array[10][2], bangs[10][2];
	int r, n;
	FILE * fp = fopen("math.txt", "r");
	FILE * bp = fopen("bangla.txt", "r");
	/*for(int i=0; i<10; i++)
	{
		fscanf(fp, "%d %d", &r, &n);
		array[i][0] = r;
		array[i][1] = n;
		fscanf(bp, "%d %d", &r, &n);
		bangs[i][0] = r;
		bangs[i][1] = n;
	}*/
	int i=1; //
	while(i<3)
	{
		FILE *fp = fopen("math.txt", "r");
		fscanf(fp, "%d %d", &r, &n);
		printf("r = %d, n = %d\n", r, n);
		fscanf(fp, "%d %d", &r, &n);
		printf("r = %d, n = %d\n", r, n);
		fclose(fp);
		i++;
	}
	printf("Displaying::\n");
	printf("      Math 		Bangla%c %s\n", 100, #array);
	//for(int i=0; i<10; i++) printf("%d -------->> %d  |  %d --------->> %d\n", array[i][0], array[i][1], bangs[i][0], bangs[i][1]);
	
	return 0;
}
