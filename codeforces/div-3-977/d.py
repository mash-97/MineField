def rearrangor(arr, res, arr_stats):
  if len(res)==len(arr):
    return res
  indx = 0
  while indx<len(arr_stats):
    if not arr_stats[indx]:
      arr_stats[indx] = True
      if res[-1]%3==0 and res[-1]//3==arr[indx]:
        res.append(arr[indx])
        r = rearrangor(arr, res, arr_stats)
        if r: 
          return r
        res.pop()
      elif res[-1]*2==arr[indx]:
        res.append(arr[indx])
        r = rearrangor(arr, res, arr_stats)
        if r:
          return r
        res.pop()
      arr_stats[indx] = False
    indx += 1
  return False


def bins(arr, li, ri, el):
  mid = li+(ri-li)//2
  if arr[mid]==el:
    return mid
  elif arr[mid]>el:
    return bins(arr, li, mid, el)
  return bins(arr, mid, ri, el)


if __name__=="__main__":
  n = int(input())
  a = list(map(int, input().strip().split(' ')))
  for i, e in enumerate(a):
    r = rearrangor(a, [e], [True if indx==i else False for indx in range(n)])
    if r:
      print(*r)
      break

