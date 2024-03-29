#! /bin/python3
from memory_profiler import profile
import sys 
import time 

iss = time.time()
DYN_ARRAY = [None for i in range(10**6+1)]
ess = time.time()
print(ess-iss)
HIGH = 10**9
BLOCKS = []


def dyn_wrapper(wished_length):
    global DYN_ARRAY
    DYN_ARRAY[0] = 0
    for i in range(wished_length+1):
        DYN_ARRAY[i] = None
    for i in range(min([max(BLOCKS), wished_length])+1):
        DYN_ARRAY[i] = dyn_blocks(i)
    return dyn_blocks(wished_length)
    

def dyn_blocks(wished_length, count=0):
    global DYN_ARRAY
    if wished_length==0:
        return count
    if wished_length<0:
        return HIGH
    if DYN_ARRAY[wished_length]:
        return DYN_ARRAY[wished_length]+count
    minimum_count = HIGH
    for b in BLOCKS:
        if b<=wished_length:
            if len(sys.argv)>1 and sys.argv[1]=='1': 
                lcount = dyn_blocks(wished_length-b, count+1)
            else:
                lcount = dyn_blocks(wished_length%b, count+(wished_length//b))
            if lcount<minimum_count:
                minimum_count = lcount
    DYN_ARRAY[wished_length] = minimum_count
    return minimum_count

def main():
    global BLOCKS
    T = int(input())
    for t in range(T):
        N, M = list(map(int, input().split(' ')))
        BLOCKS = list(map(int, input().split(' ')))
        print(dyn_wrapper(M))


if __name__=='__main__':
    main()
