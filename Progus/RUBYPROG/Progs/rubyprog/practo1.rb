
def isPrime(aNumber)
	if(aNumber == 0 || aNumber == 1 || aNumber < 0)
		return 0
	
	elsif (aNumber == 2)
		return 1
	else
		i = 3
		while(i < Math.sqrt(aNumber))
			if(aNumber % i == 0)
				return 0
			end
			i += 2
		end
	end
	return 1
end

aNumber = 1
i = 0
arrayOfPrime = []
arrayOfPrime[i] = 2
until aNumber == 9999
	print("Enter your number to check whether the number is prime or not:: ",aNumber)
	if(isPrime(aNumber)==1)
		i += 1
		arrayOfPrime[i] = aNumber
		puts("The number #{arrayOfPrime[i]} is prime.")
		
	else
		puts("The number #{aNumber} isn't prime.")
	end
	aNumber += 2
end

puts("+++++++++++++++++++")
puts arrayOfPrime
gets