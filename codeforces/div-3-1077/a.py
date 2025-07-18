import math 

for t in range(int(input())):
  a, b, k = list(map(int, input().strip().split(' ')))
  print((a*math.ceil(k/2))-(b*(k//2)))

