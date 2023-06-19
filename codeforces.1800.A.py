import re

t = int(input())
for _ in range(t):
    n = int(input())
    meow = input().strip().lower()
    if(re.match("^m+e+o+w+$", meow)):
        print("YES")
    else:
        print("NO")

