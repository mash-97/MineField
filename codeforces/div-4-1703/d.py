"""Assumptions

  * All string characters are lowercase english letters.
"""

"""Method
  step 1. find all the starting matched strings, and their associated 
    remain base string.
  step 2. check for the remain base string.
"""

def char_refs_strings(strings):
  chars = list([] for _ in range(26))
  (chars[ord(s[0])-ord('a')].append(s) for s in strings) 
  return chars

def len_ref_strings(strings):
  lens = {}
  for s in strings:
    l = len(s)
    if l in lens:
      lens[l].append(s)
    else:
      lens[l] = [s]
  return lens

def start_matched_strings(astring, char_refs, empt=False):
  matched_strings = []
  for mstring in char_refs[ord(astring[0])-ord('a')]:
    if len(astring) >= len(mstring) and astring[0:len(mstring)]==mstring:
      if not empt  and astring[len(mstring):]!='':
        matched_strings.append((mstring, astring[len(mstring):])) 

  return matched_strings


def sol_exist_for_string(astring, char_refs):
  fm_strings = start_matched_strings(astring, char_refs)
  for fm in fm_strings:
    fs = fm[0]
    rs = fm[1]
    if rs=='' or char_refs[ord(rs[0])-ord('a')]==[]: continue
    if len(start_matched_strings)==0:
      return '1'
  return '0'


if __name__=='__main__':
  for t in range(int(input().strip())):
    n = int(input())
    strings = (input().strip() for _ in range(n))
    c_refs = char_refs_strings(strings)
    bins = list(sol_exist_for_string(string, c_refs) for string in strings)
    print(''.join(bins))

