import sys
print(sys.argv)
def greedy_blocks(blocks, wished_length):
    bs = sorted(blocks, reverse=True)
    count = 0
    for b in bs:
        if b <= wished_length:
            count += wished_length//b
            wished_length %= b
        # while(b<=wished_length):
        #    wished_length -= b
        #    count += 1
         
    return count
    
    
def main():
    T = int(input())
    for t in range(T):
        N, M = list(map(int, input().split(' ')))
        blocks = list(map(int, input().split(' ')))
        print(greedy_blocks(blocks, M))


if __name__=='__main__':
    main()
