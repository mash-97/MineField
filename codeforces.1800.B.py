if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, k = list(map(lambda x: int(x), input().strip().split(' ')))
        s = input().strip()
        lchars = [0 for _ in range(26)]
        uchars = [0 for _ in range(26)]
        for c in s:
            if(c>='a' and c<='z'):
                lchars[ord(c)-ord('a')] += 1
            if(c>='A' and c<='Z'):
                uchars[ord(c)-ord('A')] += 1
        
        pair_count = 0
        for oc in range(26):
            m = min(lchars[oc], uchars[oc])
            lchars[oc] -= m
            uchars[oc] -= m
            pair_count += m

            ik = k
            k -= min(lchars[oc]//2, k)
            k -= min(uchars[oc]//2, k)
            pair_count += ik-k

        print(pair_count)

