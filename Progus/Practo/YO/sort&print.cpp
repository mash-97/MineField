#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Student
{
	char name[11];
	int roll;
	int marks;
	bool operator<(Student b)
	{
		return marks > b.marks;
	}
	bool operator>(Student b)
	{
		return marks < b.marks;
	}
	bool operator==(Student b)
	{
		return roll > b.roll;
	}
		
} Student;

bool compare(Student a, Student b)
{
	if(a.marks == b.marks) return (a.roll < b.roll);
	return (a.marks > b.marks);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, i;
	scanf("%d", &n);
	
	Student students[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &students[i].roll);
		//scanf(" %s", students[i].name);
		cin.getline(students[i].name, 11);
		scanf("%d", &students[i].marks);
	}
	
	sort(students, students+n);
	
	printf("Roll | Name       | Marks\n");
	printf("-------------------------\n");
	printf("Roll | Name       | Marks\n");

	for(i=0; i<n; i++)
		printf(" %3d | %-10s | %-3d\n", students[i].roll, students[i].name, students[i].marks);

	return 0;
}
