for t in range(int(input())):
    n = int(input())
    l = lambda: list(map(int, input().strip().split(' ')))
    s = l()
    f = l()

    d = []
    latest_time = -1
    for indx in range(n):
        if latest_time<s[indx]:
            latest_time = s[indx]
        
        if latest_time > f[indx]:
            d.append(0)
        else:
            d.append(f[indx]-latest_time)
            latest_time = f[indx]
    
    print(*d)

