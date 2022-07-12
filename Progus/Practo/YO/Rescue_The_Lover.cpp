#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

#define cpos pair<int, int>
#define lpos pair<int, int>
#define MAX_SIZE 100

int island[MAX_SIZE][MAX_SIZE];
int minimum_energy;
int n;

map< cpos, lpos> caves;
int visited_mark;
pair<int, int> max_en;

vector<pair<int, int>> possibleMoves(int mx, int my)
{
	vector< pair<int,int>> possible_moves;
	
	if(mx+1 <= n  && my+1 <=n && island[mx+1][my+1] != visited_mark) 
		possible_moves.push_back({mx+1, my+1});
		
	if(mx+1 <= n  && my-1 >=1 && island[mx+1][my-1] != visited_mark)
		possible_moves.push_back({mx+1, my-1});
		
	if(my+1 <= n && island[mx][my+1] != visited_mark)
		possible_moves.push_back({mx, my+1});
		
	if(my-1 >= 1 && island[mx][my-1] != visited_mark)
		possible_moves.push_back({mx, my-1});
		
	if(mx-1 >=1 && my+1 <= n &&  island[mx-1][my+1] != visited_mark)
		possible_moves.push_back({mx-1, my+1});
	
	if(mx-1 >=1 && my-1 >=1 && island[mx-1][my-1] != visited_mark)
		possible_moves.push_back({mx-1, my-1});
	
	if(mx-1 >=1 && island[mx-1][my] != visited_mark)
		possible_moves.push_back({mx-1, my});
	
	if(mx+1 <=n && island[mx+1][my] != visited_mark)
		possible_moves.push_back({mx+1, my});

	return possible_moves;
}
	
	

pair<int, int> minimumEnergies(int mx, int my, int me, int lx, int ly, int le)
{
	if(me<=0 || le<=0) return {visited_mark, visited_mark};
		
	me += island[mx][my];
	le -= 1;
	island[mx][my] = visited_mark;
	
	if(mx==lx && my==ly)
	{
		if(max_en.first <= me && le>0)
		{
			me = max_en.first;
			le = max_en.second;
		}
		return {me, le};
	}
	
	vector< pair<int, int>> poss_moves = possibleMoves(mx, my);
	pair<int, int> result;
	pair<int, int> max = {visited_mark, visited_mark};
	
	if(caves[{mx, my}].first!=false || caves[{mx,my}].second!=false) 
		poss_moves.push_back(caves[{mx,my}]);
	
	if(poss_moves.size()==0) return {me, le};
	for(int i=0; i<(int)poss_moves.size(); i++)
	{
		result = minimumEnergies(poss_moves[i].first, poss_moves[i].second, me, lx, ly, le);
		if(result.first!=visited_mark && result.second!=visited_mark)
		{
			if(result.first > max.first)
			{
				max.first = result.first;
				max.second = result.second;
			}
		}
	}
	if(max.first >= max_en.first)
		max_en = max;
		
	return max_en;
}
		
	

int main()
{
	int lx, ly, le;
	int mx, my, me;
	
	visited_mark = -(int) __builtin_inf();
	max_en = {-(int)__builtin_inf(), -(int)__builtin_inf()};
	
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			island[i][j] = 0;
	mx = 1;
	my = 1;
	scanf("%d", &me);
	scanf("%d %d %d", &lx, &ly, &le);
	printf("lx: %d, ly: %d, le: %d\n", lx, ly, le);
	int m;
	scanf("%d", &m);
	char c;
	int x,y,e = 5;
	for(int i=1; i<=m; i++)
	{
		scanf(" %c %d %d", &c, &x, &y);
		if(c=='E' || c=='T')
			(c=='T') ? (island[x][y] = -e) : (island[x][y] = e);

		else if(c=='K')
		{
			scanf("%d", &e);
			island[x][y] = -e;
		}
		else 
		{
			scanf("%d %d", &lx, &ly);
			caves[{x, y}] = {lx, ly};
			island[x][y] = -e;
		} 
	}
	
	
	pair<int,int> r = minimumEnergies(mx, my, me, lx, ly, le);
	
	if(r.first==visited_mark || r.second==visited_mark)
		printf("No solution!\n");
	else
		printf("%d %d\n", r.first, r.second);
	puts("");
	return 0;
}
