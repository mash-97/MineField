for t in range(int(input())):
  n = int(input())
  fskill_mins = -1
  sskill_mins = -1
  same_mins = -1
  for i in range(n):
    m, s = input().strip().split(' ')
    m = int(m)
    if s[0]=='1' and s[1]=='1' and (same_mins==-1 or same_mins>=m):
      same_mins = m
    elif s[0]=='1' and (fskill_mins==-1 or fskill_mins>=m):
      fskill_mins = m
    elif s[1]=='1' and (sskill_mins==-1 or sskill_mins>=m):
      sskill_mins = m
  

  if same_mins!=-1 and (fskill_mins==-1 or sskill_mins==-1 or fskill_mins+sskill_mins > same_mins):
    print(f"{same_mins}")
  elif fskill_mins!=-1 and sskill_mins!=-1:
    print(f"{fskill_mins+sskill_mins}")
  else:
    print(-1)
