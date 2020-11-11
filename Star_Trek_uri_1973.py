# Star_Trek_uri_1973.py

n = int(input())
x = [int(sheeps) for sheeps in input().strip().split()]


visited = [False for x in range(0,n)]
initial_sheeps = sum(x)

indx = 0
stolen_sheeps = 0

while 0<=indx<n:
	curr_indx = indx
	visited[curr_indx] = True
	
	indx += 1 if x[curr_indx]%2!=0 else -1
	
	if x[curr_indx]>0:
		x[curr_indx] -= 1
		stolen_sheeps += 1

print("{} {}".format(visited.count(True), initial_sheeps-stolen_sheeps))
