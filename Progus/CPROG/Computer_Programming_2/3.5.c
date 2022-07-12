#include <stdio.h>

int main()
{
	FILE *in, *out;
	char *input_filename, *output_filename;
	int total_written_characters;
	char string[400];								//for fgets function.
	char *string_pointer;
	int num1, num2, r;
	int num_1, num_2, sum;
	char input_string1[100], input_string2[100];	//for scanning inputs and writing to the input file.
	char input_string_1[100], input_string_2[100];	//for keening inputs.
	
	input_filename = "in.txt", output_filename = "out.txt";
	
	in = fopen(input_filename, "w");
	scanf("%d%d%s%s", &num1, &num2, input_string1, input_string2);
	
	//Writing inputs to the input file.
	total_written_characters = fprintf(in, "%d %d %s %s\n", num1, num2, input_string1, input_string2);
	printf("Inputs are written in \"%s\" file: total written characters: %d\n", input_filename, total_written_characters);
	
	r = fclose(in);
	if(r==0)printf("The file \"%s\" in 'w' mode is closed successfully.\n", input_filename);
	
	//Keening inputs from input file to output file.
	in = fopen(input_filename, "r");
	out = fopen(output_filename, "w");
	
	//Using fgets...
	string_pointer = fgets(string, 400, in);
	printf("String fetched by fgets function:: string_pointer = %s, string = %s\n", string_pointer, string);
	
	r = sscanf(string, "%d%d%s%s", &num_1, &num_2, input_string_1, input_string_2);
	if(r!=EOF)printf("successfully used sscanf return value = %d, num_1 = %d, num_2 = %d, input_string_1 = %s, input_string_2 = %s\n", r, num_1, num_2, input_string_1, input_string_2);
	sum = num_1 + num_2;
	
	//writing out put in the output file.
	r = fprintf(out, "%d\n%s\n%s\n%s\n", sum, input_string_1, input_string_2, string);
	
	fclose(in);
	fclose(out);
	
	return 0;
}
	
	
