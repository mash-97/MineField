
for t in range(int(input())):
  m, n = list(map(lambda x: int(x), input().strip().split()))
  a = list(map(lambda x: int(x), input().strip().split()))
  b = list(map(lambda x: int(x), input().strip().split()))[0]

  # print(f"#>> {a} <| #{b}")
  a[0] = min(a[0], b-a[0])
  for indx in range(1, len(a)):
    if a[indx-1]<=(b-a[indx]):
      a[indx] = b-a[indx]
  
  # print(f"#>> {a}")
  count = 0
  for indx in range(1, len(a)):
    if a[indx-1]>a[indx]:
      count+=1
      break

  if count>0:
    print("no")
  else:
    print("yes")

