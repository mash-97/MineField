
if __name__=="__main__":
  for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().strip().split(' ')))
    mina = min(map(abs, a))
    negs = len(list(filter(lambda x: x<0, a)))

    maxsum = sum(map(abs, a))
    if negs&1==1:
      maxsum += (2*(-1)*mina)
    print(maxsum)

