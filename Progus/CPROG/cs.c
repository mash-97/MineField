#include <stdio.h>

#include <string.h>
#include <strings.h>
#define t_p 11

#define swapper(a,b) {int c; c=a; a=b; b=c;}
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h> 

void ccrSetTextOutputTabSize(int n)
{
	
}

void ccrClearTextOutput()
{

}
void ccrSetTextOutputFontSize(int n)
{
	
}
int desire_int(int limit)
{
	int d;
	ccrSetTextOutputTabSize(4);
	printf("\n::");
	scanf("%d", &d);
	if(d<=limit)
	{
		return d;
	}
	else if(d<0||d>limit)
	{
		ccrClearTextOutput();
		ccrSetTextOutputTabSize(4);
		ccrSetTextOutputFontSize(17);
		printf("\n\t\tSorry! Out of required Data!");
		return 0;
	}
}






void query_1(){
	ccrClearTextOutput();
	ccrSetTextOutputFontSize(20);
	ccrSetTextOutputTabSize(4);
	printf("\n\n\n\t\t\t1. New\n\t\t\t2. History\n\t\t\t3. Exit\n");
}

							
void welcome(){
	ccrSetTextOutputFontSize(30);
	printf("\n\n\n\n\n    Welcome! To the CS!\n");
	
}
void help(){
	ccrClearTextOutput();
	ccrSetTextOutputTabSize(2);
	ccrSetTextOutputFontSize(20);
	printf("\t\t1 Run          -->     1/o/O\n");
	printf("\t\t2 Runs         -->     2/t/T\n");
	printf("\t\t3 Runs         -->     3/th/Th\n");
	printf("\t\t4 Runs         -->     4/f/F\n");
	printf("\t\t6 Runs         -->     6/s/S\n");
	printf("\t\tNo             -->     n\n");
	printf("\t\tWide           -->     w\n");
	printf("\t\tBye            -->     b\n");
	printf("\t\tOver           -->     Ov\n");
	printf("\t\tShow Scoreboard-->     SS/ss\n");
	
	printf("\t\tHelp           -->     h\n");
	
	printf("--------------------------------------\n");
	printf("--------------------------------------\n");
}


int seque_search(char players[11][20], char *name, bool out_or_not[11]){
	for(int i=0;i<11;i++)
	{
		if(strcmp(players[i], name)==0&&out_or_not[i]==0)
		{
			return i+1;
		}
	}
	return 0;
}


void scoreboard(char players_name[11][20], int players_individual_run[11], int extra_run, int total_run, int over , int total_wicket, char teams_name[20], bool out_or_not[11]){
	
	printf("%s: %d/%d\nOVER: %d\n", teams_name, total_run, total_wicket, over);
	printf("Name\t\t\tRun\n");
	for(int i=0;i<11;i++)
	{
		if(out_or_not[i]==1)
		{
			printf("%d.%s\t::out::\t%d\n", i+1, players_name[i], players_individual_run[i]);
		}
		else if(out_or_not[i]==0)
		{
			printf("%d.%s\t\t\t%d\n",  i+1, players_name[i], players_individual_run[i]);
		}
	}
	printf("Extras : %d\n", extra_run);
}

