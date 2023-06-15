if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = list(map(lambda x: int(x), input().strip().split(' ')))

        total_power = 0
        bonus_deck = []

        for ix, si in enumerate(s):
            if si==0 and len(bonus_deck)!=0:
                total_power += bonus_deck.pop()
            else:
                if(n-ix-1 < len(bonus_deck)):
                    bonus_deck = bonus_deck[len(bonus_deck) - (n-ix-1):]
                indx = len(bonus_deck)
                while(indx>0 and bonus_deck[indx-1]>si):
                    indx -= 1
                bonus_deck.insert(indx, si)

        print(total_power)

