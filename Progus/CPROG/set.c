#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
	return a<=b ? a : b;
}

int max(int a, int b)
{
	return a>=b ? a : b;
}

void display(int length, int *array)
{
	printf("{ ");
	for(int i=0; i<length-1; i++)
		printf("%d, ", array[i]);
	if(length!=0)
		printf("%d }\n", array[length-1]);
	else
		printf("}\n");
}

void displayArray(int length, int *array)
{
	for(int i=0; i<length; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int copy(int length, int *source, int **dest)
{
	free(*dest);
	*dest = (int *)malloc(sizeof(int)*length);
	if(*dest==NULL)
	{
		return 0;
	}

	for(int i=0; i<length; i++)
		*((*dest)+i) = source[i];
		
	return length;
}

int in(int fl, int *f, int sl, int *s, int **dest)
{
	free(*dest);
	*dest = (int*) malloc(sizeof(int)*(min(fl, sl)));
	int length = 0;
	for(int i=0; i<fl; i++)
		for(int j=0; j<sl; j++)
			if(f[i]==s[j])
			{
				*(*dest+(length++)) = (f[i]|s[j]);
				break;
			}
	return length; 
}

int un(int fl, int *f, int sl, int *s, int **dest)
{
	free(*dest);
	int length = 0;
	*dest = (int *)malloc(sizeof(int)*(fl+sl));
	for(int i=0; i<fl; i++)
		*(*dest+(length++)) = f[i];
	
	for(int i=0; i<sl; i++)
	{
		int flag = 1;
		for(int j=0; j<length; j++)
			if(s[i]==*(*dest+j))
			{
				flag = 0; 
				break;
			}
		
		if(flag)
			*(*dest+(length++)) = s[i];
	}
	return length; 
}

int main()
{
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	
	int Al;
	printf("Size of set A: ");
	scanf("%d", &Al);
	printf("%d\n", Al);
	int A[Al];
	printf("Elements of set A: ");
	for(int i=0; i<Al; i++)
		scanf("%d", &A[i]);
	displayArray(Al, A);
	
	printf("\n");
	int Bl;
	printf("Size of set B: ");
	scanf("%d", &Bl);
	printf("%d\n", Bl);
	int B[Bl];
	printf("Elements of set B: ");
	for(int i=0; i<Bl; i++)
		scanf("%d", &B[i]);
	displayArray(Bl, B);
	
	printf("\n");
	int Cl;
	printf("Size of set C: ");
	scanf("%d", &Cl);
	printf("%d\n", Cl);
	int C[Cl];	
	printf("Elements of set C: ");
	for(int i=0; i<Cl; i++)
		scanf("%d", &C[i]);
	displayArray(Cl, C);
	
	printf("\n");
	printf("\n");
	printf("For Associative Laws of Sets: \n");
	printf("A n (B n C): ");
	int *res = NULL;
	int res_length = in(Bl, B, Cl, C, &res);						// B n C
	
	int * temp = NULL;
	int temp_length = copy(res_length, res, &temp);				// temp stores the BnC
	
	res_length = in(Al, A, temp_length, temp, &res);				// A n (B n C)
	
	int *An_BnC = NULL;
	int An_BnCl = copy(res_length, res, &An_BnC);				// storing A n (B n C) into An_BnCl
	if(An_BnCl==0)
		printf("{ }\n");
	else
		display(An_BnCl, An_BnC);
	
	printf("(A n B) n C: ");
	res_length = in(Al, A, Bl, B, &res);
	
	temp_length = copy(res_length, res, &temp);					// temp stores the AnB
	res_length = in(temp_length, temp, Cl, C, &res);					// (A n B) n C
	
	int *AnBn_C = NULL;
	int AnBn_Cl = copy(res_length, res, &AnBn_C);				// storing (A n B) n C into AnBn_Cl
	if(AnBn_Cl==0)
		printf("{ }\n");
	else
		display(AnBn_Cl, AnBn_C);
	
	return 0;
}
