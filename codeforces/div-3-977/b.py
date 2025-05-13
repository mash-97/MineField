n = int(input())
s = input().strip()

two_grams = dict()
indx = 0
while indx<n-1:
  tg = s[indx:indx+2]
  if tg in two_grams:
    two_grams[tg] += 1
  else:
    two_grams[tg] = 1
  indx += 1

max_tg = None
max_tgv = -1
for tg in two_grams:
  if max_tgv<two_grams[tg]:
    max_tgv = two_grams[tg]
    max_tg = tg

print(max_tg)

