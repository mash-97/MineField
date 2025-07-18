for q in range(int(input())):
    n = int(input())
    candies = list(map(int, input().strip().split(' ')))
    print(f"####> for query:{q+1}")
    if n<3:
        print(0)
    else:
        presum = [*candies[:2]]
        for i in range(2, n):
            presum.append(presum[-2]+candies[i])
        
        print(f"-> cands : {candies}")
        print(f"-> presum: {presum}")
        count = 0
        for i in range(1, n+1):
            
            # find last odd and even index
            last_even_indx = -1
            last_odd_indx = -1
            
            if (n&1!=1):
                last_odd_indx = n
                if last_odd_indx==i:
                    last_odd_indx -= 1
                last_even_indx = last_odd_indx-1
                if last_even_indx==i:
                    last_even_indx -= 1
            else:
                last_even_indx = n
                if last_even_indx==i:
                    last_even_indx -= 1
                last_odd_indx = last_even_indx-1
                if last_odd_indx==i:
                    last_odd_indx -= 1
           
            
            even_sum = 0
            odd_sum = 0
            if (last_even_indx&1==i&1) and i<last_even_indx:
                even_sum = presum[last_even_indx-1]-presum[i-1]
                if i>1:
                    even_sum += presum[i-1-1]
            else:
                even_sum = presum[last_even_indx-1]

            if (last_odd_indx&1==i&1) and i<last_odd_indx:
                odd_sum = presum[last_odd_indx-1]-presum[i-1]
                if i>1:
                    odd_sum += presum[i-1-1]
            else:
                odd_sum = presum[last_odd_indx-1]
           
            print(f"-> for element: {candies[i-1]}:{i}")
            print(f"-> last_even_indx: {last_even_indx}, last_odd_indx: {last_odd_indx}")
            print(f"-> even_sum: {even_sum}, odd_sum: {odd_sum}")

            if odd_sum==even_sum:
                count += 1
                print(f"-> ***** {candies[i-1]} at {i} is counted! ******")
        
        print(count)

