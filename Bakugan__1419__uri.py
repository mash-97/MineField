
def first_3consecutive_position(bakugan_rounds, rounds):
  ffmpos = -1 
  p = None
  c = 0
  for i in range(rounds):
    if p != bakugan_rounds[i]:
      p = bakugan_rounds[i]
      ffmpos = i
      c = 1
    elif p==bakugan_rounds[i]:
      c += 1
      if c==3:
        return ffmpos
  return -1

def resp(mp, lp):
  if mp > lp:
    print("M")
  elif mp < lp:
    print("L")
  else:
    print("T")


if __name__ == '__main__':
  while True:
    rounds = int(input())
    if rounds==0:
      break
    
    mp = list(map(lambda x: int(x), input().split(' ')))
    lp = list(map(lambda x: int(x), input().split(' ')))
    
    ismp = sum(mp)
    islp = sum(lp)
  
    mpos = first_3consecutive_position(mp, rounds)
    lpos = first_3consecutive_position(lp, rounds)

    if (mpos==-1) and (lpos==-1):
      resp(ismp, islp)
    elif mpos != -1  and (mpos < lpos or lpos == -1):
      resp(ismp+30, islp)
    elif lpos != -1 and (lpos < mpos or mpos == -1):
      resp(ismp, islp+30)
    else:
      resp(ismp, islp)


  

