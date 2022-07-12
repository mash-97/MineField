#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t
{
	string name;
	int years;
	movies_t * next;
};

void print_movie(movies_t *movie)
{
	movies_t * i = movie;
	while(i!=NULL)
	{
		cout << "Name of the movie: "<< movie->name << endl;
		cout << "Publication Year : "<< movie->years<< endl;
		i = i->next;
	}
	cout<<endl;
}

int main()
{
	string s;
	movies_t *one = new movies_t;
	movies_t *head = one;
	movies_t *buf;
	for(int i=1;; i++)
	{
		
		cout << i << ". Enter name of the movie: ";
		getchar();
		getline(cin, one->name);

		cout << "Enter year of publication: ";
		cin >> one->years;
		buf = one;
		if(i<3) 
		{
			one = new movies_t;
			buf->next = one;
		}
		else
		{
			buf->next = NULL;
			break;
		}
	}

	cout << "Printing movies:\n";
	print_movie(head);
	return 0;
}
