#include <bits/stdc++.h>
using namespace std;

template <class T>
class Ball
{
	public:
		T x,y;
		Ball(int a, int b)
		{
			x=a;
			y=b;
		}
		void up()
		{
			y++;
			disp();
		}
		void down()
		{
			y--;
			disp();
		}
		void right()
		{
			x++;
			disp();
		}
		void left()
		{
			x--;
			disp();
		}
	private:
		void disp()
		{
			cout << "X: "<< x<< " Y: "<< y<< endl;
		}
};

#define vpii vector<pair<int,int>>
#define V(type) vector<type>
#define VPP vector<pair<pair<int,int>, pair<int,int>>>
#define pb   push_back
#define mp	 make_pair
#define sq(a) (a)*(a)

int main(int aa, char *skdf[])
{
	map<int,int>a;
	
	printf("%d\n", ++a[1]);
	//~ regex email_pattern(R"(^[a-zA-Z0-9.+_-]+@[a-zA-Z0-9.]+\.[a-zA-Z0-9]+$)");
	//~ string valid_email("mashiur15-955@diu.edu.bd");
	//~ string invalid_email("this is not a email");
	
	//~ if(regex_match(valid_email, email_pattern))
		//~ cout<<"This is a valid email: "<<valid_email<<endl;
	//~ else 
		//~ cout<<"This is invalid email: "<<valid_email<<endl;
	
	//~ if(regex_match(invalid_email, email_pattern)) 
		//~ cout<<"This is a valid email: "<<invalid_email<<endl;
	//~ else
		//~ cout<<"This is invalid email: "<<invalid_email<<endl;
		
	return 0;
}
		
