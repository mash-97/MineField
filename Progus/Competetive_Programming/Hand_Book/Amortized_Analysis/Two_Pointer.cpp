#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <time.h>
#include <tuple>

using namespace std;

pair<int,int> sum2(int x, int n, vector<int>v);
pair<int,int> sum21(int x, int n, vector<int>v);


pair<int,int> sum22(int x, int n, vector<int>v)
{
	for(int i=0; i<n; i++)
	{
		int a = v[i];
		int k = 0;
		for(int j=(n+i)/2; j>=1; j/=2)
			while(k+j<n && a+v[k+j]<=x) k+=j;
		if(a+v[k]==x) return {a,v[k]};
	}
	return {false,false};
}
deque<int> subarraySum(int x, vector<int>v)
{
	deque<int> subarray;
	int sum = 0;
	if(v.size()<=1)
	{
		if(v.size()==1 && v[0]==x) subarray.push_back(v[0]);
		return subarray;
	}
	
	auto left = v.begin();
	subarray.push_back(*left);
	sum += *left;
	
	auto right = left;
	
	while(left<v.end() && right<v.end())
	{
		if(sum==x) return subarray;
		while(right<v.end() && sum+*(right+1)<x)
		{
			right++;
			if(right<v.end())
			{
				sum += *right;
				subarray.push_back(*right);
			}
			if(sum==x) return subarray;
		}
		if(sum==x) return subarray;
		if(subarray.size()>0) subarray.pop_front();
		sum-=*left;
		left++;
		
	}
	
	return subarray;
}

vector<int> sum3(int x,  int n, vector<int>v)
{
	vector<int> r;
	for(int i=0; i<n; i++)
	{
		r.push_back(v[i]);
		pair<int,int> p = sum22(x-v[i], n, v);
		if(p.first!=false && p.second!=false)
		{
			r.push_back(p.first);
			r.push_back(p.second);
			return r;
		}
		r.pop_back();
	}
	return r;
}

int anotherTry(int x, int n, vector<int>v)
{
	auto l = v.begin();
	auto r = l+1;
	int sum = *l;
	while(l!=v.end() && r!=v.end())
	{
		while(sum+*r<x && r<v.end()) {sum+=*r;r++;}
		if(sum==x) 
		{
			while(l<=r) {printf("%d ", *l); l++;}
			puts("");
			return true;
		}
		sum -= *l;
		l++;
	}
	return false;
}
		
int main()
{
	auto t = make_tuple(1,2,"dkjf");
	int size = tuple_size<decltype(t)>::value;
	printf("Tuple size: %d\n", size);
	cout<<get<0>(t)<<get<1>(t)<<get<2>(t)<<endl;
	
	int n, x;
	cin >> n;
	vector<int> v(n, 0);
	
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		v[i] = a;
	}
	
	while(~scanf("%d", &x))
	{
		auto r = anotherTry(x, n, v);
		if(r==false) printf("No subarray Matched!!\n");
	}
	
	//~ pair<int,int>pairs[n*n+5];
	//~ int index = 0;
	//~ for(int i=0; i<n; i++)
		//~ for(int j=0; j<n; j++) 
			//~ pairs[index++] = {v[i], v[j]};
	//~ for(int i=1; i<5; i++) pairs[index++] = {rand()%101, rand()%101};
	
	//~ for(int i=0; i<n*n+5; i++)
	//~ {
		//~ x =  pairs[i].first+pairs[i].second;
		//~ printf("%d: \n", x);
		//~ printf("pairs: %d, %d\n\n", pairs[i].first, pairs[i].second);
		//~ pair<int,int> p = sum2(x, n, v);
		//~ cout<<"sum2: "<<p.first<<" "<<p.second<<endl;
		//~ pair<int,int> p2 = sum21(x, n, v);
		//~ cout<<"sum21: "<<p2.first<<" "<<p2.second<<endl;
		//~ pair<int,int> p3 = sum22(x, n, v);
		//~ cout<<"sum22: "<<p3.first<<" "<<p3.second<<endl;
		//~ if(p.first!=false && p.second!=false) 
			//~ ((p.first+p3.second == x)&&(p2.first==p.first && p2.second==p.second && p3.first==p.first) ) ? 
				//~ cout<<"Correct!"<<endl : cout<<"Incorrect!"<<endl;
		//~ puts("");
	//~ }
	
	
	return 0;
}

pair<int,int> sum21(int x, int n, vector<int>v)
{
	auto l = v.begin();
	auto r = v.end();
	r--;
	while(l!=v.end() && r>=v.begin())
	{
		//printf("*l: %d, *r: %d\n", *l, *r);
		//if(l==r){r--;continue;}
		if(*l+*r==x) return {*l, *r};
		else if(*l+*r>x) r--;
		else if(*l+*r<x) l++;
	}
	return {false, false};
}

pair<int,int> sum2(int x, int n, vector<int>v)
{
	
	auto l = v.begin();
	auto r = v.end();
	r--;
	//while(l!=v.end() && r>=v.begin())
	while(l<=r)
	{
		//printf("*l: %d, *r: %d\n", *l, *r);
		//if(l==r){r--;continue;}
		if(*l+*r==x) return {*l, *r};
		else if(*l+*r>x) r--;
		else if(*l+*r<x) l++;
	}
	return {false, false};
}
