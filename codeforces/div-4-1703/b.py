import os

__DEBUG__ = os.environ.get('DEBUG', False)

def using_ancient(n, s):
  ballons_count = 0
  chars_ref = list(False for _ in range(26))
  for c in s:
    if not chars_ref[ord(c)-ord('A')]:
      ballons_count += 2
      chars_ref[ord(c)-ord('A')] = True
    else:
      ballons_count += 1
  return ballons_count

def using_v1(n, s):
  ballons_count = len(set(s))*2
  ballons_count += (n-len(set(s)))
  return ballons_count


def using_v2(n, s):
  chars_dict = dict()
  for c in s:
    if c in chars_dict:
      chars_dict[c]+=1
    else:
      chars_dict[c]=2
  return sum(chars_dict.values())


if __name__=='__main__':
  for t in range(int(input().strip())):
    n = int(input().strip())
    s = list(input().strip())
    if __DEBUG__: 
      from timeit import timeit
      ua = using_ancient(n, s)
      uv1 = using_v1(n, s)
      uv2 = using_v2(n, s)

      tua = timeit(lambda: using_ancient(n, s), number=1000)
      tuv1 = timeit(lambda: using_v1(n, s), number=1000)
      tuv2 = timeit(lambda: using_v2(n, s), number=1000)



      print(f"using ancient: {using_ancient(n, s)} -- {round(tua, 6)}s") 
      print(f"using v1: {using_v1(n, s)} -- {round(tuv1, 6)}s")
      print(f"using v2: {using_v2(n, s)} -- {round(tuv2, 6)}s")
      if ua==uv1 and uv1==uv2:
        print(f"#> same result!")
      else:
        print(f"#> !! not same result !!")


    print(using_v1(n, s))

    
