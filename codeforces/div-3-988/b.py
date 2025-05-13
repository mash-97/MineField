def is_possible(strings):
  indx = 1
  while indx<len(strings):
    if strings[indx].find(strings[indx-1])<0:
      return False
    indx += 1
  return True


if __name__=='__main__':
  n = int(input())
  strings = []
  [strings.append(input().strip()) for _ in range(n)]
  for indx in range(n):
    strings[indx] = [len(strings[indx]), strings[indx]]

  strings.sort()
  strings = list(map(lambda x: x[1], strings))
  if is_possible(strings):
    print("YES")
    print("\n".join(strings))
  else:
    print("NO")


