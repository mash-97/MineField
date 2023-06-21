# range sum query
def rsq(indx, a, b, l, r, bt):
  if((a==l and b==r) or (a==l and a==b and b==r)):
    return bt[indx];
  
  h = l+(r-l)//2
  print(f"indx: {indx}, a: {a}, b: {b}, l: {l}, r: {r}, h: {h}")
  if(b<=h): return rsq(indx*2, a, b, l, h, bt);
  if(a>h): return rsq(indx*2+1, a, b, h+1, r, bt);
  
  return rsq(indx*2, a, h, l, h, bt) + rsq(indx*2+1, h+1, b, h+1, r, bt)


# update value in the tree 'bt'
def uv(indx, v, bt):
  indx += len(bt)//2
  vv = v - bt[indx] #// 4-3=1 // 3-4=-1
  bt[indx] = v
  
  while(indx>1):
    print(f"indx: {indx}")
    bt[indx//2] += vv
    indx //= 2

# build segment tree
# with given numbers
def bstree(numbers):
  ls = 1
  while(ls<len(numbers)):
    ls *= 2
  s = ls*2
  bt = [0 for _ in range(s)]
  
  indx = s//2
  while((indx-s//2)<len(numbers)):
    bt[indx] = numbers[indx-s//2]
    bt[indx//2] += bt[indx]
    indx += 1
  
  indx = s//2-1
  while(indx>1):
    bt[indx//2]+= bt[indx]
    indx -= 1
  return bt

if __name__=='__main__':
  numbers = list(map(lambda x: int(x), input("enter numbers: ").strip().split()))
  print(numbers)
  bt = bstree(numbers)
  print(f"bt: {bt}")
   
  op = input("enter operation u(update), rsq(range sum query): ").strip()
  if(op=="u"):
    t = int(input("enter number of updates: "))
    while(t>0):
      indx,v = list(map(lambda x: int(x), input("> ").strip().split()))
      uv(indx, v, bt)
      t -= 1
    print(f"after updates bt: {bt}")
  
  elif(op=="rsq"):
    t = int(input("enter number of queries: "))
    while(t>0):
      a, b = list(map(lambda x: int(x), input("> ").strip().split()))
      rs = rsq(1, a, b, 1, len(bt)//2, bt)
      print(f"for a: {a}, b: {b} => rs: {rs}")
      t -= 1



