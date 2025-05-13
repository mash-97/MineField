def is_possible(sumk_dict):
  for k in sumk_dict.keys():
    if len(sumk_dict[k])>=2:
      _kys = list(sumk_dict[k].keys())[:2]
      return [
        [_kys[0], sumk_dict[k][_kys[0]]],
        [_kys[1], sumk_dict[k][_kys[1]]]
      ]
  return False

if __name__=="__main__":
  k = int(input())
  sumk_dict = dict()

  for indx in range(k):
    n = int(input())
    a = list(map(int, input().strip().split(' ')))
    sa = sum(a)
    for  i in range(n):
      if (sa-a[i]) not in sumk_dict:
        sumk_dict[sa-a[i]] = dict()
      sumk_dict[sa-a[i]][indx+1] = i+1

  res = is_possible(sumk_dict)
  if res!=False:
    print("YES")
    for r in res:
      print(*r)
  else:
    print("NO")

