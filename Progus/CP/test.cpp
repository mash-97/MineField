#include <iostream>
#include <string>

using namespace std;

class Person
{
	public:
		string name;
		int age;
		
		void setName(string n)
		{
			name = n;
		}
		void setAge(int a)
		{
			age = a;
		}
		
};

int main()
{
	Person person1;
	
	cout << "Enter name: ";
	int a;
	string n;
	
	cin >> n;
	cout << "Enter age: ";
	cin >> a;
	
	person1.setName(n);
	person1.setAge(a);
	
	cout <<"Name: " << person1.name << endl;
	cout <<"Age: " << person1.age << endl;
	return 0;
}