int main(){
	bool out_or_not_A[11];
	for(int z=0;z<11; z++)
	{
		out_or_not_A[z]=0;
	}
	bool out_or_not_B[11];
	for(int z=0;z<11; z++)
	{
		out_or_not_B[z]=0;
	}
	
	
	
	unsigned int q1, over, extra=0, bye;
	char name_of_the_match[20];
	char nameOfTeamA[20], players_name_team_A[t_p][20];
	int total_run_of_A=0, players_run_A[11];
	char nameOfTeamB[20], players_name_team_B[t_p][20];
	int total_run_of_B=0, players_run_B[11];
	char toss_winner;
	char b_1[10], b_2[10];
	int seque_1, seque_2;
	char instruction[4];
	int over_counter=0, out_counter=0, x, y, i;
	char striker[20];
	bool A=0, B=0, bla=0, bla_a=0;
	welcome();
	getchar();
	a:
	query_1();      //1.New, 2.History, 3.Exit
	q1=desire_int(3);
	switch(q1)
	{
		case 1:
			ccrClearTextOutput();
			ccrSetTextOutputFontSize(20);
			ccrSetTextOutputTabSize(4);
//-----Name-of-the-match-team-A-team-B------//	
			gets(name_of_the_match);
			printf("\t\tName of the Match : ");
			gets(name_of_the_match);
		
			printf("\n\t\tName of Team A : ");
			gets(nameOfTeamA);
		
			printf("\n\t\tName of Team B : ");
			gets(nameOfTeamB);
		
			printf("\n\t\tTotal Over : ");
			scanf("%d", &over);
//----------Players-Names-Inputing----------//
			ccrClearTextOutput();
			printf("Name of Players in %s", nameOfTeamA);
			getchar();
			for(int i=0;i<11;i++)
			{
				printf("\n\t\t%d. ", i+1);
				gets(players_name_team_A[i]);
			}
			ccrClearTextOutput();
			printf("Name of Players in %s", nameOfTeamB);
			getchar();
			for(int i=0;i<11;i++)
			{
				printf("\n\t\t%d. ", i+1);
				gets(players_name_team_B[i]);
			}
//------------Who-will-bat-first------------//
			bla_bla:
			ccrClearTextOutput();
			
			if(bla==0)
			{
				give_toss_winner:
				printf("\t\tWho will bat first? (A/B)(%s/%s): ", nameOfTeamA, nameOfTeamB);
			    scanf("%c", &toss_winner);
			    if(toss_winner==10)
			    {
			    	goto give_toss_winner;
			    }
			    bla=1;
			}
			else if(bla==1)
			{
				bla_a=1;
				if(A==1)
				{
					toss_winner='B';
				}
				else if(B=1)
				{
					toss_winner='A';
				}
			}
			ccrClearTextOutput();gets(b_1);
//AAAAAAAAAAAAAA     AAAAAAAAAAAAA   AAAAAAAAAAAAA//
			if(toss_winner=='A'&&A==0)
			{
				A=1;
				n_f:
				printf("\nName of first player : ");
					gets(b_1);
					seque_1=seque_search(players_name_team_A, b_1, out_or_not_A);
				if(seque_1==0)
				{
					goto n_f;
				}
				n_s:
					printf("\nName of second player : ");
					gets(b_2);
					seque_2=seque_search(players_name_team_A, b_2, out_or_not_A);
				if(seque_2==0)
				{
					goto n_s;
				}
				printf("%d->%s\n%d->%s\n", seque_1, b_1, seque_2, b_2);
				x=seque_1-1;
				y=seque_2-1;
				getchar();
				help();
				
				printf("\n\n\t\tStart!\n");
				getchar();
				while(over_counter<=over&&out_counter<=10)
				{
					m:
					printf("\n%s(%d) :: ", players_name_team_A[x], players_run_A[x]);
					gets(instruction);
					if(strcmp(instruction, "1")==0||strcmp(instruction, "one")==0||strcmp(instruction, "o")==0||strcmp(instruction, "O")==0)
					{
						
						players_run_A[x]+=1;
						swapper(x, y);
						total_run_of_A+=1;
						goto m;
						
					}
					else if(strcmp(instruction, "2")==0||strcmp(instruction, "two")==0||strcmp(instruction, "T")==0||strcmp(instruction, "t")==0)
					{
						players_run_A[x]+=2;
						total_run_of_A+=2;
						goto m;
					}
					else if(strcmp(instruction, "3")==0||strcmp(instruction, "th")==0||strcmp(instruction, "TH")==0||strcmp(instruction, "three")==0)
					{
						players_run_A[x]+=3;
						swapper(x, y);
						total_run_of_A+=3;
						goto m;
					}
					else if(strcmp(instruction, "4")==0||strcmp(instruction, "f")==0||strcmp(instruction, "four")==0||strcmp(instruction, "F")==0||strcmp(instruction, "FOUR")==0)
					{
						 players_run_A[x]+=4;
						 total_run_of_A+=4;
						 goto m;
					}
					else if(strcmp(instruction, "6")==0||strcmp(instruction, "six")==0||strcmp(instruction, "SIX")==0||strcmp(instruction, "s")==0||strcmp(instruction, "S")==0)
					{
						players_run_A[x]+=6;
						total_run_of_A+=6;
						goto m;
					}
					else if(strcmp(instruction, "w")==0||strcmp(instruction, "wide")==0||strcmp(instruction, "WIDE")==0||strcmp(instruction, "W")==0||strcmp(instruction, "n")==0||strcmp(instruction, "N")==0||strcmp(instruction, "no")==0||strcmp(instruction, "NO")==0)
					{
						total_run_of_A+=1;
						extra+=1;
						goto m;
					}
					else if(strcmp(instruction, "ov")==0||strcmp(instruction, "over")==0||strcmp(instruction, "OVER")==0||strcmp(instruction, "OV")==0)
					{
						over_counter+=1;
						swapper(x, y);
						goto m;
					}
					else if(strcmp(instruction, "out")==0||strcmp(instruction, "OUT")==0)
					{
						out_counter+=1;
						out_or_not_A[x]=1;
						next_batsman:
						printf("\n\t\tNext Batsman:: ");
						gets(b_1);
						seque_1=seque_search(players_name_team_A, b_1, out_or_not_A);
						if(seque_1==0)
						{
							goto next_batsman;
						}
						x=seque_1-1;
						goto m;
						
					}
					else if(strcmp(instruction, "b")==0||strcmp(instruction, "bye")==0||strcmp(instruction, "B")==0||strcmp(instruction, "BYE")==0||strcmp(instruction, "by")==0||strcmp(instruction, "BY")==0)
					{
						printf("\n\t\tHow much:: ");
						scanf("%d", &bye);
						total_run_of_A+=bye;
						extra+=bye;
						goto m;
					}
					else if(strcmp(instruction, "help")==0||strcmp(instruction, "HELP")==0||strcmp(instruction, "h")==0||strcmp(instruction, "H")==0)
					{
						help();
						goto m;
					}
					else if(strcmp(instruction, "SS")==0||strcmp(instruction, "ss")==0||strcmp(instruction, "show scoreboard")==0)
					{
						ccrClearTextOutput();
						ccrSetTextOutputFontSize(18);
						ccrSetTextOutputTabSize(4);
						scoreboard(players_name_team_A, players_run_A, extra, total_run_of_A, over_counter, out_counter, nameOfTeamA, out_or_not_A);
						goto m;
					}
					else if(strcmp(instruction, "end")==0)
					{
						if(bla_a==0)
						{
							bla_a=1;
							goto bla_bla;
							
						}
						else if(bla_a==1)
						{
							if(total_run_of_A>total_run_of_B)
							{
								ccrClearTextOutput();
								ccrSetTextOutputFontSize(20);
								ccrSetTextOutputTabSize(4);
								scoreboard(players_name_team_A, players_run_A, extra, total_run_of_A, over_counter, out_counter, nameOfTeamA, out_or_not_A);
printf("#########################################\n");
								scoreboard(players_name_team_B, players_run_B, extra, total_run_of_B, over_counter, out_counter, nameOfTeamB, out_or_not_B);
								printf("Winner : %s\n", nameOfTeamA);
							}
							else if(total_run_of_B>total_run_of_A)
							{
								ccrClearTextOutput();
								ccrSetTextOutputFontSize(20);
								ccrSetTextOutputTabSize(4);
								scoreboard(players_name_team_A, players_run_A, extra, total_run_of_A, over_counter, out_counter, nameOfTeamA, out_or_not_A);
printf("#########################################\n");
								scoreboard(players_name_team_B, players_run_B, extra, total_run_of_B, over_counter, out_counter, nameOfTeamB, out_or_not_B);
								printf("Winner : %s\n", nameOfTeamB);
							}
							else if(total_run_of_A==total_run_of_B)
							{
								ccrClearTextOutput();
								ccrSetTextOutputFontSize(20);
								ccrSetTextOutputTabSize(4);
								scoreboard(players_name_team_A, players_run_A, extra, total_run_of_A, over_counter, out_counter, nameOfTeamA, out_or_not_A);
printf("#########################################\n");
								scoreboard(players_name_team_B, players_run_B, extra, total_run_of_B, over_counter, out_counter, nameOfTeamB, out_or_not_B);
								printf("Winner : %s & %s::Match Draw\n", nameOfTeamA, nameOfTeamB);
							}
							break;
						}
					}
					else
					{
						printf("\n\t\tSorry Out of instruction set. For help enter\"h\"\n");
						goto m;
					}
				}
			}			
//BBBBBBBBBB  BBBB     BBBBBBBB    BBBBBBBBB//			
			if(toss_winner=='B'&&B==0)
			{
				B=1;
				n_ff:
				printf("\nName of first player : ");
					gets(b_1);
					seque_1=seque_search(players_name_team_B, b_1, out_or_not_B);
				if(seque_1==0)
				{
					goto n_ff;
				}
				n_ss:
					printf("\nName of second player : ");
					gets(b_2);
					seque_2=seque_search(players_name_team_B, b_2, out_or_not_B);
				if(seque_2==0)
				{
					goto n_ss;
				}
				printf("%d->%s\n%d->%s\n", seque_1, b_1, seque_2, b_2);
				x=seque_1-1;
				y=seque_2-1;
				getchar();
				help();
				
				printf("\n\n\t\tStart!\n");
				getchar();
				while(over_counter<=over&&out_counter<=10)
				{
					n:
					printf("\n%s(%d) :: ", players_name_team_B[x], players_run_B[x]);
					gets(instruction);
					if(strcmp(instruction, "1")==0||strcmp(instruction, "one")==0||strcmp(instruction, "o")==0||strcmp(instruction, "O")==0)
					{
						
						players_run_B[x]+=1;
						swapper(x, y);
						total_run_of_B+=1;
						goto n;
						
					}
					else if(strcmp(instruction, "2")==0||strcmp(instruction, "two")==0||strcmp(instruction, "T")==0||strcmp(instruction, "t")==0)
					{
						players_run_B[x]+=2;
						total_run_of_B+=2;
						goto n;
					}
					else if(strcmp(instruction, "3")==0||strcmp(instruction, "th")==0||strcmp(instruction, "TH")==0||strcmp(instruction, "three")==0)
					{
						players_run_B[x]+=3;
						swapper(x, y);
						total_run_of_B+=3;
						goto n;
					}
					else if(strcmp(instruction, "4")==0||strcmp(instruction, "f")==0||strcmp(instruction, "four")==0||strcmp(instruction, "F")==0||strcmp(instruction, "FOUR")==0)
					{
						 players_run_B[x]+=4;
						 total_run_of_B+=4;
						 goto n;
					}
					else if(strcmp(instruction, "6")==0||strcmp(instruction, "six")==0||strcmp(instruction, "SIX")==0||strcmp(instruction, "s")==0||strcmp(instruction, "S")==0)
					{
						players_run_B[x]+=6;
						total_run_of_B+=6;
						goto n;
					}
					else if(strcmp(instruction, "w")==0||strcmp(instruction, "wide")==0||strcmp(instruction, "WIDE")==0||strcmp(instruction, "W")==0||strcmp(instruction, "n")==0||strcmp(instruction, "N")==0||strcmp(instruction, "no")==0||strcmp(instruction, "NO")==0)
					{
						total_run_of_B+=1;
						extra+=1;
						goto n;
					}
					else if(strcmp(instruction, "ov")==0||strcmp(instruction, "over")==0||strcmp(instruction, "OVER")==0||strcmp(instruction, "OV")==0)
					{
						over_counter+=1;
						swapper(x, y);
						goto m;
					}
					else if(strcmp(instruction, "out")==0||strcmp(instruction, "OUT")==0)
					{
						out_counter+=1;
						out_or_not_B[x]=1;
						next_batsmanB:
						printf("\n\t\tNext Batsman:: ");
						gets(b_1);
						seque_1=seque_search(players_name_team_B, b_1, out_or_not_B);
						if(seque_1==0)
						{
							goto next_batsmanB;
						}
						x=seque_1-1;
						goto n;
						
					}
					else if(strcmp(instruction, "b")==0||strcmp(instruction, "bye")==0||strcmp(instruction, "B")==0||strcmp(instruction, "BYE")==0||strcmp(instruction, "by")==0||strcmp(instruction, "BY")==0)
					{
						printf("\n\t\tHow much:: ");
						scanf("%d", &bye);
						total_run_of_B+=bye;
						extra+=bye;
						goto n;
					}
					else if(strcmp(instruction, "help")==0||strcmp(instruction, "HELP")==0||strcmp(instruction, "h")==0||strcmp(instruction, "H")==0)
					{
						help();
						goto n;
					}
					else if(strcmp(instruction, "SS")==0||strcmp(instruction, "ss")==0||strcmp(instruction, "show scoreboard")==0)
					{
						ccrClearTextOutput();
						ccrSetTextOutputFontSize(18);
						ccrSetTextOutputTabSize(4);
						scoreboard(players_name_team_B, players_run_B, extra, total_run_of_B, over_counter, out_counter, nameOfTeamB, out_or_not_B);
						goto n;
					}
					else if(strcmp(instruction, "end")==0)
					{
						if(bla_a==0)
						{
							bla_a=1;
							goto bla_bla;
						}
						else if(bla_a==1)
						{
							if(total_run_of_A>total_run_of_B)
							{
								ccrClearTextOutput();
								ccrSetTextOutputFontSize(20);
								ccrSetTextOutputTabSize(4);
								scoreboard(players_name_team_A, players_run_A, extra, total_run_of_A, over_counter, out_counter, nameOfTeamA, out_or_not_A);
printf("#########################################\n");
								scoreboard(players_name_team_B, players_run_B, extra, total_run_of_B, over_counter, out_counter, nameOfTeamB, out_or_not_B);
								printf("Winner : %s\n", nameOfTeamA);
							}
							else if(total_run_of_B>total_run_of_A)
							{
								ccrClearTextOutput();
								ccrSetTextOutputFontSize(20);
								ccrSetTextOutputTabSize(4);
								scoreboard(players_name_team_A, players_run_A, extra, total_run_of_A, over_counter, out_counter, nameOfTeamA, out_or_not_A);
printf("#########################################\n");
								scoreboard(players_name_team_B, players_run_B, extra, total_run_of_B, over_counter, out_counter, nameOfTeamB, out_or_not_B);
								printf("Winner : %s\n", nameOfTeamB);
							}
							else if(total_run_of_A==total_run_of_B)
							{
								ccrClearTextOutput();
								ccrSetTextOutputFontSize(20);
								ccrSetTextOutputTabSize(4);
								scoreboard(players_name_team_A, players_run_A, extra, total_run_of_A, over_counter, out_counter, nameOfTeamA, out_or_not_A);
printf("#########################################\n");
								scoreboard(players_name_team_B, players_run_B, extra, total_run_of_B, over_counter, out_counter, nameOfTeamB, out_or_not_B);
								printf("Winner : %s & %s::Match Draw\n", nameOfTeamA, nameOfTeamB);
							}
							break;
						}
					}
					else
					{
						printf("\n\t\tSorry Out of instruction set. For help enter\"h\"\n");
						goto n;
					}
				}
			}			
		break;
		
		case 2:
		
		break;
		
		case 3:
			return 0;
		break;
		
		default:
			
				printf("Please try again\n");
			
			
			goto a;
		break;
		
	}
	
	
	return 0;
}
	

