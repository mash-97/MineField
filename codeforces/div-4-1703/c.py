if __name__=="__main__":
  for t in range(int(input().strip())):
    n = int(input().strip())
    oseq = []
    fseq = list(int(i) for i in input().strip().split(' '))
    for i in range(n):
      bi, bs = input().strip().split(' ')
      bi = int(bi)
      if bi!=len(bs): raise ValueError("bi should match the length of bs")
      bs = sum(1 if c=='D' else -1 for c in bs)
      oseq.append((fseq[i]+bs)%10)
    print(' '.join(str(_) for _ in oseq))

