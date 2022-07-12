#include <stdio.h>
#define TOTAL 10

int rolls_and_averages[10][2];
FILE *mathFp;
FILE *banglaFp;
FILE *engFp;
FILE *avgFp;

void initialize(char math_file[], char bangla_file[], char english_file[])
{
	int roll, number;
	mathFp = fopen(math_file, "w+");
	banglaFp = fopen(bangla_file, "w+");
	engFp = fopen(english_file, "w+");
	
	printf("Enter 10 Roll numbers and Numbers for Math:\n");
	for(int i=1; i<=10; i++)
	{
		scanf("%d%d", &roll, &number);
		fprintf(mathFp, "%d %d\n", roll, number);
	}
	
	printf("Enter 10 Roll numbers and Numbers for Bangla:\n");
	for(int i=1; i<=10; i++)
	{
		scanf("%d%d", &roll, &number);
		fprintf(banglaFp, "%d %d\n", roll, number);
	}
	
	printf("Enter 10 Roll numbers and Numbers for English:\n");
	for(int i=1; i<=10; i++)
	{
		scanf("%d%d", &roll, &number);
		fprintf(engFp, "%d %d\n", roll, number);
	}
	
	fclose(mathFp);
	fclose(banglaFp);
	fclose(engFp);
}
int existPosition(int rolls[], int length, int roll)
{
	for(int i=0; i<length; i++)if(rolls[i]==roll) return i;
	return -1;
}
void makeAverage(char math[], char bangla[], char english[], char average[], int total)
{
	int roll, number, rolls[10];
	mathFp = fopen(math, "r");
	banglaFp = fopen(bangla, "r");
	engFp = fopen(english, "r");
	avgFp = fopen(average, "w");
	
	for(int i=0; i<total; i++)
	{
		fscanf(mathFp, "%d %d", &roll, &number);
		rolls[i] = rolls_and_averages[i][0] = roll;
		rolls_and_averages[i][1] = number;
	}
	
	for(int i=0; i<total; i++)
	{
		fscanf(banglaFp, "%d %d", &roll, &number);
		rolls_and_averages[existPosition(rolls, 10, roll)][1] += number;
		
		fscanf(engFp, "%d %d", &roll, &number);
		rolls_and_averages[existPosition(rolls, 10, roll)][1] += number;
		
	}
	
	for(int i=0; i<total; i++)
	{
		fprintf(avgFp, "%d ------>> %.2lf\n", rolls_and_averages[i][0], (rolls_and_averages[i][1] = (rolls_and_averages[i][1]*1.0)/3)*1.0);
	}
	
	fclose(mathFp);
	fclose(banglaFp);
	fclose(engFp);
	fclose(avgFp);
}
	
int main()
{
	char ans;
	char math_file[100], eng_file[100], bang_file[100], average_file[100];
	
	
	printf("Enter the name of math file: ");
	scanf("%s", math_file);
	printf("Enter the name of bangla file: ");
	scanf("%s", bang_file);
	printf("Enter the name of english file: ");
	scanf("%s", eng_file);
	
	getchar();
	printf("Do you want to initialize?(y/n):: ");
	scanf("%c", &ans);
	
	if(ans=='y') initialize(math_file, bang_file, eng_file);
	
	printf("Enter the file name where you want to keep all the averages:: ");
	scanf("%s", average_file);
	//avgFp = fopen(average_file, "w");
	makeAverage(math_file, bang_file, eng_file, average_file, TOTAL);
	
	printf("Showing Averages: \n");
	for(int i=0; i<10; i++) printf("%d -----------> %0.2lf\n", rolls_and_averages[i][0], rolls_and_averages[i][1]*1.0);
	
	return 0;
}
