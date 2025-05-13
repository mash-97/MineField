for t in range(int(input())):
  n = int(input())
  perm = [None for _ in range(2*n+1)]
  flags = [False for _ in range(2*n+1)]

  for i in range(1, n+1):
      nums = list(map(int, input().strip().split(' ')))
      for j, num in enumerate(nums):
        j += 1
        perm[i+j] = num
        flags[num] = True

  for i, _ in enumerate(flags[1:]):
    i += 1
    if not _:
      perm[1] = i
      break
  print(*perm[1:])

