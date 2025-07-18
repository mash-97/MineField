for t in range(int(input())):
    n = int(input())
    h1 = h2 = h3 = n//3
    r = n%3
    h2 += r+1
    h3 -= 1

    d = ((h2-h1)//2)+1
    h2 -= d
    h1 += d
    print(*[h2,h1,h3])


