n = int(input())
a = list(map(int, input().strip().split(' ')))

x = [0 for _ in range(101)]
for e in a:
  x[e]+=1
print(max(x))

