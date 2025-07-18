for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().strip().split(' ')))
    b = list(map(int, input().strip().split(' ')))
    max_diff = -1
    for indx in range(n):
        diff = a[indx]-b[indx]
        if diff>max_diff:
            max_diff = diff

    ans = True
    for indx in range(n):
        diff = a[indx]-b[indx]
        if diff<0:
            ans = False
            break
        if diff<max_diff and b[indx]!=0:
            ans = False
            break
    if ans:
        print('yes')
    else:
        print('no')
