for t in range(int(input())):
  n = int(input())
  maxi = maxb = -1
  for indx in range(1, n+1):
    a, b = list(map(int, input().strip().split(' ')))
    if a<=10 and b>=maxb:
      maxb = b
      maxi = indx
  print(maxi)

