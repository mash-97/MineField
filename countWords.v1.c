// Chy Method to count all the words in a string.
// This approach is cool, Idea of Abir Chy.
// As I just implemented the idea.
// The credit goes to Abir Chy.

// This program works for just alphabets. You can think all the characters except alphabets are it's delimeters.

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

// Function to check if the character is alphabet or not.
int letterCheck(char c)
{
	return ((c>='A' && c<='Z') || (c>='a' && c<='z')) ? true : false;
}

int countWords(char *string)
{
	int string_length = strlen(string);
	
	int count_words = 0;
	
	for(int i=0; i<string_length-1; i++)
		if(letterCheck(string[i]) == true && letterCheck(string[i+1]) == false) ++count_words;	// I call it The Chy Logic...
	
	if(letterCheck(string[string_length-1]) == true) ++count_words;
	return count_words;
}

int main()
{
	char string[1000];
	
	printf("String: ");
	scanf(" %[^\n]", string);
	
	printf("Total words: %d\n", countWords(string));
	
	return 0;
}
