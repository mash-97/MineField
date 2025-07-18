for q in range(int(input())):
    n, a, b = list(map(int, input().strip().split(' ')))
    ttam = (n//2)*b
    if n%2!=0:
        ttam += (n-((n//2)*2))*a
    if ttam <= n*a:
        print(ttam)
    else:
        print(n*a)

