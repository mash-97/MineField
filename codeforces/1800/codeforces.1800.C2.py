import queue
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = list(map(lambda x: int(x), input().strip().split(' ')))

        total_power = 0
        bonus_deck = queue.PriorityQueue()

        for ix, si in enumerate(s):
            if si==0 and not bonus_deck.empty():
                total_power += (-bonus_deck.get())
            elif si!=0:
                bonus_deck.put(-si)    
        print(total_power)

