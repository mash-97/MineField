for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().strip().split(' ')))
    count = 1
    indx = 1
    prev = a[0]
    while indx<n:
        indx += 1
        if not(prev+1<a[indx-1]):
            continue
        prev = a[indx-1]
        count += 1
    print(count)

