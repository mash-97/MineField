

if __name__=="__main__":
  n, m = list(map(int, input().strip().split(' ')))
  a = list(map(int, input().strip().split(' ')))
  b = list(map(int, input().strip().split(' ')))
  
  f = 0
  k = 0

  bindx = 0
  preva = 0
  while bindx<m:
    ansf = f
    ansk = k
    x = b[bindx]-preva
    while x!=0:
      if a[f]-k==x:
        k = a[f]
        ansk = k
        x = 0
      elif a[f]-k>x:
        k += x
        ansk = k
        x = 0
      elif a[f]-k<x:
        x -= a[f]-k
        f += 1
        ansf = f
        k = 0
    preva = b[bindx]
    print(ansf+1, ansk)
    bindx += 1

