for t in range(int(input())):
    n, k = list(map(int, input().strip().split(' ')))
    s = input().strip()
    o = 0
    for c in s:
        if c=='1':
            o += 1
    z = n-o
    ans = True
    po = o//2
    pz = z//2
    if po>=pz and po>=k:
        po -= k
        k = 0
    elif po>=pz:
        po = 0
        k -= po

    if pz >= k:
        pz -= k
        k = 0
    else:
        pz = 0
        k -= pz

    ro = (o&1)+po*2
    rz = (z&1)+pz*2
    if not ((ro==0 and rz==1)or(ro==1 and rz==0)) and not(ro==rz):
        ans = False
    if k!=0:
        ans = False

    if ans:
        print('yes')
    else:
        print('no')

