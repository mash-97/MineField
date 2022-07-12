#include <stdio.h>

int main()
{
	FILE *of = fopen("in.txt", "w+");
	FILE *to = fopen("out.txt", "w");
	int a, b, total_readed_inputs, total_written_inputs;
	char astring[55];
	char as[55], bs[55];
	char anotherstr[55];
	scanf("%d%d%s%s", &a, &b, astring, as);
	total_written_inputs = fprintf(of, "%d %d %s\n%s", a, b, astring, as);
	fclose(of);
	
	of = fopen("in.txt", "r+");
	int c, d, sum;
	
	
	total_readed_inputs = fscanf(of, "%d%d%s%s", &c, &d, anotherstr, bs);

	
	sum = c+d;
	printf("a = %d, b = %d\nc = %d, d = %d\nsum = %d\n r = %d\n w = %d\n", a, b, c, d, sum, total_readed_inputs, total_written_inputs);
	fprintf(to, "%d%s\n%s", sum, anotherstr, bs); 
	
	fclose(to);
	fclose(of);
	
	return 0;
}
	
