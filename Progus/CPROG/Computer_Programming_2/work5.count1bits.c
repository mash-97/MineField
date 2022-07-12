#include <stdio.h>
#include <string.h>

char bits_string[50];
int oneZeroes[2];

int deciToB(int dec_n)
{
	int bits_count = 0;
	int d_n = dec_n;
	int rem;
	
	if(dec_n <= 0){bits_string[0] = 48; return 1;}
	while(d_n > 0)
	{
		 rem = d_n%2;
		 d_n /= 2;
		 bits_string[bits_count++] = 48+rem;
	}
	
	return bits_count;
}

int count1s(char string[])
{
	int count = 0;
	oneZeroes[0] = 0;
	oneZeroes[1] = 0;
	int length = strlen(string);
	
	for(int i=0; i<length; i++)
	{
		 if(string[i]==49){
			 ++count;
			 ++oneZeroes[1];
		 }
		 else ++oneZeroes[0];
	}
	
	return count;
}

int main()
{
	int number, total_ones;
	scanf("%d", &number);
	
	int length = deciToB(number);
	printf("The binary is : ");
	for(int i=length-1; i>0; i--)printf("%c", bits_string[i]);
	printf("%c\n", bits_string[0]);
	total_ones = count1s(bits_string);
	printf("Total 1 is: %d and Total zero is: %d\n", total_ones, oneZeroes[0]);
	printf("\n\n%d : %d\n\n", oneZeroes[0], oneZeroes[1]);
	
	main();
	return 0;
}
