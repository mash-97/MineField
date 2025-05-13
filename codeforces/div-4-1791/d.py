def get_lowercase_stat(n, s):
  farr = [False for _ in range(26)]
  rarr = [False for _ in range(26)]
  fasr = [0 for _ in s]
  rasr = [0 for _ in s]
  farr[ord(s[0])-ord('a')] = True
  fasr[0] = 1
  rarr[ord(s[n-1])-ord('a')] = True
  rasr[n-1] = 1

  for indx in range(1, n-1):
    fasr[indx] = fasr[indx-1]
    if not farr[ord(s[indx])-ord('a')]:
      farr[ord(s[indx])-ord('a')] = True
      fasr[indx] += 1
    
    rasr[-(indx+1)] = rasr[-indx]
    if not rarr[ord(s[-(indx+1)])-ord('a')]:
      rarr[ord(s[-(indx+1)])-ord('a')] = True
      rasr[-(indx+1)] += 1
  return [fasr, rasr]

if __name__=='__main__':
  for t in range(int(input())):
    n = int(input())
    s = input().strip()
    
    fasr, rasr = get_lowercase_stat(n, s)

    maxi = -1
    for indx in range(0, n-1):
      if maxi < fasr[indx]+rasr[indx+1]:
        maxi = fasr[indx]+rasr[indx+1]
    print(maxi)

