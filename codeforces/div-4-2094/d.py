for t in range(int(input())):
  p = list(input().strip())
  s = list(input().strip())
  
  yes = True
  pcurr_char = p[0]
  scurr_char = s[0]
  p_count = s_count = 0
  pindx = 0
  sindx = 0
  while pindx<len(p):
    if pcurr_char!=scurr_char:
      yes = False
      break
    
    while pindx<len(p):
      if pcurr_char==p[pindx]:
        p_count += 1
        pindx += 1
        continue
      pcurr_char = p[pindx]
      break

    while sindx<len(s):
      if scurr_char==s[sindx]:
        s_count += 1
        sindx += 1
        continue
      scurr_char = s[sindx]
      break
    if not(s_count>=p_count and s_count<=2*p_count):
      yes = False 
      break
    p_count = s_count = 0

  if yes and sindx==len(s):
    print('YES')
  else:
    print('NO')


    

