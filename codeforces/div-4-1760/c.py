for t in range(int(input())):
  n = int(input())
  s = list(map(int, input().strip().split(' ')))
  maxe = max(s)
  maxe_indx = s.index(maxe)
  s[maxe_indx] = -1
  maxe2 = max(s)
  s = list(map(lambda x: x-maxe, s))
  s[maxe_indx] = maxe-maxe2
  print(*s)
