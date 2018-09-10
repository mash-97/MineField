// Chy Method to count all the words in a string.
// This approach is cool, Idea of Abir Chy.
// As I just implemented the idea.
// The credit goes to Abir Chy.

// This program works for delimeters.
// You specify the delimeters, words divided according to those delimeters.
// Though time complexity is a fact. It depends on delimeters length and string length quite hugely.
// It looks like generalized. But can be clarify.

#include <stdio.h>
#include <strings.h>

#define true 1
#define false 0

int delimeterCheck(char c, char *delimeters, int delimeters_length)
{
	for(int i=0; i<delimeters_length; i++)
		if(delimeters[i] == c) return true;
	
	return false;
}

int countWords(char *string, char *delimeters)
{
	int string_length = strlen(string);
	int delimeters_length = strlen(delimeters);
	
	int count_words = 0;
	int a, b;
	
	a = delimeterCheck(string[0], delimeters, delimeters_length);
	
	for(int i=1; i<string_length-1; i++)
	{
		b = delimeterCheck(string[i], delimeters, delimeters_length);
		
		// I call it The Chy Logic...
		// a==false means it is before character is alphabet and b==true means current character is one of the delimeter.
		if(a == false && b == true) ++count_words;		
		// It just checks is the before character is alphabet and current character is delimeters.
		// If the above condition is true then it's a word to count.				
		
		a = b;
	}
	
	if(delimeterCheck(string[string_length-1], delimeters, delimeters_length) == false) ++count_words;
	// above condition is for last word check.
	
	return count_words;
}

int main()
{
	char string[1000];
	
	printf("String: ");
	scanf(" %[^\n]", string);
	
	printf("Total words: %d\n", countWords(string, " ,./"));
	//main();
	return 0;
}

