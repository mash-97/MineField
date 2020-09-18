
def get_least_prime_factors(n):
	# mark[i]: False means i is prime
	# initially all i is prime
	mark = [False for x in range(0, n+1)]
	
	# lpfm => least prime factor mapper
	# lpfm[i] will give the corresponding least prime factor for i 
	# initially all lpfms are None
	lpfm = [None for x in range(0, n+1)]
	
	# mark 1,0 as True, cause they aren't prime
	mark[0] = mark[1] = True
	
	# also their corresponding lpfms are themselves
	lpfm[0] = 0
	lpfm[1] = 1
	
	# 2 is prime so mark[2] should be False
	# all even numbers are non-prime
	# and their corresponding lpfm is also 2
	mark[2] = False
	lpfm[2] = 2
	
	# only take even numbers except 2
	for num in range(4, n+1, 2):
		mark[num] = True 
		lpfm[num] = 2
	
	# we have to keep in mind that any prime number's corresponding 
	# lpfm is himself
	
	# we have to process only odd numbers for performance optimization
	for num in range(3, n+1, 2):
		# process if it is prime, means only if mark[num] is False
		if mark[num]==False:
			# any prime number's corresponding lpfm is himself
			lpfm[num] = num
			
			# process if num is below or equal to sqrt(n) : (num*num) <= n
			# because after sqrt(n) is already checked-in for prime checking
			if num*num <= n:
				# only check odd numbers
				i = num*num
				while i<=n:
					# mark[i] as True, cause it's not prime
					mark[i] = True
					
					# set i's corresponding lpfm is num
					if lpfm[i]==None:
						lpfm[i] = num 
					
					# next i should be odd
					i += num*2
	
	# return lpfm
	return lpfm



if __name__== '__main__':
	
	t = int(input())
	for i in range(t):
		# get a number for printing least prime factor between 1 to number
		number = int(input())
		result = " ".join([str(x) for x in get_least_prime_factors(number)[1:number+1]])
		print(result)
	

