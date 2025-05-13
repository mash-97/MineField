for t in range(int(input())):
  s = list(map(int, input().strip()))
  s.sort(reverse=True)
  ans = list(set(s))
  ans.reverse()
  [s.remove(e) for e in ans]
  s.sort()
  [ans.append(e) for e in s]
  print(''.join(map(str, ans)))


