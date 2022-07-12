#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define MAX_PAGES 100


void clear()
{
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		system("clear");
	#endif
	
	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}

typedef struct
{
	int top;
	void (*pages[MAX_PAGES])(void);
} Page;


void homePage(void)
{
	clear();
	printf("              Home            \n");
	printf("This is home page.\n");
}

void profilePage(void)
{
	clear();
	printf("              Profile          \n");
	printf("My profile\n");
}

void settingsPage(void)
{
	clear();
	printf("              Settings          \n");
	printf("This about settings\n");
}

void aboutPage(void)
{
	clear();
	printf("                About            \n");
	printf("This about about\n");
}

void push(Page * page_struct, void (*page) (void))
{
	if(page_struct->top < MAX_PAGES) page_struct->pages[page_struct->top++] = *page; // as function name is function's address.
	else printf("Stack is full!\n");
}

void * pop(Page *page_struct)
{
	void (*function_pointer)(void);
	if(page_struct->top==0)
	{
		printf("Stack is empty!\n");
		return NULL;
	}
	else
	{
		function_pointer = page_struct->pages[--page_struct->top];
	}
	
	return function_pointer;
}

int main()
{
	Page back, forth;
	void (*current_page)(void);
	void (*before_page) (void);
	back.top = 0, forth.top = 0;
	
	int commando;
	surf:
	puts("");
	printf("1. Home Page\n");
	printf("2. Profile Page\n");
	printf("3. Settings Page\n");
	printf("4. About Page\n");
	printf("5. Back\n");
	printf("6. Forth\n");
	printf(":: ");
	scanf("%d", &commando);
	switch(commando)
	{
		case 1: 
			homePage();
			current_page = &homePage;
			push(&back, current_page);
			goto surf;
		break;
		case 2:
			profilePage();
			current_page = &profilePage;
			push(&back, current_page);
			goto surf;
		break;
		case 3:
			settingsPage();
			current_page = &settingsPage;
			push(&back, current_page);
			goto surf;
		break;
		case 4:
			aboutPage();
			current_page = &aboutPage;
			push(&back, current_page);
			goto surf;
		break;
		case 5: //                 <<<<<<<<<<<<<<<<<
			printf("back\n");
			current_page = pop(&back);
			if(current_page==NULL) printf("Page not found!\n");
			else 
			{
				//printf("crush!\n");
				clear();
				push(&forth, current_page);
				before_page = pop(&back);
				if(before_page==NULL) printf("Page not found!\n");
				else
				{
					before_page();
					push(&back, before_page);
				}
			}
			goto surf;
		break;
		case 6: //                 >>>>>>>>>>>>>>>>>>>
			printf("forth\n");
			current_page = pop(&forth);
			if(current_page==NULL) printf("Page not found!\n\n");
			else
			{
				current_page();
				push(&back, current_page);
			}
			goto surf;
		break;
		default:
			goto surf;
		break;
	}
	return 0;
}
			
/*
((())(()))
]{{()}}}{}{[][
*/
