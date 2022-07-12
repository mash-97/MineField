#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define INF 1111111111
void disp_v(vector<int>v)
{
	for(auto x: v) cout<<x<<" ";
	cout<<endl;
}

void disp_m(map <int, int> m, int x)
{
	//~ cout<<"Total: "<<m.size()<<endl;
	//~ for(auto i: m)
	//~ {
		//~ cout<<i.first<<": "<<i.second<<endl;
	//~ }
	if(m.size()==0) cout<<x<<endl;
}

map<int, int> hasSum3(vector<int>v, int n, int x)
{
	map<int,int> m;
	
	int total_coins = x;
	int lim = 1<<n;
	
	for(int i=0; i<lim; i++)
	{
		int money = x;
		map<int,int> a;
		int buf_coins = 0;
		int sum = 0;
		
		for(int j=0; j<n; j++)
		{
			//if(i&(1<<j)) cout<<v[j]<<" (";
			if((i&(1<<j)) && (money/v[j]))
			{
				//cout<<v[j]<<" :";
				buf_coins += a[v[j]] = money/v[j];
				money %= v[j];
				//cout<<money<<": ";
				sum += v[j]*a[v[j]];
			}
			//if(i&(1<<j)) cout<<")";
		}
		//cout<<endl;
		
		if(sum==x && buf_coins && buf_coins < total_coins)
		{
			total_coins = buf_coins;
			m = a;
		}
	}
	return m;
}

map<int, int> hasSum2(vector<int>v, int n, int x)
{
	map<int, int> r;
	int bf_total_coins = x;
	for(int i=n-1; i>=0; i--)
		if(x/v[i])
		{
			map<int, int> br;
			int sum = x;
			int ssum = 0;
			int total_coins = 0;
			for(int j=i; j>=0; j--)
				if(sum/v[j])
				{
					total_coins += br[v[j]] = sum/v[j];
					sum %= v[j];
					ssum += v[j]*br[v[j]];
				}
			if(ssum==x && bf_total_coins > total_coins) 
			{
				r = br;
				bf_total_coins = total_coins;
			}
		}
	return r;
}

map<int, int> hasSum(vector <int> v, int n, int x)
{
	map <int, int> r;
	int sum = 0;
	int xx = x;
	for(int i=0; i<n && x; i++)
	{
		if(x/v[i])
		{
			r[v[i]] = x/v[i];
			sum += v[i]*r[v[i]];
		}
		x %= v[i];
	}
	if(sum!=xx) r.clear();
	return r;
}

int mem[1000000];

int miniumCoins(vector<int> v, int k, int money)
{
	//~ static int st = 0;
	//~ st++;
	//~ system("clear");
	//~ printf("state: %d\n", st);
	
	if(money < 0) return INF;
	if(money == 0) return 0;
	
	if(mem[money]) return mem[money];
	int u = INF;
	for(int i=0; i<k; i++)
		u = min(u, miniumCoins(v, k, money-v[i])+1);
	
	mem[money] = u;
	return u;
}

int last_cons = 1;
int constructSolutions(vector<int> coins, int k, int x)
{
	mem[0] = 0;
	
	if(last_cons>x) return mem[x];
	for(int i=last_cons; i<=x; i++, last_cons++)
	{
		int u = INF;
		for(int j=0; j<k; j++)
		{
			if(i-coins[j]<0) continue;
			u = min(u, mem[i-coins[j]]+1);
		}
		mem[i] = u;
	}
	return mem[x];
}

void loopMinSum(vector<int>coins, int k, int x)
{
	int d[x+1];	
	d[0] = 0;
	int e[x+1];
	
	for(int i=1; i<=x; i++)
	{
		d[i] = INF;
		for(int j=0; j<k; j++)
		{
			if(i-coins[j]<0) continue;
			int u = d[i-coins[j]]+1;
			if(u<d[i])
			{
				d[i] = u;
				e[i] = coins[j];
			}
		}
	}
	
	while(x>0)
	{
		cout << e[x] <<" ";
		x -= e[x];
	}
	cout<<endl<<endl;;
}

int totalPossibleSolutions(vector<int> coins, int k, int x)
{
	int d[x+1];
	d[0] = 1;
	for(int i=1; i<x+1; i++) d[i] = 0;
	
	for(int i=1; i<=x; i++)
	{
		for(int j=0; j<k; j++)
		{
			if(i-coins[j]<0) continue;
			d[i] += d[i-coins[j]];
		}
	}
	return d[x];
}

int main()
{
	//cout<<min(1,3)<<endl;
	mem[0] = 0;
	
	int k;
	cin >> k;
	
	vector <int> coins(k);
	for(auto &x: coins) cin>>x;
	//~ int x = 1;
	//~ while(x>=0){cin>>x; loopMinSum(coins, k, x); }//cout<<"Result: "<<constructSolutions(coins, k, x)<<endl;};
	for(int i=0; i<=9; i++)
		cout<<i<<": "<<totalPossibleSolutions(coins, k, i)<<endl;
	return 0;
}
	
