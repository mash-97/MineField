if __name__=='__main__':
  for t in range(int(input())):
    hh, mm = input().strip().split(':')
    hh = int(hh)
    ap = ['AM', 'PM'][hh//12]
    hh = str(hh%12)
    if int(hh)==0:
      hh = '12'
    hh = ['', '0', ''][len(hh)]+hh
    print(':'.join([hh, mm]), ap)

    
