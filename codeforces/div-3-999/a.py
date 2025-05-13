n, k = list(map(int, input().strip().split(' ')))
a = list(map(int, input().strip().split(' ')))

i = 0
j = n-1

while (i<n and a[i]<=k) or (j>=0 and a[j]<=k):
  if a[i]<=k:
    i += 1
  if a[j]<=k:
    j -= 1

if i==n and j==-1:
  print(n)

elif (i<n and j>=0) and (i==j):
  print(n-1)

else:
  print(n-((j-i)+1))


