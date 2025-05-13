n = int(input())
a = list(map(int, input().strip().split(' ')))

astats = [-1 for _ in range(1001)]
for indx, e in enumerate(a):
  astats[e] = indx

indxs = [indx for indx in astats if indx!=-1]
indxs.sort()
ans = [a[indx] for indx in indxs]
print(len(ans))
print(*ans)

