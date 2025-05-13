for t in range(int(input())):
  n, k = list(map(int, input().strip().split(' ')))
  a = sorted(list(map(int, input().strip().split(' '))))

  max_adjacent_count = 1
  indx = 0
  while indx<n-1:
    local_adjacent_count = 1
    while indx<n-1:
      indx += 1
      if not (a[indx]-a[indx-1]<=k):
        break
      local_adjacent_count += 1
      
    max_adjacent_count = max(max_adjacent_count, local_adjacent_count)
  print(n-max_adjacent_count)

