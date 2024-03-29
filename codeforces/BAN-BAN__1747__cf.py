
if __name__=='__main__':
  t = int(input())
  for _ in range(t):
    n = int(input())
    if n==1:
      print("1\n1 2")
    else:
      r = (n//2)+(n&1)
      print(r)
      x = None
      for i in range(0, (r-(n&1))):
        x = (i*6)+3
        print(f"{x} {x+1}")
      
      if n&1 == 1:
        print(f"{x+3} {x+5}")


