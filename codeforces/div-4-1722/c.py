if __name__=='__main__':
  for t in range(int(input())):
    n = int(input())
    astrings = input().strip().split(' ')
    bstrings = input().strip().split(' ')
    cstrings = input().strip().split(' ')

    ass = set(astrings)
    bss = set(bstrings)
    css = set(cstrings)
    wss = ass.intersection(bss.intersection(css))
    ass = ass-wss
    bss = bss-wss
    css = css-wss
    
    ap = len(ass-(bss.union(css)))*3
    ap += len(ass.intersection(bss))
    ap += len(ass.intersection(css))
    
    bp = len(bss-(ass.union(css)))*3
    bp += len(bss.intersection(ass))
    bp += len(bss.intersection(css))

    cp = len(css-(ass.union(bss)))*3
    cp += len(css.intersection(ass))
    cp += len(css.intersection(bss))

    print(ap, bp, cp)

