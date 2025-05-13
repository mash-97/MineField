
for t in range(int(input())):
  n = int(input())
  nums = list(map(int, input().strip().split(' ')))
  groups_count = 0
  for i in range(0,31):
    one_count = 0
    for num in nums:
      if ((num>>i)&1)==1:
        one_count += 1
    groups_count = max(groups_count, max(one_count, n-one_count))
  print(groups_count)

