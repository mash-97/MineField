#include <stdio.h>

// 0 => 1c
// 1 => 2c
// 2 => 3c

// 3 => 1t
// 4 => 2t
// 5 => 3t

// 6 => 1q
// 7 => 2q
// 8 => 3q

int Cardos[9];

int setType1(int tvs)
{
	//Set type one. same number and same figure.
	for(int i=0; i<9; i++) 
	{
		if(Cardos[i]>=3)
		{
			tvs += Cardos[i]/3;
			Cardos[i]%=3;
			//printf("1\n");
		}
	}
	return tvs;
}

int setType2(int tvs)
{
	//Set type two. different number but same figure
	for(int i=0; i<9; i+=3)
	if(Cardos[i]>0)
	{
		if(Cardos[i]==Cardos[i+1] && Cardos[i+1]==Cardos[i+2])
		{
			int conto;
			conto=(Cardos[i]+Cardos[i+1]+Cardos[i+2])/3;
			tvs+=conto;
			Cardos[i]-=conto; Cardos[i+1]-=conto; Cardos[i+2]-=conto;
			//printf("2.1\n");
		}
			
			
		else if(Cardos[i]>0 && Cardos[i+1]>0 && Cardos[i+2]>0)
		{
			++tvs;
			--Cardos[i]; --Cardos[i+1]; --Cardos[i+2];
			//printf("2.2\n");
		}
		
	}
	return tvs;
}

int setType3(int tvs)
{
	//Set type three. same number but different figure.
	for(int i=0; i<3; i++)
	if(Cardos[i]>0)
	{
		if(Cardos[i]==Cardos[i+3] && Cardos[i+3]==Cardos[i+6])
		{
			int conto = (Cardos[i]+Cardos[i+3]+Cardos[i+6])/3;
			tvs+=conto;
			Cardos[i]-=conto; Cardos[i+3]-=conto; Cardos[i+6]-=conto;
			//printf("3.1\n");
		}
			 
		else if(Cardos[i]>0 && Cardos[i+3]>0 && Cardos[i+6]>0)
		{
			++tvs;
			--Cardos[i]; --Cardos[i+3]; --Cardos[i+6];
			//printf("3.2\n");
		}
		
	}
	return tvs;
}

int setType4(int tvs)
{
	//Set type four. different number and different figure
	for(int i=0; i<3; i++)
	if(Cardos[i]>0)
	{
		for(int j=3; j<6; j++)
		if(j-3!=i && Cardos[j]>0)
		{
			for(int k=6; k<9; k++)
			if(k-3!=j && k-6!=i && Cardos[k]>0)
			{
				if(Cardos[i]==Cardos[j] && Cardos[j]==Cardos[k])
				{
					int conto = (Cardos[i]+Cardos[j]+Cardos[k])/3;
					tvs+=conto;
					Cardos[i]-=conto; Cardos[j]-=conto; Cardos[k]-=conto;
					//printf("4.1\n");
				}
				else if(Cardos[i]>0 && Cardos[j]>0 && Cardos[k]>0)
				{
					++tvs;
					--Cardos[i]; --Cardos[j]; --Cardos[k];
					//printf("4.2\n");
				}
				
			}
		}
	}
	return tvs;
}



int largestNumberOfSetFrom(int cards_array[9])
{
	int svt, tvs=0;
	int (*funct[4])(int);
	funct[0] = &setType1;
	funct[1] = &setType2;
	funct[2] = &setType3;
	funct[3] = &setType4;
	
	for(int i=0; i<4; i++)
	for(int j=0; j<4; j++)
	if(j!=i)
	for(int k=0; k<4; k++)
	if(k!=i && k!=j)
	for(int l=0; l<4; l++)
	if(l!=i && l!=k && l!=j)
	{
		for(int z=0; z<9; z++) Cardos[z]=cards_array[z]; 
		svt = funct[i](funct[j](funct[k](funct[l](0))));
		if(svt>tvs) tvs = svt;
	}
	return tvs;
}

int pos(int number, int figure)
{
	switch(figure)
	{
		case 0: 
			if(number==1) return 0;
			else if(number==2) return 1;
			else if(number==3) return 2;
		break;
		case 3:
			if(number==1) return 3;
			else if(number==2) return 4;
			else if(number==3) return 5;
		break;
		case 4:
			if(number==1) return 6;
			else if(number==2) return 7;
			else if(number==3) return 8;
		break;
		default:
			return -1;
		break;
	}
	return -1;
}

int main()
{
	int length;
	char string_1[15], string_2[15];
	int cards_array[9];
	int number;
	int figure;
	
	while(scanf("%d", &length) && length!=0)
	{
		for(int i=0; i<9; i++) cards_array[i]=0; 
		
		for(int i=0; i<length; i++)
		{
			scanf(" %s %s", string_1, string_2);
			
			if(string_1[0]=='u') number = 1;
			else if(string_1[0]=='d') number = 2;
			else if(string_1[0]=='t') number = 3;
			
			if(string_2[0]=='c') figure = 0;
			else if(string_2[0]=='t') figure = 3;
			else if(string_2[0]=='q') figure = 4;
			
			++cards_array[pos(number, figure)];
		}
		
		//puts("");
		printf("%d\n", largestNumberOfSetFrom(cards_array));
	}
	
	return 0;
}
