n = int(input())
a = list(map(int, input().strip().split(' ')))
sa = [[] for _ in range(10**6+1)]
for indx, e in enumerate(a):
  sa[e].append(indx+1)

ans_set = set()

s = sum(a)
for inx, e in enumerate(a):
  rs = s-e
  ex = rs-e
  if ex>0 and ex<(10**6+1) and len(sa[ex])>0:
    same_flag = False
    for x in sa[ex]:
      if inx+1!=x:
        ans_set.add(x)
      else:
        same_flag = x
    if same_flag:
      sa[ex]=[same_flag]
    else:
      sa[ex] = []
    

print(len(ans_set))
if len(ans_set):
  print(*ans_set)


