h1, m1 = list(map(int, input().strip().split(':')))
h2, m2 = list(map(int, input().strip().split(':')))

h, m = -1, -1
if h1==h2:
    dm = m2-m1
    h = (h1+h2)//2
    m = m1+dm//2
else:
    tm = 0
    tm += 60-m1
    if h2!=0:
        tm += (h2-(h1+1))*60
    else:
        tm += (24-(h1+1))*60
    tm += m2
    tm //= 2
    h1 += tm//60
    tm = m1+tm%60
    
    h1 += tm//60
    h = h1
    m = tm%60

if h==24:
    h = 0
h = str(h)
m = str(m)
if len(h)==1: 
    h = '0'+h
if len(m)==1:
    m = '0'+m


print(f"{h}:{m}")


